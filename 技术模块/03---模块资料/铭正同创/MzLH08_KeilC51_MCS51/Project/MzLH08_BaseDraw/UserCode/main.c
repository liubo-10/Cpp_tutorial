//========================================================================
//  �������ƣ�BaseDraw
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: MCS51 ������ѡ��AT89S52��
//  ��̻���: Keil C51
//  ʵ�ֹ���: MzLH08ģ��Ļ�����ʾ������ʾ����,ʵ�ֻ��\ֱ��\����
//
//  ϵͳҪ��: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision3��or later��
//  ����ļ�:
//     	main.c		----�������ļ�
//		LCD_Dis.c
//     	LCD_Dis.h
//					----MzLH08ģ��Ļ�����������
//	Ӳ������:
//		LCD CS		    ---P1.0
//		LCD SCK			---P1.2
//		LCD SDA			---P1.1
//		LCD RST			---P1.3
//  �˿ڶ�����ο�LCD_Config.h�ļ��еĶ���
//
//	CPU����Ƶ��11.0592MHz	(ÿ��ָ��Ϊ12����)
//
//		LCD ������ο������ģ����3.3V�Ļ���5Vģ��
//
//  ��ǰ�汾:  V1.00
//  ����:  2010-02-10
//  
//  �ο��ļ�: 
//  ά����¼:
//-------------------------------------------------------------------
//  Version   2010-03-10-V10   Modified By    Xinqiang Zhang
//
//========================================================================

#include "LCD_Dis.h"

int main(void)
{
	LCD_Init();
	SetBackLight(0);				//���ñ�������ȵȼ�Ϊ0
	ClrScreen();
	
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
	SetBackLight(100);				//���ñ�������	 

	while(1)
	{
	}
}


