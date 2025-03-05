#include "led.h"
#include "delay.h"
#include "sys.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
// void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
 void motor_cw(uint32_t j)//正转 延时控制转速
{
	int i;
	for(i=1000;i>j;i--) //加速过程
	{
	 GPIO_Write(GPIOA, 8);
   delay_us(i);	
   GPIO_Write(GPIOA, 12);
   delay_us(i);
   GPIO_Write(GPIOA, 4);
   delay_us(i);
   GPIO_Write(GPIOA, 6);
   delay_us(i);
   GPIO_Write(GPIOA, 2);
   delay_us(i);
   GPIO_Write(GPIOA, 3);
   delay_us(i);
   GPIO_Write(GPIOA, 1);
   delay_us(i);
   GPIO_Write(GPIOA, 9);
   delay_us(i);
	}
	while(1)
	{
   GPIO_Write(GPIOA, 8);
   delay_us(j);
   GPIO_Write(GPIOA, 12);
   delay_us(j);
   GPIO_Write(GPIOA, 4);
   delay_us(j);
   GPIO_Write(GPIOA, 6);
   delay_us(j);
   GPIO_Write(GPIOA, 2);
   delay_us(j);
   GPIO_Write(GPIOA, 3);
   delay_us(j);
   GPIO_Write(GPIOA, 1);
   delay_us(j);
   GPIO_Write(GPIOA, 9);
   delay_us(j);
	}
 }

void motor_ccw(uint32_t j)//反转
{
	int i;
	for(i=1000;i>j;i--) //加速过程
	{
	 GPIO_Write(GPIOA, 9);
   delay_us(i);
   GPIO_Write(GPIOA, 1);
   delay_us(i);
   GPIO_Write(GPIOA, 3);
   delay_us(i);
   GPIO_Write(GPIOA, 2);
   delay_us(i);
   GPIO_Write(GPIOA, 6);
   delay_us(i);
   GPIO_Write(GPIOA, 4);
   delay_us(i);
   GPIO_Write(GPIOA, 12);
   delay_us(i);
   GPIO_Write(GPIOA, 8);
   delay_us(i);
	}
	while(1)
	{
   GPIO_Write(GPIOA, 9);
   delay_us(j);
   GPIO_Write(GPIOA, 1);
   delay_us(j);
   GPIO_Write(GPIOA, 3);
   delay_us(j);
   GPIO_Write(GPIOA, 2);
   delay_us(j);
   GPIO_Write(GPIOA, 6);
   delay_us(j);
   GPIO_Write(GPIOA, 4);
   delay_us(j);
   GPIO_Write(GPIOA, 12);
   delay_us(j);
   GPIO_Write(GPIOA, 8);
   delay_us(j);
	}
}
 int main(void)
 {	
	delay_init();	    	 //延时函数初始化	  
	SDIO_Init();		  	//初始化与LED连接的硬件接口

   	while(1)
	{
		motor_ccw(100); //鉴于本人用的是 28BYJ48步进电机，减速比64，所以电机转速120r/min,再快就卡了
 
	} 
}

