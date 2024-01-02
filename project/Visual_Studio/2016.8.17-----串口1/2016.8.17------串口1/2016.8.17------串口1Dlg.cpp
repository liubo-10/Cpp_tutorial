
// 2016.8.17------串口1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2016.8.17------串口1.h"
#include "2016.8.17------串口1Dlg.h"
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


// CMy2016817串口1Dlg 对话框




CMy2016817串口1Dlg::CMy2016817串口1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2016817串口1Dlg::IDD, pParent)
	, m_receive(_T(""))
	, m_send(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2016817串口1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_MSComm);
	DDX_Text(pDX, IDC_EDIT1, m_receive);
	DDX_Text(pDX, IDC_EDIT2, m_send);
}

BEGIN_MESSAGE_MAP(CMy2016817串口1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMy2016817串口1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMy2016817串口1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy2016817串口1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy2016817串口1Dlg 消息处理程序

BOOL CMy2016817串口1Dlg::OnInitDialog()
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
	/*m_MSComm.SetCommPort(1); //设置串口
    m_MSComm.SetInBufferSize(1024); //设置输入缓冲区大小
    m_MSComm.SetOutBufferSize(1024); //设置输出缓冲区大小
    m_MSComm.SetRThreshold(1); //设置收到多少个字符后触发OnComm事件
    m_MSComm.SetPortOpen(TRUE); //打开串口
    m_MSComm.SetInputMode(1); //设置输入方式为二进制方式
    m_MSComm.SetSettings("9600,n,8,1"); //设置波特率等参数
    m_MSComm.SetInputLen(0); //设置当前接收长度为0
    m_MSComm.GetInput(); //先预读缓冲区以清除残留数据*/
	m_MSComm.put_CommPort(1); //设置串口
	m_MSComm.put_InBufferSize(1024); //设置输入缓冲区大小
    m_MSComm.put_OutBufferSize(1024); //设置输出缓冲区大小
    m_MSComm.put_RThreshold(1); //设置收到多少个字符后触发OnComm事件
    m_MSComm.put_PortOpen(TRUE); //打开串口
    m_MSComm.put_InputMode(1); //设置输入方式为二进制方式
    m_MSComm.put_Settings(_T("9600,n,8,1")); //设置波特率等参数
    m_MSComm.put_InputLen(0); //设置当前接收长度为0
    m_MSComm.get_Input(); //先预读缓冲区以清除残留数据

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2016817串口1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy2016817串口1Dlg::OnPaint()
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
HCURSOR CMy2016817串口1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//-------------------------------------------------------
//-------------------------------------------------------

void CMy2016817串口1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy2016817串口1Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
BEGIN_EVENTSINK_MAP(CMy2016817串口1Dlg, CDialogEx)
	ON_EVENT(CMy2016817串口1Dlg, IDC_MSCOMM1, 1, CMy2016817串口1Dlg::OnCommMscomm1, VTS_NONE)
END_EVENTSINK_MAP()


void CMy2016817串口1Dlg::OnCommMscomm1()
{
	// TODO: 在此处添加消息处理程序代码
	int resEvent;
    resEvent = m_MSComm.get_CommEvent();
    if(resEvent == 2);
      {
        VARIANT data;
        data = m_MSComm.get_Input();
        CString str;
        str = data.bstrVal;
        m_receive += str + "rn";//m_receive为显示接收到数据的编辑框变量
        UpdateData(FALSE);
      }
}


void CMy2016817串口1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
    m_receive += m_send + "rn";
    UpdateData(FALSE);
    m_MSComm.put_Output((COleVariant)m_send);//m_Send为输入发送消息的编辑框变量
    Sleep(1000);



}
