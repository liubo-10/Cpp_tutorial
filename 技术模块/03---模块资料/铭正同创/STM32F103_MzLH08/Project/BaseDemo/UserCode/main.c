//========================================================================
//  工程名称：BaseDraw.Uv2
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: STM32(该工程的IC对像为STM32F103R8T6)
//  实现功能: MzLH08-12864 带汉字库LCD显示模块驱动V1.0版演示  
//				基本显示功能演示
//
//  系统要求: PC with CPU 233MHz,128MB RAM,
//                      Keil uVision 3（or later）
//
//  涉及的库：(a) 
//
//  组成文件:
//		STM32F10x_vector.s	----STM32的启动文件，适应于STM32应用库的，不要修改
//		cortexm3_macro.s	----STM32的一些宏定义
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
	System_Init();
	LCD_Init();
	ClrScreen();
	SetBackLight(100);
	SetPaintMode(1,1);				//设置绘图前景色为黑色
	PutPixel(0,0);					//绘制点
	PutPixel(0,1);
	PutPixel(0,3);
	PutPixel(2,0);
	PutPixel(4,0);
	PutPixel(6,0);
	PutPixel(3,3);

	Line(0,6,127,6);				//绘制直线
	Line(8,8,120,8);
	Line(3,10,3,30);
	Line(10,10,30,30);
	Line(10,30,30,10);

	Rectangle(35,10,65,30,0); 		//绘制矩形
	Rectangle(70,10,100,30,1);

	Circle(30,48,15,0);
	Circle(30,48,13,1); 	
	while(1)
	{
	}	  	
}




