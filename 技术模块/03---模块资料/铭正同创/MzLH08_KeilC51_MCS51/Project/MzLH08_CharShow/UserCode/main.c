//========================================================================
//  工程名称：CharShow
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: MCS51 （本例选择AT89S52）
//  编程环境: Keil C51
//  实现功能: MzLH08模块的基本显示功能演示程序,实现字符显示
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
//  日期:  2009-02-10
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
	LCD_Init();
	SetBackLight(0);				//设置背光的亮度等级为0
	ClrScreen();
	
	FontSet(0,1); 					//选择ASCII字符0(6X10),字符色为1(黑色)
	PutChar(10,0,'A');				//在指定位置显示字符A
	FontSet(1,1); 					//选择ASCII字符1(8X16),字符色为1(黑色)
	PutChar(20,0,'A');				//在指定位置显示字符A

	Rectangle(64,0,127,20,1);		//在指定位置绘制一个黑色的矩形作背景
	FontSet(1,0); 					//选择ASCII字符1(8X16),字符色为0(白色)
	FontMode(0,1);					//设置字符覆盖模式为禁止，字符背景覆盖色为1 	
	PutChar(70,1,'B');				//显示ASCII字符
	FontSet(1,1);					//选择ASCII字符1(8X16),字符色为1(黑色)
	FontMode(1,0);					//设置字符覆盖模式为使能，字符背景覆盖色为0 					
	PutChar(80,1,'a');				//显示ASCII字符
		
	PutString(0,17,"MzDesign");		//在指定位置开始显示ASCII字符串
	FontSet(0,1);
	PutString(66,23,"--MzLH08");

	FontSet_cn(1,1);
	PutChar_cn(10,33,"显");
	PutString_cn(40,33,"铭正同创");
	FontSet_cn(0,1);
	PutChar_cn(10,50,"显");
	PutString_cn(40,50,"汉字库液晶");  

	SetBackLight(100);			//设置背光打开 
	
	while(1)
	{
	}
}


