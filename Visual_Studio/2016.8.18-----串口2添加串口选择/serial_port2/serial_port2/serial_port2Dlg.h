
// serial_port2Dlg.h : 头文件
//

#pragma once
#include "mscomm1.h"
#include "afxwin.h"


// Cserial_port2Dlg 对话框
class Cserial_port2Dlg : public CDialogEx
{
// 构造
public:
	Cserial_port2Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERIAL_PORT2_DIALOG };

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
	CMscomm1 m_mscomm;
	CEdit m_EditSend;
	CString m_Editsend1;
	CString m_EditReceive;
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonSend();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	afx_msg void OnBnClickedButtonOx();
	afx_msg void OnCbnSelchangeCombo1();
private:
	CComboBox m_combl;
};
