/******************************************************************
*  描  述: LED驱动代码
		         LED初始化
											
*  文件名: led.c
*  作  者: 刘博
*  时  间: 2018/08/09
*  版  本: V1.1    
*******************************************************************/
//=======================================宏包含=========================================
#include "led.h"
//=======================================函数区=========================================
/*******************************************************
  描述：LED IO初始化
		      

  函数：void  LED_Init(void)
  参数：无
  返回：无
  备注：
  版本：
********************************************************/
void  LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;                                       //GPIO初始化结构体
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);  //使能PB,PE端口时钟
	
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;								  //LED0-->PB.5 端口配置
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;				//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				//IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);								       //根据设定参数初始化GPIOB.5
  GPIO_SetBits(GPIOB,GPIO_Pin_5);											           //PB.5 输出高

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;								  //LED1-->PE.5 端口配置, 推挽输出
  GPIO_Init(GPIOE, &GPIO_InitStructure);									      //推挽输出 ，IO口速度为50MHz
  GPIO_SetBits(GPIOE,GPIO_Pin_5);											           //PE.5 输出高 
}

/************************** END OF FILE ***************************/








