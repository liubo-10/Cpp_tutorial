/******************************************************************
*  ��  ��: LED��������
		         LED��ʼ��
											
*  �ļ���: led.c
*  ��  ��: ����
*  ʱ  ��: 2018/08/09
*  ��  ��: V1.1    
*******************************************************************/
//=======================================�����=========================================
#include "led.h"
//=======================================������=========================================
/*******************************************************
  ������LED IO��ʼ��
		      

  ������void  LED_Init(void)
  ��������
  ���أ���
  ��ע��
  �汾��
********************************************************/
void  LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;                                       //GPIO��ʼ���ṹ��
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);  //ʹ��PB,PE�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;								  //LED0-->PB.5 �˿�����
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;				//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				//IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);								       //�����趨������ʼ��GPIOB.5
  GPIO_SetBits(GPIOB,GPIO_Pin_5);											           //PB.5 �����

  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;								  //LED1-->PE.5 �˿�����, �������
  GPIO_Init(GPIOE, &GPIO_InitStructure);									      //������� ��IO���ٶ�Ϊ50MHz
  GPIO_SetBits(GPIOE,GPIO_Pin_5);											           //PE.5 ����� 
}

/************************** END OF FILE ***************************/








