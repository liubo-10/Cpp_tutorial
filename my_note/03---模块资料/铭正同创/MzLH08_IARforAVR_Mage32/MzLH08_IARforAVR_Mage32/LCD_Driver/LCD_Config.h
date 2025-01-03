
#include "iom32.h"

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register
#define SPI_CS  0x10		//定义CS接在PortB4端口
#define SPI_SDA 0x20		//定义SDA接在PortB5端口
#define SPI_SCK 0x80		//定义SCK接在PortB7端口
#define SPI_RES 0x08		//定义RESET接PortB3端口


#define LCD_CMD_Dir		DDRB
#define LCD_CMD_Buffer	PORTB
#define LCD_CMD_Data    PINB

