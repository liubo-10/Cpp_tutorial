
#include "iom32.h"

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register
#define SPI_CS  0x10		//����CS����PortB4�˿�
#define SPI_SDA 0x20		//����SDA����PortB5�˿�
#define SPI_SCK 0x80		//����SCK����PortB7�˿�
#define SPI_RES 0x08		//����RESET��PortB3�˿�


#define LCD_CMD_Dir		DDRB
#define LCD_CMD_Buffer	PORTB
#define LCD_CMD_Data    PINB

