
// AdditionDlg.h : 头文件
//

#pragma once


// CAdditionDlg 对话框
class CAdditionDlg : public CDialogEx
{
// 构造
public:
	CAdditionDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ADDITION_DIALOG };

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
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnBnClickedAddButton();
};
