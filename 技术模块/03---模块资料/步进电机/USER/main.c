#include "led.h"
#include "delay.h"
#include "sys.h"
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
// void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
 void motor_cw(uint32_t j)//��ת ��ʱ����ת��
{
	int i;
	for(i=1000;i>j;i--) //���ٹ���
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

void motor_ccw(uint32_t j)//��ת
{
	int i;
	for(i=1000;i>j;i--) //���ٹ���
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
	delay_init();	    	 //��ʱ������ʼ��	  
	SDIO_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�

   	while(1)
	{
		motor_ccw(100); //���ڱ����õ��� 28BYJ48������������ٱ�64�����Ե��ת��120r/min,�ٿ�Ϳ���
 
	} 
}

