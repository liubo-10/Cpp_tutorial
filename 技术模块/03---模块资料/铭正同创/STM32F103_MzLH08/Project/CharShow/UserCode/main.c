//========================================================================
//  工程名称：CharShow.uV2
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: STM32(该工程的IC对像为STM32F103R8T6)
//  实现功能: MzLH08-12864 带汉字库LCD显示模块驱动V1.0版演示  
//				字符显示功能演示
//
//  系统要求: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision 3（or later）
//
//  涉及的库：(a) 
//
//  组成文件:
//		STM32F10x_vector.s	----STM32的启动文件，适应于STM32应用库的，不要修改
//		STM32F10X.lib	----STM32的应用库文件
//		cortexm3_macro.s----STM32的一些宏定义，必需的
//		stm32f10x_conf.h----STM32的库配置文件
//		stm32f10x_it.c	----STM32的中断定义文件
//
//		STM32F10X_System.c	----当前工程的系统初始化，包括晶体初始化、中断初始化以及端口初始化
//
//     	main.c		----主程序文件
//		
//		LCD_Driver\ ----LCD驱动程序集
//			LCD_Dis.c   ----LCD功能接口函数
//     		LCD_Dis.h	----头文件
//						----基本驱动程序
//			LCD_Config.h	----LCD相关的定义头文件，如端口定义等
//     	main.c		----主程序文件
//
//	硬件连接:
//		CS接在GPIOB 13端口
//		SDA接在GPIOB 15端口
//		SCK接在GPIOB 14端口
//		RST接GPIOB 12端口
//		BS(BUSY)接GPIOA 8端口  (注:本例并没有连接该端口,也没有使用)
//
//	CPU运行频率72MHz
//
//		此代码仅供参考，注意该模组的供电为3.3V，如使用传统的5V的51片子驱该模组时
//		切记要给模组供3.3V的电，不要供5V，端口为5V倒是没什么，只是要注意LCD的供电    
//
//  当前版本:  V1.0
//  日期:  2010-02-10
//  
//  参考文件: 
//  维护记录:
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
	PutChar_cn(10,33,(unsigned short *)"显");
	PutString_cn(40,33,(unsigned short *)"铭正同创");
	FontSet_cn(0,1);
	PutChar_cn(10,50,(unsigned short *)"显");
	PutString_cn(40,50,(unsigned short *)"汉字库液晶"); 
	while(1)
	{
		TimerDly(500);
		Show_Char(30,6,Temp,0);
		Temp++;
	}	  	
}




