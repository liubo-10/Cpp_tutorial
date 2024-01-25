
// 2016.8.15---additionDlg.h : 头文件
//

#pragma once


// CMy2016815additionDlg 对话框
class CMy2016815additionDlg : public CDialogEx
{
// 构造
public:
	CMy2016815additionDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY2016815ADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeAddendEdit();
	afx_msg void OnEnChangeSumEdit();
	afx_msg void OnEnChangeSummandEdit();
	afx_msg void OnStnClickedAddendStatic();
	float m_editSummand;
	float m_editAddend;
	float m_editSum;
	afx_msg void OnBnClickedAddButton();
};
