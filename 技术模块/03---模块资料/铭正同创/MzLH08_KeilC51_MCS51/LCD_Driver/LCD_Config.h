
#include "REG52.h"

#define Dis_X_MAX		128-1
#define Dis_Y_MAX		64-1

//Define the MCU Register

sbit SPI_CS = P1^0;				//����CS����P1.0�˿�
sbit SPI_SDA = P1^1;			//����SDA����P1.1�˿�
sbit SPI_SCK = P1^2;			//����SCK����P1.2�˿�
sbit SPI_RES = P1^3;			//����RESET��P1.3�˿�


