/**
 * On/Off Switch Node - behaviour predominantly based on the Bluetooth mesh Generic OnOff Client Model
 * 
 * Coded for and tested with nRF52840 DK board
 * 
 **/

#include <drivers/gpio.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/mesh.h>
#include <settings/settings.h>
#include <bluetooth/mesh/proxy.h>
#include <random/rand32.h>

// GPIO for the buttons - see zephyr samples/button for origin of some of this code
// Get button configuration from the devicetree sw0 alias. This is mandatory.

// Button 1
#define SW0_NODE	DT_ALIAS(sw0)
#if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios,
							      {0});
static struct gpio_callback gpio_btn1_cb;

#ifndef SW0_GPIO_FLAGS
#ifdef SW0_GPIO_PIN_PUD
#define SW0_GPIO_FLAGS SW0_GPIO_PIN_PUD
#else
#define SW0_GPIO_FLAGS 0
#endif
#endif

// Button 2
#define SW1_NODE	DT_ALIAS(sw1)
#if !DT_NODE_HAS_STATUS(SW1_NODE, okay)
#error "Unsupported board: sw1 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button2 = GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios,
							      {0});
static struct gpio_callback gpio_btn2_cb;

#ifndef SW1_GPIO_FLAGS
#ifdef SW1_GPIO_PIN_PUD
#define SW1_GPIO_FLAGS SW1_GPIO_PIN_PUD
#else
#define SW1_GPIO_FLAGS 0
#endif
#endif

// Button 3
#define SW2_NODE	DT_ALIAS(sw2)
#if !DT_NODE_HAS_STATUS(SW2_NODE, okay)
#error "Unsupported board: sw2 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button3 = GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios,
							      {0});
static struct gpio_callback gpio_btn3_cb;

#ifndef SW2_GPIO_FLAGS
#ifdef SW2_GPIO_PIN_PUD
#define SW2_GPIO_FLAGS SW2_GPIO_PIN_PUD
#else
#define SW2_GPIO_FLAGS 0
#endif
#endif

// Button 4
#define SW3_NODE	DT_ALIAS(sw3)
#if !DT_NODE_HAS_STATUS(SW3_NODE, okay)
#error "Unsupported board: sw3 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button4 = GPIO_DT_SPEC_GET_OR(SW3_NODE, gpios,
							      {0});
static struct gpio_callback gpio_btn4_cb;

#ifndef SW3_GPIO_FLAGS
#ifdef SW3_GPIO_PIN_PUD
#define SW3_GPIO_FLAGS SW3_GPIO_PIN_PUD
#else
#define SW3_GPIO_FLAGS 0
#endif
#endif


#define BUTTON_DEBOUNCE_DELAY_MS 250

static uint32_t btn_time[4] = { 0,0,0,0};
static uint32_t btn_last_time[4] = { 0,0,0,0};

static struct gpio_callback gpio_btn1_cb;
static struct gpio_callback gpio_btn2_cb;
static struct gpio_callback gpio_btn3_cb;
static struct gpio_callback gpio_btn4_cb;

// GPIO for LED 0
/*
 * The led0 devicetree alias is optional. If present, we'll use it
 * to turn on the LED whenever the button is pressed.
 */
static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios,
						     {0});

// for use with k_work_submit which we use to handle button presses in a background thread to avoid holding onto an IRQ for too long
static struct k_work button1_work;
static struct k_work button2_work;
static struct k_work button3_work;
static struct k_work button4_work;

static uint8_t dev_uuid[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00 };

static uint8_t onoff_tid;
static uint8_t hsl_tid;

void gen_uuid() {
    uint32_t rnd1 = sys_rand32_get();
    uint32_t rnd2 = sys_rand32_get();
    uint32_t rnd3 = sys_rand32_get();
    uint32_t rnd4 = sys_rand32_get();

    dev_uuid[15] = (rnd1 >> 24) & 0x0FF;
    dev_uuid[14] = (rnd1 >> 16) & 0x0FF;
    dev_uuid[13] = (rnd1 >>  8) & 0x0FF;
    dev_uuid[12] =  rnd1 & 0x0FF;

    dev_uuid[11] = (rnd2 >> 24) & 0x0FF;
    dev_uuid[10] = (rnd2 >> 16) & 0x0FF;
    dev_uuid[9] = (rnd2 >>  8) & 0x0FF;
    dev_uuid[8] =  rnd2 & 0x0FF;

    dev_uuid[7] = (rnd3 >> 24) & 0x0FF;
    dev_uuid[6] = (rnd3 >> 16) & 0x0FF;
    dev_uuid[5] = (rnd3 >>  8) & 0x0FF;
    dev_uuid[4] =  rnd3 & 0x0FF;

    dev_uuid[3] = (rnd4 >> 24) & 0x0FF;
    dev_uuid[2] = (rnd4 >> 16) & 0x0FF;
    dev_uuid[1] = (rnd4 >>  8) & 0x0FF;
    dev_uuid[0] =  rnd4 & 0x0FF;

    /* Set 4 MSB bits of time_hi_and_version field */
    dev_uuid[6] &= 0x0f;
    dev_uuid[6] |= 4 << 4;

    /* Set 2 MSB of clock_seq_hi_and_reserved to 10 */
    dev_uuid[8] &= 0x3f;
    dev_uuid[8] |= 0x80;

}

void ledOn(void) {
	gpio_pin_set(led.port, led.pin, 1);
}

void ledOff(void) {
	gpio_pin_set(led.port, led.pin, 0);
}

static void attention_on(struct bt_mesh_model *model)
{
	printk("attention_on()\n");
	ledOn();
}

static void attention_off(struct bt_mesh_model *model)
{
	printk("attention_off()\n");
	ledOff();
}

static const struct bt_mesh_health_srv_cb health_srv_cb = {
	.attn_on = attention_on,
	.attn_off = attention_off,
};

static int provisioning_output_pin(bt_mesh_output_action_t action, uint32_t number) {
	printk("OOB Number: %04d\n", number);
	return 0;
}

static void provisioning_complete(uint16_t net_idx, uint16_t addr) {
    printk("Provisioning completed\n");
}

static void provisioning_reset(void)
{
	bt_mesh_prov_enable(BT_MESH_PROV_ADV | BT_MESH_PROV_GATT);
}

// provisioning properties and capabilities
static const struct bt_mesh_prov prov = {
	.uuid = dev_uuid,
	.output_size = 4,
	.output_actions = BT_MESH_DISPLAY_NUMBER,
	.output_number = provisioning_output_pin,
	.complete = provisioning_complete,
	.reset = provisioning_reset,
};

// -------------------------------------------------------------------------------------------------------
// Health Server
// -------------
BT_MESH_HEALTH_PUB_DEFINE(health_pub, 0);
static struct bt_mesh_health_srv health_srv = {
	.cb = &health_srv_cb,
};

// -------------------------------------------------------------------------------------------------------
// Generic OnOff Client Model
// --------------------------

uint8_t onoff[] = {
	0,
	1};

// handler functions for this model's RX messages

static void generic_onoff_status(struct bt_mesh_model *model,struct bt_mesh_msg_ctx *ctx,struct net_buf_simple *buf)
{
	uint8_t onoff_state = net_buf_simple_pull_u8(buf);
	printk("generic_onoff_status onoff=%d\n",onoff_state);   
}

// generic on off client - message types defined by this model

#define BT_MESH_MODEL_OP_GENERIC_ONOFF_GET	      BT_MESH_MODEL_OP_2(0x82, 0x01)
#define BT_MESH_MODEL_OP_GENERIC_ONOFF_SET	      BT_MESH_MODEL_OP_2(0x82, 0x02)
#define BT_MESH_MODEL_OP_GENERIC_ONOFF_SET_UNACK  BT_MESH_MODEL_OP_2(0x82, 0x03)
#define BT_MESH_MODEL_OP_GENERIC_ONOFF_STATUS     BT_MESH_MODEL_OP_2(0x82, 0x04)

static const struct bt_mesh_model_op gen_onoff_cli_op[] = {
		{BT_MESH_MODEL_OP_GENERIC_ONOFF_STATUS, 1, generic_onoff_status},
		BT_MESH_MODEL_OP_END,
};

// -------------------------------------------------------------------------------------------------------
// Light HSL Client Model
// ----------------------

/*
BLACK   : HSL(    0,    0,    0) = RGB(0,0,0)

RED     : HSL(    0,65535,32767) = RGB(255,0,0)

GREEN   : HSL(21845,65535,32767) = RGB(0,255,0)

BLUE    : HSL(43690,65535,32767) = RGB(0,0,255)

YELLOW  : HSL(10922,65535,32767) = RGB(255,255,0)

MAGENTA : HSL(54613,65535,32767) = RGB(255,0,255)

CYAN    : HSL(32768,65535,32767) = RGB(0,255,255)

WHITE   : HSL(    0,    0,65535) = RGB(255,255,255)
*/

#define NUMBER_OF_COLOURS 8

uint16_t hsl[NUMBER_OF_COLOURS][3] = {
	{ 0x0000, 0x0000, 0x0000 }, // black
	{ 0x0000, 0xFFFF, 0x7FFF }, // red 
	{ 0x5555, 0xFFFF, 0x7FFF }, // green
	{ 0xAAAA, 0xFFFF, 0x7FFF }, // blue
	{ 0x2AAA, 0xFFFF, 0x7FFF }, // yellow
	{ 0xD555, 0xFFFF, 0x7FFF }, // magenta
	{ 0x7FFF, 0xFFFF, 0x7FFF }, // cyan
	{ 0x0000, 0x0000, 0xFFFF }  // white
};

uint8_t current_hsl_inx = 1;

// message types defined by this model.
#define BT_MESH_MODEL_OP_LIGHT_HSL_SET_UNACK	BT_MESH_MODEL_OP_2(0x82, 0x77)

// -------------------------------------------------------------------------------------------------------
// Composition
// -----------

BT_MESH_MODEL_PUB_DEFINE(gen_onoff_cli, NULL, 2);
BT_MESH_MODEL_PUB_DEFINE(light_hsl_cli, NULL, 2);

static struct bt_mesh_model sig_models[] = {
				BT_MESH_MODEL_CFG_SRV,
				BT_MESH_MODEL_HEALTH_SRV(&health_srv, &health_pub),
				BT_MESH_MODEL(BT_MESH_MODEL_ID_GEN_ONOFF_CLI, gen_onoff_cli_op, &gen_onoff_cli, &onoff[0]),
				BT_MESH_MODEL(BT_MESH_MODEL_ID_LIGHT_HSL_CLI, NULL, &light_hsl_cli, &hsl[0]),
};

// node contains elements. Note that BT_MESH_MODEL_NONE means "none of this type" and here means "no vendor models"
static struct bt_mesh_elem elements[] = {
				BT_MESH_ELEM(0, sig_models, BT_MESH_MODEL_NONE),
};

// node
static const struct bt_mesh_comp comp = {
				.cid = 0xFFFF,
				.elem = elements,
				.elem_count = ARRAY_SIZE(elements),
};


// Generic OnOff Client - TX message producer functions
// -----------------------------------------------------------

int genericOnOffGet() 
{
	printk("genericOnOffGet\n");
    int err;
    struct bt_mesh_model *model = &sig_models[2];
	if (model->pub->addr == BT_MESH_ADDR_UNASSIGNED) {
		printk("No publish address associated with the generic on off client model - add one with a configuration app like nRF Mesh\n");
		return -1;
	}     
	struct net_buf_simple *msg = model->pub->msg;

	bt_mesh_model_msg_init(msg,	BT_MESH_MODEL_OP_GENERIC_ONOFF_GET);
	printk("publishing get on off message\n");
	err = bt_mesh_model_publish(model);
	if (err) {
		printk("bt_mesh_model_publish err %d\n", err);
	}

	return err;
}

int sendGenOnOffSet(uint8_t on_or_off, uint16_t message_type) 
{
    int err;
    struct bt_mesh_model *model = &sig_models[2];
	if (model->pub->addr == BT_MESH_ADDR_UNASSIGNED) {
		printk("No publish address associated with the generic on off client model - add one with a configuration app like nRF Mesh\n");
		return -1;
	}     
	struct net_buf_simple *msg = model->pub->msg;

	bt_mesh_model_msg_init(msg,	message_type);
	net_buf_simple_add_u8(msg, on_or_off);
	net_buf_simple_add_u8(msg, onoff_tid);
	onoff_tid++;
	printk("publishing set on off state=0x%02x\n",on_or_off);
	err = bt_mesh_model_publish(model);
	if (err) {
		printk("bt_mesh_model_publish err %d\n", err);
	}

	return err;
}

void genericOnOffSetUnAck(uint8_t on_or_off) 
{
	if (sendGenOnOffSet(on_or_off, BT_MESH_MODEL_OP_GENERIC_ONOFF_SET_UNACK))
	{
		printk("Unable to send generic onoff set unack message\n");
	} else {
	    printk("onoff set unack message %d sent\n",on_or_off);
	}
}


void genericOnOffSet(uint8_t on_or_off) 
{
	if (sendGenOnOffSet(on_or_off, BT_MESH_MODEL_OP_GENERIC_ONOFF_SET))
	{
		printk("Unable to send generic onoff set message\n");
	} else {
		printk("onoff set message %d sent\n",on_or_off);
	}
}


// Light HSL Client - TX message producer functions
// -----------------------------------------------------------

int sendLightHslSet(uint16_t message_type) 
{
    int err;
    struct bt_mesh_model *model = &sig_models[3];
	if (model->pub->addr == BT_MESH_ADDR_UNASSIGNED) {
		printk("No publish address associated with the light HSL client model - add one with a configuration app like nRF Mesh\n");
		return -1;
	}     
	struct net_buf_simple *msg = model->pub->msg;

	bt_mesh_model_msg_init(msg,	message_type);
	net_buf_simple_add_le16(msg, hsl[current_hsl_inx][2]); // Yes, index value 2 is correct - ordering of params is Lightness, Hue, Saturation
	net_buf_simple_add_le16(msg, hsl[current_hsl_inx][0]);
	net_buf_simple_add_le16(msg, hsl[current_hsl_inx][1]);
	net_buf_simple_add_u8(msg, hsl_tid);
	hsl_tid++;
	printk("publishing light HSL set message\n");
	err = bt_mesh_model_publish(model);
	if (err) {
		printk("bt_mesh_model_publish err %d\n", err);
	} else {
		current_hsl_inx++;
		if (current_hsl_inx == NUMBER_OF_COLOURS) {
			current_hsl_inx = 0;
		}
	}

	return err;
}

void lightHslSetUnAck() 
{
	if (sendLightHslSet(BT_MESH_MODEL_OP_LIGHT_HSL_SET_UNACK))
	{
		printk("Unable to send light HSL set unack message\n");
	}
}

// Buttons
// -------
void button1_work_handler(struct k_work *work)
{
    genericOnOffSetUnAck(onoff[1]);
	// genericOnOffSet(onoff[1]);
}

void button2_work_handler(struct k_work *work)
{
    genericOnOffSetUnAck(onoff[0]);
	// genericOnOffSet(onoff[0]);
}

void button3_work_handler(struct k_work *work)
{	
 	genericOnOffGet();
}

void button4_work_handler(struct k_work *work)
{
	lightHslSetUnAck();
}

bool debounce(int btn_inx) {
	bool ignore = false;
	btn_time[btn_inx] = k_uptime_get_32();
	if (btn_time[btn_inx] < (btn_last_time[btn_inx] + BUTTON_DEBOUNCE_DELAY_MS)) {
		ignore = true;
	} else {
		ignore = false;
	}
	btn_last_time[btn_inx] = btn_time[btn_inx];
	return ignore;
}

void button_1_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button 1 pressed at %d\n", k_cycle_get_32());

    if (!debounce(0)) {
	  k_work_submit(&button1_work);
	}
}

void button_2_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button 2 pressed at %d\n", k_cycle_get_32());
    if (!debounce(1)) {
	  k_work_submit(&button2_work);
	}
}

void button_3_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button 3 pressed at %d\n", k_cycle_get_32());
    if (!debounce(2)) {
	  k_work_submit(&button3_work);
	}
}

void button_4_pressed(const struct device *dev, struct gpio_callback *cb,
		    uint32_t pins)
{
	printk("Button 4 pressed at %d\n", k_cycle_get_32());
    if (!debounce(3)) {
	  k_work_submit(&button4_work);
	}
}

// -------------------------------------------------------------------------------------------------------
// LED
// -------

void configureLED(void)
{
	printk("configureLED\n");

	int ret = 0;

	if (led.port && !device_is_ready(led.port)) {
		printk("Error %d: LED device %s is not ready; ignoring it\n",
		       ret, led.port->name);
		led.port = NULL;
	}
	if (led.port) {
		ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT);
		if (ret != 0) {
			printk("Error %d: failed to configure LED device %s pin %d\n",
			       ret, led.port->name, led.pin);
			led.port = NULL;
		} else {
			printk("Set up LED at %s pin %d\n", led.port->name, led.pin);
		}
	}

	// LED 0
	ledOff();
}


// -------------------------------------------------------------------------------------------------------
// Buttons
// -------

void configureButtons(void)
{
	printk("configureButtons\n");

	int ret;

	// Button 1
	k_work_init(&button1_work, button1_work_handler);
	ret = gpio_pin_configure_dt(&button1, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button1.port->name, button1.pin);
		return;
	}

	ret = gpio_pin_interrupt_configure_dt(&button1,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button1.port->name, button1.pin);
		return;
	}

	gpio_init_callback(&gpio_btn1_cb, button_1_pressed, BIT(button1.pin));
	gpio_add_callback(button1.port, &gpio_btn1_cb);
	printk("Set up button at %s pin %d\n", button1.port->name, button1.pin);

	// Button 2
	k_work_init(&button2_work, button2_work_handler);
	ret = gpio_pin_configure_dt(&button2, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button2.port->name, button2.pin);
		return;
	}

	ret = gpio_pin_interrupt_configure_dt(&button2,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button2.port->name, button2.pin);
		return;
	}

	gpio_init_callback(&gpio_btn2_cb, button_2_pressed, BIT(button2.pin));
	gpio_add_callback(button2.port, &gpio_btn2_cb);
	printk("Set up button at %s pin %d\n", button2.port->name, button2.pin);

	// Button 3
	k_work_init(&button3_work, button3_work_handler);
	ret = gpio_pin_configure_dt(&button3, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button3.port->name, button3.pin);
		return;
	}

	ret = gpio_pin_interrupt_configure_dt(&button3,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button3.port->name, button3.pin);
		return;
	}

	gpio_init_callback(&gpio_btn3_cb, button_3_pressed, BIT(button3.pin));
	gpio_add_callback(button3.port, &gpio_btn3_cb);
	printk("Set up button at %s pin %d\n", button3.port->name, button3.pin);

	// Button 4
	k_work_init(&button4_work, button4_work_handler);
	ret = gpio_pin_configure_dt(&button4, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button4.port->name, button4.pin);
		return;
	}

	ret = gpio_pin_interrupt_configure_dt(&button4,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button4.port->name, button4.pin);
		return;
	}

	gpio_init_callback(&gpio_btn4_cb, button_4_pressed, BIT(button4.pin));
	gpio_add_callback(button4.port, &gpio_btn4_cb);
	printk("Set up button at %s pin %d\n", button4.port->name, button4.pin);

}

static void bt_ready(int err)
{
	if (err)
	{
			printk("bt_enable init failed with err %d\n", err);
			return;
	}

	printk("Bluetooth initialised OK\n");

	// prov is a bt_mesh_prov struct and is declared in provisioning.c
	err = bt_mesh_init(&prov, &comp);
	if (err)
	{
			printk("bt_mesh_init failed with err %d\n", err);
			return;
	}

	printk("Mesh initialised OK\n");

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	    printk("Settings loaded\n");
	}

    if (!bt_mesh_is_provisioned()) {
    	printk("Node has not been provisioned - beaconing\n");
		gen_uuid();
		printk("\n%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X\n\n",
				dev_uuid[15], dev_uuid[14], dev_uuid[13], dev_uuid[12],dev_uuid[11], dev_uuid[10], dev_uuid[9], dev_uuid[8],
				dev_uuid[7], dev_uuid[6], dev_uuid[5], dev_uuid[4],dev_uuid[3], dev_uuid[2], dev_uuid[1], dev_uuid[0]);
		bt_mesh_prov_enable(BT_MESH_PROV_ADV | BT_MESH_PROV_GATT);
	} else {
    	printk("Node has already been provisioned\n");
	    printk("Node unicast address: 0x%04x\n",elements[0].addr);
	}

}

void main(void)
{
	int err;
	printk("switch\n");

	onoff_tid = 0;
	hsl_tid = 0;

	configureButtons();

	configureLED();

	err = bt_enable(bt_ready);
	if (err)
	{
			printk("bt_enable failed with err %d\n", err);
	}
}
