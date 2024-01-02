
// 2016.8.15---additionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2016.8.15---addition.h"
#include "2016.8.15---additionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2016815additionDlg 对话框




CMy2016815additionDlg::CMy2016815additionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2016815additionDlg::IDD, pParent)
	, m_editSummand(0)
	, m_editAddend(0)
	, m_editSum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2016815additionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
}

BEGIN_MESSAGE_MAP(CMy2016815additionDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_ADDEND_EDIT, &CMy2016815additionDlg::OnEnChangeAddendEdit)
	ON_EN_CHANGE(IDC_SUM_EDIT, &CMy2016815additionDlg::OnEnChangeSumEdit)
	ON_EN_CHANGE(IDC_SUMMAND_EDIT, &CMy2016815additionDlg::OnEnChangeSummandEdit)
	ON_STN_CLICKED(IDC_ADDEND_STATIC, &CMy2016815additionDlg::OnStnClickedAddendStatic)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CMy2016815additionDlg::OnBnClickedAddButton)
END_MESSAGE_MAP()


// CMy2016815additionDlg 消息处理程序

BOOL CMy2016815additionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2016815additionDlg::OnPaint()
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
HCURSOR CMy2016815additionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2016815additionDlg::OnEnChangeAddendEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy2016815additionDlg::OnEnChangeSumEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy2016815additionDlg::OnEnChangeSummandEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMy2016815additionDlg::OnStnClickedAddendStatic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMy2016815additionDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	 // 将各控件中的数据保存到相应的变量   
    UpdateData(TRUE);   
  
    // 将被加数和加数的加和赋值给m_editSum   
    m_editSum = m_editSummand + m_editAddend;   
  
    // 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
    UpdateData(FALSE);   
}
