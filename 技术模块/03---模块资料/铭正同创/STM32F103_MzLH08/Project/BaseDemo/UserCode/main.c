//========================================================================
//  �������ƣ�BaseDraw.Uv2
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: STM32(�ù��̵�IC����ΪSTM32F103R8T6)
//  ʵ�ֹ���: MzLH08-12864 �����ֿ�LCD��ʾģ������V1.0����ʾ  
//				������ʾ������ʾ
//
//  ϵͳҪ��: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision 3��or later��
//
//  �漰�Ŀ⣺(a) 
//
//  ����ļ�:
//		STM32F10x_vector.s	----STM32�������ļ�����Ӧ��STM32Ӧ�ÿ�ģ���Ҫ�޸�
//		cortexm3_macro.s	----STM32��һЩ�궨��
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
	System_Init();
	LCD_Init();
	ClrScreen();
	SetBackLight(100);
	SetPaintMode(1,1);				//���û�ͼǰ��ɫΪ��ɫ
	PutPixel(0,0);					//���Ƶ�
	PutPixel(0,1);
	PutPixel(0,3);
	PutPixel(2,0);
	PutPixel(4,0);
	PutPixel(6,0);
	PutPixel(3,3);

	Line(0,6,127,6);				//����ֱ��
	Line(8,8,120,8);
	Line(3,10,3,30);
	Line(10,10,30,30);
	Line(10,30,30,10);

	Rectangle(35,10,65,30,0); 		//���ƾ���
	Rectangle(70,10,100,30,1);

	Circle(30,48,15,0);
	Circle(30,48,13,1); 	
	while(1)
	{
	}	  	
}




