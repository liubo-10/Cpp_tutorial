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

// for debouncing the four buttons
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

static const struct bt_mesh_health_srv_cb health_srv_cb = {
};

// provisioning properties and capabilities


// -------------------------------------------------------------------------------------------------------
// Health Server
// -------------


// -------------------------------------------------------------------------------------------------------
// Generic OnOff Client Model
// --------------------------

uint8_t onoff[] = {
	0,
	1};

// generic on off client - handler functions for this model's RX messages


// generic on off client - message types defined by this model.


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


// Generic OnOff Client - TX message producer functions
// -----------------------------------------------------------

// Light HSL Client - TX message producer functions
// -----------------------------------------------------------


// Buttons
// -------
void button1_work_handler(struct k_work *work)
{
}

void button2_work_handler(struct k_work *work)
{
}

void button3_work_handler(struct k_work *work)
{	
}

void button4_work_handler(struct k_work *work)
{
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

void button_1_pressed(const struct device *gpiob, struct gpio_callback *cb,
											uint32_t pins)
{
	// printk("Button 1 pressed at %d\n", k_cycle_get_32());

    if (!debounce(0)) {
	  k_work_submit(&button1_work);
	}
}

void button_2_pressed(const struct device *gpiob, struct gpio_callback *cb,
											uint32_t pins)
{
	// printk("Button 2 pressed at %d\n", k_cycle_get_32());
    if (!debounce(1)) {
	  k_work_submit(&button2_work);
	}
}

void button_3_pressed(const struct device *gpiob, struct gpio_callback *cb,
											uint32_t pins)
{
	// printk("Button 3 pressed at %d\n", k_cycle_get_32());
    if (!debounce(2)) {
	  k_work_submit(&button3_work);
	}
}

void button_4_pressed(const struct device *gpiob, struct gpio_callback *cb,
											uint32_t pins)
{
	// printk("Button 4 pressed at %d\n", k_cycle_get_32());
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

void main(void)
{
	int err;
	printk("switch\n");

	onoff_tid = 0;
	hsl_tid = 0;

	configureButtons();

	configureLED();

}
