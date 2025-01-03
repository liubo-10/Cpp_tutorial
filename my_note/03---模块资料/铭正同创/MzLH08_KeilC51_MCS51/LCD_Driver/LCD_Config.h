
#include "REG52.h"

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register

sbit SPI_CS = P1^0;				//定义CS接在P1.0端口
sbit SPI_SDA = P1^1;			//定义SDA接在P1.1端口
sbit SPI_SCK = P1^2;			//定义SCK接在P1.2端口
sbit SPI_RES = P1^3;			//定义RESET接P1.3端口


