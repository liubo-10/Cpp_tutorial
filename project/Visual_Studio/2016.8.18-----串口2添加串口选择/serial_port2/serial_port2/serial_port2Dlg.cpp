
// serial_port2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "serial_port2.h"
#include "serial_port2Dlg.h"
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


// Cserial_port2Dlg 对话框




Cserial_port2Dlg::Cserial_port2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cserial_port2Dlg::IDD, pParent)
	, m_Editsend1(_T(""))
	, m_EditReceive(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cserial_port2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscomm);
	DDX_Control(pDX, IDC_EDIT1, m_EditSend);
	DDX_Text(pDX, IDC_EDIT1, m_Editsend1);
	DDX_Text(pDX, IDC_EDIT2, m_EditReceive);
	DDX_Control(pDX, IDC_COMBO1, m_combl);
}

BEGIN_MESSAGE_MAP(Cserial_port2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &Cserial_port2Dlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &Cserial_port2Dlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &Cserial_port2Dlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_OX, &Cserial_port2Dlg::OnBnClickedButtonOx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cserial_port2Dlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// Cserial_port2Dlg 消息处理程序

BOOL Cserial_port2Dlg::OnInitDialog()
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

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	//------------------------------------------------------------
	CString str;  
	int i;   
	for(i=0;i<15;i++)  
	{     
		str.Format(_T("com %d"),i+1);
		m_combl.InsertString(i,str);   
	}   
	m_combl.SetCurSel(0);//预置COM口



	//----------------------------------------------------------
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cserial_port2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cserial_port2Dlg::OnPaint()
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
HCURSOR Cserial_port2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// -----------------------------------------------------------------------------------
//------------------------------------------------------------------------------------


void Cserial_port2Dlg::OnBnClickedButtonOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	 if(m_mscomm.get_PortOpen()) //如果串口是打开的，则行关闭串口  
	   {   
		 m_mscomm.put_PortOpen(FALSE);   
	   }   
	 m_mscomm.put_CommPort((m_combl.GetCurSel()+1)); //选择串口
	// m_mscomm.put_CommPort(3); //选择COM3  
	 m_mscomm.put_InBufferSize(1024); //接收缓冲区  
	 m_mscomm.put_OutBufferSize(1024);//发送缓冲区  
	 m_mscomm.put_InputLen(0);//设置当前接收区数据长度为0,表示全部读取  
	 m_mscomm.put_InputMode(1);//以二进制方式读写数据   
	 m_mscomm.put_RThreshold(1);//接收缓冲区有1个及1个以上字符时，将引发接收数据的OnComm事件
	 m_mscomm.put_Settings(_T("9600,n,8,1"));//波特率9600无检验位，8个数据位，1个停止位  
	 if(!m_mscomm.get_PortOpen())//如果串口没有打开则打开  
	 {   
		 m_mscomm.put_PortOpen(TRUE);//打开串口   
		 AfxMessageBox(_T("串口打开成功"));   
	 }  
	 else  
	 {   
		 m_mscomm.put_OutBufferCount(0);   
	     AfxMessageBox(_T("串口打开失败"));  
	 }
}


void Cserial_port2Dlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	m_mscomm.put_PortOpen(FALSE);//关闭串口  
	AfxMessageBox(_T("串口已关闭")); 
}


void Cserial_port2Dlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(true); //读取编辑框内容
	VARIANT variant_inp;   
	COleSafeArray safearray_inp; 
	long len,k;  
	unsigned int data[1024]={0};   
	byte rxdata[1024]; //设置 BYTE 数组   
	CString strtemp; 
    
	variant_inp=m_mscomm.get_Input(); //读缓冲区消息    
	safearray_inp=variant_inp; ///变量转换    
	len=safearray_inp.GetOneDimSize(); //得到有效的数据长度    
		for(k=0;k<len;k++)    
		   {    
			 safearray_inp.GetElement(&k,rxdata+k);    
		   }   
		for(k=0;k<len;k++) //将数组转换为 CString 型变量   
		  {     
			strtemp.Format(_T("%x"),*(rxdata+k));   
		    m_Editsend1+=strtemp;     
			CString temp=_T("\r\n"); //换行    
			m_Editsend1+=temp; 
		  }
	m_mscomm.put_Output(COleVariant(m_Editsend1));//发送数据   
	m_Editsend1.Empty(); //发送后清空输入框   
	UpdateData(false); //更新编辑框内容 
}
BEGIN_EVENTSINK_MAP(Cserial_port2Dlg, CDialogEx)
	ON_EVENT(Cserial_port2Dlg, IDC_MSCOMM1, 1, Cserial_port2Dlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void Cserial_port2Dlg::OnCommMscomm1()
{
	// TODO: 在此处添加消息处理程序代码
	static unsigned int cnt=0;  
	VARIANT variant_inp;    
	COleSafeArray safearray_inp;   
	long len,k;    
	unsigned int data[1024]={0};   
	byte rxdata[1024]; //设置 BYTE 数组   
	CString strtemp;    
	if(m_mscomm.get_CommEvent()==2) //值为 2 表示接收缓冲区内有字符   
	  { 
		    cnt++;   
			variant_inp=m_mscomm.get_Input(); //读缓冲区消息    
			safearray_inp=variant_inp; ///变量转换    
			len=safearray_inp.GetOneDimSize(); //得到有效的数据长度    
			for(k=0;k<len;k++)    
			  {    
				  safearray_inp.GetElement(&k,rxdata+k);    
			  }   
			for(k=0;k<len;k++) //将数组转换为 CString 型变量   
			  {     
				  strtemp.Format(_T("%x"),*(rxdata+k));   
				  m_EditReceive+=strtemp;     
				  CString temp=_T("\r\n"); //换行    
				  m_EditReceive+=temp; 
			   } 
	  }   
	UpdateData(FALSE); //更新编辑框内容
}


void Cserial_port2Dlg::OnBnClickedButtonOx()
{
	/*// TODO: 在此添加控件通知处理程序代码
	m_Editsend1.Format(_T("\61 \62"));
	long len=2,k; 
	CString strtemp;
	byte rxdata[1024]; //设置 BYTE 数组  

	for(k=0;k<len;k++) //将数组转换为 CString 型变量   
			  {     
				  strtemp.Format(_T("%x"),*(rxdata+k));   
				  m_Editsend1+=strtemp;     
				  CString temp=_T("\r\n"); //换行    
				  m_Editsend1+=temp; 
			   } 
			   

	
	unsigned char protocoldata[36];
	protocoldata[0] = '\a';
    protocoldata[1] = '\b';
	

    m_mscomm.put_Output(COleVariant(protocoldata[36]));//发送数据
	//m_com.SetOutput(COleVariant(protocoldata[n]));*/

	CByteArray hexdata;//发送的数据	
    hexdata.Add(0x02 );
    hexdata.Add(0x00);
    hexdata.Add(0x18);
    hexdata.Add(0x07);
    hexdata.Add(0xCB);	
    hexdata.Add(0xFF);	
    hexdata.Add(0xFF);	
    hexdata.Add(0xCA);	
    hexdata.Add(0x17);	
    hexdata.Add(0x00);	
    hexdata.Add(0x00);	
    hexdata.Add(0x09);		
    m_mscomm.put_OutBufferCount(0);//清空发送缓冲区
    m_mscomm.put_Output(COleVariant(hexdata));//发送十六进制数据
}







void Cserial_port2Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_mscomm.get_PortOpen())     
	  {    
		  m_mscomm.put_PortOpen(FALSE);  
	  }    
	m_mscomm.put_CommPort( m_combl.GetCurSel()+1 );      
	UpdateData(FALSE); //更新编辑框内容 
}
