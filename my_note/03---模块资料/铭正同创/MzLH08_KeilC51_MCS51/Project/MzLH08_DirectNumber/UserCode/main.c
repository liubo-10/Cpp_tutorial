//========================================================================
//  工程名称：DirectNumber
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: MCS51 （本例选择AT89S52）
//  编程环境: Keil C51
//  实现功能: MzLH08模块的直接数字显示功能演示
//
//  系统要求: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision3（or later）
//  组成文件:
//     	main.c		----主程序文件
//		LCD_Dis.c
//     	LCD_Dis.h
//					----MzLH08模块的基本驱动程序
//	硬件连接:
//		LCD CS		    ---P1.0
//		LCD SCK			---P1.2
//		LCD SDA			---P1.1
//		LCD RST			---P1.3
//  端口定义请参考LCD_Config.h文件中的定义
//
//	CPU运行频率11.0592MHz	(每个指令为12周期)
//
//		LCD 供电请参考具体的模块是3.3V的还是5V模块
//
//  当前版本:  V1.00
//  日期:  2010-02-10
//  
//  参考文件: 
//  维护记录:
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
	SetBackLight(0);				//设置背光的亮度等级为0
	ClrScreen();
	FontSet(0,1);
	ShowChar(10,0,ucTemp,0);			//在指定位区域显示一个无符字符型变量
	ShowShort(50,0,usTemp,0);			//在指定位区域显示一个无符短整型变量
	
	ShowChar(10,10,ucTemp,1);			//在指定位区域显示一个无符字符型变量
	ShowShort(50,10,usTemp,1);			//在指定位区域显示一个无符短整型变量
	
	ShowChar(10,20,ucTemp,2);			//在指定位区域显示一个无符字符型变量
	ShowShort(50,20,usTemp,2);			//在指定位区域显示一个无符短整型变量
		
	FontSet(1,1);
	FontMode(1,0);	  

	SetBackLight(100);					//设置背光打开	 

	while(1)
	{

		TimeDelay(200);
		ShowChar(10,45,ucTemp,1);			//在指定位区域显示一个无符字符型变量
		ShowShort(50,45,usTemp,0);			//在指定位区域显示一个无符短整型变量
		ucTemp++;
		usTemp+=3;		
	}
}


