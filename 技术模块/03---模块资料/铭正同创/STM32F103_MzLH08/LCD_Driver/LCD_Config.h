
#include "STM32F10x_lib.h"

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register
/*
sbit SPI_SS=P0^7;			//定义SS接在IOA0端口
sbit SPI_SDA=P0^6;			//定义SDA接在IOA1端口
sbit SPI_SCK=P0^4;			//定义SCK接在IOA3端口
sbit SPI_RES=P0^3;			//定义RESET接IOA4端口
sbit SPI_BUSY=P0^2;			//定义BUSY接IOA5端口*/

#define LCD_Ctrl_GPIO()		//PINSEL1 &= ~(0x00003cfc)
#define LCD_Ctrl_Out()		//IODIR0 |= (SPI_SS+SPI_SDA+SPI_SCK+SPI_RES)
#define LCD_Ctrl_In()		//IODIR0 &= ~(SPI_BUSY)
#define LCD_Ctrl_Set(n)		GPIOB->BSRR = n
#define LCD_Ctrl_Clr(n)		GPIOB->BSRR = ((n)<<16)

#define SPI_CS				(unsigned int)(0x01<<13)
#define SPI_CS_SET()		GPIOB->BSRR = SPI_CS
#define SPI_CS_CLR()		GPIOB->BSRR = (SPI_CS<<16)

#define SPI_SDA				(unsigned int)(0x01<<15)
#define SPI_SDA_SET()		GPIOB->BSRR = SPI_SDA
#define SPI_SDA_CLR()		GPIOB->BSRR = (SPI_SDA<<16)

#define SPI_SCK				(unsigned int)(0x01<<14)
#define SPI_SCK_SET()		GPIOB->BSRR = SPI_SCK
#define SPI_SCK_CLR()		GPIOB->BSRR = (SPI_SCK<<16)

#define SPI_RES				(unsigned int)(0x01<<12)
#define SPI_RES_SET()		GPIOB->BSRR = SPI_RES
#define SPI_RES_CLR()		GPIOB->BSRR = (SPI_RES<<16)

#define SPI_BUSY			(unsigned int)(0x01<<8)
#define SPI_BUSY_SET()		GPIOA->BSRR = SPI_BUSY
#define SPI_BUSY_CLR()		GPIOA->BSRR = (SPI_BUSY<<16)
#define SPI_BUSY_READ()		((GPIOA->IDR&SPI_BUSY)>>22)


