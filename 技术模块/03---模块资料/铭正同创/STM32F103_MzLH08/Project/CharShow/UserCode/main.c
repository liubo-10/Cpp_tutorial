//========================================================================
//  �������ƣ�CharShow.uV2
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: STM32(�ù��̵�IC����ΪSTM32F103R8T6)
//  ʵ�ֹ���: MzLH08-12864 �����ֿ�LCD��ʾģ������V1.0����ʾ  
//				�ַ���ʾ������ʾ
//
//  ϵͳҪ��: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision 3��or later��
//
//  �漰�Ŀ⣺(a) 
//
//  ����ļ�:
//		STM32F10x_vector.s	----STM32�������ļ�����Ӧ��STM32Ӧ�ÿ�ģ���Ҫ�޸�
//		STM32F10X.lib	----STM32��Ӧ�ÿ��ļ�
//		cortexm3_macro.s----STM32��һЩ�궨�壬�����
//		stm32f10x_conf.h----STM32�Ŀ������ļ�
//		stm32f10x_it.c	----STM32���ж϶����ļ�
//
//		STM32F10X_System.c	----��ǰ���̵�ϵͳ��ʼ�������������ʼ�����жϳ�ʼ���Լ��˿ڳ�ʼ��
//
//     	main.c		----�������ļ�
//		
//		LCD_Driver\ ----LCD��������
//			LCD_Dis.c   ----LCD���ܽӿں���
//     		LCD_Dis.h	----ͷ�ļ�
//						----������������
//			LCD_Config.h	----LCD��صĶ���ͷ�ļ�����˿ڶ����
//     	main.c		----�������ļ�
//
//	Ӳ������:
//		CS����GPIOB 13�˿�
//		SDA����GPIOB 15�˿�
//		SCK����GPIOB 14�˿�
//		RST��GPIOB 12�˿�
//		BS(BUSY)��GPIOA 8�˿�  (ע:������û�����Ӹö˿�,Ҳû��ʹ��)
//
//	CPU����Ƶ��72MHz
//
//		�˴�������ο���ע���ģ��Ĺ���Ϊ3.3V����ʹ�ô�ͳ��5V��51Ƭ������ģ��ʱ
//		�м�Ҫ��ģ�鹩3.3V�ĵ磬��Ҫ��5V���˿�Ϊ5V����ûʲô��ֻ��Ҫע��LCD�Ĺ���    
//
//  ��ǰ�汾:  V1.0
//  ����:  2010-02-10
//  
//  �ο��ļ�: 
//  ά����¼:
//-------------------------------------------------------------------
//  Version   2010-02-10-V10   Modified By    Xinqiang Zhang
//
//========================================================================
#include "STM32F10x_lib.h"
#include "STM32F10x_System.h"
#include "LCD_Dis.h"


void TimerDly(unsigned int Timer)
{
	unsigned int i=0;
	while(Timer)
	{
		for(i=0;i<700;i++);
		Timer--;
	}
}


int main(void)
{
	unsigned char Temp=0;
	System_Init();
	LCD_Init();
	ClrScreen();

	SetBackLight(127);
	FontSet(0,1); 					//ѡ��ASCII�ַ�0(6X10),�ַ�ɫΪ1(��ɫ)
	PutChar(10,0,'A');				//��ָ��λ����ʾ�ַ�A
	FontSet(1,1); 					//ѡ��ASCII�ַ�1(8X16),�ַ�ɫΪ1(��ɫ)
	PutChar(20,0,'A');				//��ָ��λ����ʾ�ַ�A

	Rectangle(64,0,127,20,1);		//��ָ��λ�û���һ����ɫ�ľ���������
	FontSet(1,0); 					//ѡ��ASCII�ַ�1(8X16),�ַ�ɫΪ0(��ɫ)
	FontMode(0,1);					//�����ַ�����ģʽΪ��ֹ���ַ���������ɫΪ1 	
	PutChar(70,1,'B');				//��ʾASCII�ַ�
	FontSet(1,1);					//ѡ��ASCII�ַ�1(8X16),�ַ�ɫΪ1(��ɫ)
	FontMode(1,0);					//�����ַ�����ģʽΪʹ�ܣ��ַ���������ɫΪ0 					
	PutChar(80,1,'a');				//��ʾASCII�ַ�
		
	PutString(0,17,"MzDesign");		//��ָ��λ�ÿ�ʼ��ʾASCII�ַ���
	FontSet(0,1);
	PutString(66,23,"--MzLH08");

	FontSet_cn(1,1);
	PutChar_cn(10,33,(unsigned short *)"��");
	PutString_cn(40,33,(unsigned short *)"����ͬ��");
	FontSet_cn(0,1);
	PutChar_cn(10,50,(unsigned short *)"��");
	PutString_cn(40,50,(unsigned short *)"���ֿ�Һ��"); 
	while(1)
	{
		TimerDly(500);
		Show_Char(30,6,Temp,0);
		Temp++;
	}	  	
}




