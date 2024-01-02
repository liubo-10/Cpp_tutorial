
// 窗口求根1Dlg.h : 头文件
//

#pragma once


// C窗口求根1Dlg 对话框
class C窗口求根1Dlg : public CDialogEx
{
// 构造
public:
	C窗口求根1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnChangeEdit1();
	afx_msg void m_a();
	double m_b;
	double m_c;
	afx_msg void OnEnChangeEdit6();
	double m_d;
	double m_x1;
	double m_x2;
};
