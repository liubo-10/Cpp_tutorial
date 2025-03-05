//========================================================================
//  工程名称：MzLH08_Bitmap
//  作    者: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)    
//	版权所有：北京铭正同创科技有限公司   www.mzdesign.com.cn
//  适应芯片: AVR （本例选择AVR Mega32）
//  编程环境: IAR Embedded Workbench IDE for AVR
//  实现功能: MzLH08模块的位图显示功能演示
//
//  系统要求: PC with CPU 233MHz,128MB RAM,
//  组成文件:
//     	main.c		----主程序文件
//		Bitmap.c	----利用字模工具制作的单色位图图像资源数组
//		LCD_Dis.c
//     	LCD_Dis.h
//				----MzLH08模块的基本驱动程序
//		LCD_Config.h----端口定义
//	硬件连接:
//		LCD CS		    ---PortB4
//		LCD SCK			---PortB7
//		LCD SDA			---PortB5
//		LCD RST			---PortB3
//  端口定义请参考LCD_Config.h文件中的定义
//	CPU运行频率8MHz
//
//		LCD 供电请参考具体的模块是3.3V的还是5V模块
//		在使用字模工具提取图像的字模时,请注意取模方式为横向取模,即点排列与LCD的点排列
//	方向一致,就是从左到右自上到下的排列,每个byte的数据表示8个单色像素点
//
//		注意,由于位图显示时,MCU传送给LCD模块的数据量较大,请用户参考LCD模块的手册,以及
//	 LCD_Dis.c中的PutBitmap函数,以及具体使用的MCU的相关资料,以保证传输数据至LCD模块时
//	模块中的缓冲区不至于益处而出现显示混乱的情况.
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
#include "Bitmap.h"

int main(void)
{
	LCD_Init();
	SetBackLight(0);				//设置背光的亮度等级为0
	ClrScreen();  					//清屏

	PutBitmap(10,10,101,46,Bitmap01);		//在坐标点10,10为左上角的位置显示尺寸大小为101X46点的位图

	SetBackLight(100);				//设置背光打开
	

	while(1)
	{
		;	
	}
}


