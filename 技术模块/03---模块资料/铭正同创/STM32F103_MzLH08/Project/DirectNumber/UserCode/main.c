//========================================================================
//  工程名称：DirectNumber.Uv2
//  作    者: xinqiang Zhang (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: STM32(该工程的IC对像为STM32F103R8T6)
//  实现功能: MzLH08-12864 带汉字库LCD显示模块驱动V1.0版演示  
//				模块的直接数字显示功能演示
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
	unsigned char ucTemp=12;
	unsigned short usTemp=2009;
	System_Init();
	LCD_Init();
	ClrScreen();

	SetBackLight(100);
	FontSet(0,1);
	Show_Char(10,0,ucTemp,0);			//在指定位区域显示一个无符字符型变量
	Show_Short(50,0,usTemp,0);			//在指定位区域显示一个无符短整型变量
	
	Show_Char(10,10,ucTemp,1);			//在指定位区域显示一个无符字符型变量
	Show_Short(50,10,usTemp,1);			//在指定位区域显示一个无符短整型变量
	
	Show_Char(10,20,ucTemp,2);			//在指定位区域显示一个无符字符型变量
	Show_Short(50,20,usTemp,2);			//在指定位区域显示一个无符短整型变量
		
	FontSet(1,1);
	FontMode(1,0);	 
	while(1)
	{
		TimerDly(300);
		Show_Char(10,45,ucTemp,1);			//在指定位区域显示一个无符字符型变量
		Show_Short(50,45,usTemp,0);			//在指定位区域显示一个无符短整型变量
		ucTemp++;
		usTemp+=3;
	}	  	
}




