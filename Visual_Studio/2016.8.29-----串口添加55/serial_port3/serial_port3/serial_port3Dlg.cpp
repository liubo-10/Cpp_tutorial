
// serial_port3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "serial_port3.h"
#include "serial_port3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cserial_port3Dlg 对话框




Cserial_port3Dlg::Cserial_port3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cserial_port3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cserial_port3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscomm);
}

BEGIN_MESSAGE_MAP(Cserial_port3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &Cserial_port3Dlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &Cserial_port3Dlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON1, &Cserial_port3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cserial_port3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cserial_port3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cserial_port3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cserial_port3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cserial_port3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cserial_port3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cserial_port3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cserial_port3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cserial_port3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Cserial_port3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &Cserial_port3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &Cserial_port3Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &Cserial_port3Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &Cserial_port3Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &Cserial_port3Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &Cserial_port3Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &Cserial_port3Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &Cserial_port3Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &Cserial_port3Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &Cserial_port3Dlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON_START55, &Cserial_port3Dlg::OnBnClickedButtonStart55)
	ON_BN_CLICKED(IDC_BUTTON_STOP55, &Cserial_port3Dlg::OnBnClickedButtonStop55)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Cserial_port3Dlg 消息处理程序

BOOL Cserial_port3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cserial_port3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cserial_port3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cserial_port3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

BEGIN_EVENTSINK_MAP(Cserial_port3Dlg, CDialogEx)
	ON_EVENT(Cserial_port3Dlg, IDC_MSCOMM1, 1, Cserial_port3Dlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()

void Cserial_port3Dlg::OnCommMscomm1()
{
	// TODO: 在此处添加消息处理程序代码
}


void Cserial_port3Dlg::OnBnClickedButtonOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_mscomm.get_PortOpen()) //如果串口是打开的，则先关闭串口
	   {   
		 m_mscomm.put_PortOpen(FALSE);   
	   }   
	 m_mscomm.put_CommPort(3); //选择COM3
	 m_mscomm.put_InBufferSize(1024); //接收缓冲区  
	 m_mscomm.put_OutBufferSize(1024);//发送缓冲区  
	 m_mscomm.put_InputLen(0);//设置当前接收区数据长度为0,表示全部读取  
	 m_mscomm.put_InputMode(1);//以二进制方式读写数据   
	 m_mscomm.put_RThreshold(1);//接收缓冲区有1个及1个以上字符时，将引发接收数据的OnComm事件
	 m_mscomm.put_Settings(_T("9600,n,8,1"));//波特率9600无检验位，8个数据位，1个停止位  
	 if(!m_mscomm.get_PortOpen())//如果串口没有打开则打开  
	   {   
		 m_mscomm.put_PortOpen(TRUE);//打开串口   
		 AfxMessageBox(_T("串口3打开成功"));   
	   }  
	 else 
	   {   
		   m_mscomm.put_OutBufferCount(0);   
	       AfxMessageBox(_T("串口3打开失败"));  
	   }
}


void Cserial_port3Dlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	m_mscomm.put_PortOpen(FALSE);//关闭串口  
	AfxMessageBox(_T("串口3已关闭"));
}


void Cserial_port3Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}

void Cserial_port3Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}

void Cserial_port3Dlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}



void Cserial_port3Dlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	CByteArray hexdata;//发送的数据	
    hexdata.Add(0xC1);
    hexdata.Add(0x03);
    hexdata.Add(0x01);
    hexdata.Add(0x00);
    hexdata.Add(0x00);	
    hexdata.Add(0x30);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}


void Cserial_port3Dlg::OnBnClickedButtonStart55()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1,100,NULL);//参数1：nIDEvent，定时器ID；
                        //参数2：nElapse，定时器定时时间，单位为毫秒；
                        //参数3：回调函数，设为NULL即可。
}


void Cserial_port3Dlg::OnBnClickedButtonStop55()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);//只需输入一个参数（定时器ID）
}


void Cserial_port3Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CByteArray hexdata;//发送的数据	
	switch (nIDEvent)
	{
	  case 1:
          hexdata.Add(0x55);
         // m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
          m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
		  break;
	 }
	CDialogEx::OnTimer(nIDEvent);
}
