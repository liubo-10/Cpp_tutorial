
// serial_portDlg.h : 头文件
//

#pragma once
#include "mscomm1.h"
#include "afxwin.h"


// Cserial_portDlg 对话框
class Cserial_portDlg : public CDialogEx
{
// 构造
public:
	Cserial_portDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERIAL_PORT_DIALOG };

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
	CMscomm1 m_mscomm;
	CEdit m_EditSend;
	CEdit m_EditReceive;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonClose();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	CString m_EditReceive1;
	afx_msg void OnEnChangeEdit4();
	CString m_EditSend1;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButtonsixteen();
	CMscomm1 m_mscomma;
	CString m_edit_send;
	CString m_edit_receive;
	void OnCommMscomm2();
};
