//========================================================================
//  工程名称：MzLH08_BaseDraw
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: AVR （本例选择AVR Mega32）
//  编程环境: IAR Embedded Workbench IDE for AVR
//  实现功能: MzLH08模块的基本显示功能演示程序,实现绘点\直线\矩形
//
//  系统要求: PC with CPU 233MHz,128MB RAM,
//  组成文件:
//     	main.c		----主程序文件
//		LCD_Dis.c
//     	LCD_Dis.h
//			----MzLH08模块的基本驱动程序
//	硬件连接:
//		LCD CS		    ---PortB4
//		LCD SCK			---PortB7
//		LCD SDA			---PortB5
//		LCD RST			---PortB3
//  端口定义请参考LCD_Config.h文件中的定义
//
//	CPU运行频率8MHz
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
	LCD_Init();
	SetBackLight(0);				//设置背光的亮度等级为0
	ClrScreen();
	
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
	SetBackLight(100);				//设置背光亮度	

	while(1)
	{
	}
}


