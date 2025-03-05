//========================================================================
//  �������ƣ�DirectNumber
//  ��    ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	��Ȩ���У���������ͬ���Ƽ����޹�˾   www.mzdesign.com.cn
//  ��ӦоƬ: MCS51 ������ѡ��AT89S52��
//  ��̻���: Keil C51
//  ʵ�ֹ���: MzLH08ģ���ֱ��������ʾ������ʾ
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
//  Version   2010-02-10-V10   Modified By    Xinqiang Zhang
//
//========================================================================

#include "LCD_Dis.h"

int main(void)
{
	unsigned char ucTemp=12;
	unsigned short usTemp=2009;
	LCD_Init();
	SetBackLight(0);				//���ñ�������ȵȼ�Ϊ0
	ClrScreen();
	FontSet(0,1);
	ShowChar(10,0,ucTemp,0);			//��ָ��λ������ʾһ���޷��ַ��ͱ���
	ShowShort(50,0,usTemp,0);			//��ָ��λ������ʾһ���޷������ͱ���
	
	ShowChar(10,10,ucTemp,1);			//��ָ��λ������ʾһ���޷��ַ��ͱ���
	ShowShort(50,10,usTemp,1);			//��ָ��λ������ʾһ���޷������ͱ���
	
	ShowChar(10,20,ucTemp,2);			//��ָ��λ������ʾһ���޷��ַ��ͱ���
	ShowShort(50,20,usTemp,2);			//��ָ��λ������ʾһ���޷������ͱ���
		
	FontSet(1,1);
	FontMode(1,0);	  

	SetBackLight(100);					//���ñ����	 

	while(1)
	{

		TimeDelay(200);
		ShowChar(10,45,ucTemp,1);			//��ָ��λ������ʾһ���޷��ַ��ͱ���
		ShowShort(50,45,usTemp,0);			//��ָ��λ������ʾһ���޷������ͱ���
		ucTemp++;
		usTemp+=3;		
	}
}


