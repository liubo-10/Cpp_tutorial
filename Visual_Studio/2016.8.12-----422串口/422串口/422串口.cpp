// 422串口.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(void)
{
	HANDLE hCom;  
   DWORD dwErrorHcomm=CreateFile(“COM1”,GENERIC_READ|GENERIC_WRITE  
   ,0, NULL,OPEN_EXISTING, 0, NULL);  
if (hComm==(HANDLE)0Xffff)  
{  
    dwError=GetLastError();  
    MessageBox(dwError);  
}   
	
	
	
	return 0;
}

