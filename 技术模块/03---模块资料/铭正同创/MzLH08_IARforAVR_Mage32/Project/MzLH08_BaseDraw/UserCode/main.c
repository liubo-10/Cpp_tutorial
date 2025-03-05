//========================================================================
//  �������ƣ�MzLH08_BaseDraw
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: AVR ������ѡ��AVR Mega32��
//  ��̻���: IAR Embedded Workbench IDE for AVR
//  ʵ�ֹ���: MzLH08ģ��Ļ�����ʾ������ʾ����,ʵ�ֻ��\ֱ��\����
//
//  ϵͳҪ��: PC with CPU 233MHz,128MB RAM,
//  ����ļ�:
//     	main.c		----�������ļ�
//		LCD_Dis.c
//     	LCD_Dis.h
//			----MzLH08ģ��Ļ�����������
//	Ӳ������:
//		LCD CS		    ---PortB4
//		LCD SCK			---PortB7
//		LCD SDA			---PortB5
//		LCD RST			---PortB3
//  �˿ڶ�����ο�LCD_Config.h�ļ��еĶ���
//
//	CPU����Ƶ��8MHz
//
//		LCD ������ο������ģ����3.3V�Ļ���5Vģ��
//
//  ��ǰ�汾:  V1.00
//  ����:  2010-02-10
//  
//  �ο��ļ�: 
//  ά����¼:
//-------------------------------------------------------------------
//  Version   2010-02-10-V10   Modified By    Xinqiang Zhang
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


