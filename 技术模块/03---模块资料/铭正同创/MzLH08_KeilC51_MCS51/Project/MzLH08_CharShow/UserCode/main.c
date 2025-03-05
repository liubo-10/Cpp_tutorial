//========================================================================
//  �������ƣ�CharShow
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: MCS51 ������ѡ��AT89S52��
//  ��̻���: Keil C51
//  ʵ�ֹ���: MzLH08ģ��Ļ�����ʾ������ʾ����,ʵ���ַ���ʾ
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
//  ����:  2009-02-10
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
	PutChar_cn(10,33,"��");
	PutString_cn(40,33,"����ͬ��");
	FontSet_cn(0,1);
	PutChar_cn(10,50,"��");
	PutString_cn(40,50,"���ֿ�Һ��");  

	SetBackLight(100);			//���ñ���� 
	
	while(1)
	{
	}
}


