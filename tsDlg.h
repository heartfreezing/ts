
// tsDlg.h: 头文件
//

#pragma once
#include "CCSocket.h"
#include "CLSocket.h"
#include "CMsg.h"

class CMsg;
// CtsDlg 对话框
class CtsDlg : public CDialogEx
{
// 构造
public:
	CtsDlg(CWnd* pParent = nullptr);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TS_DIALOG };
#endif
	CStatic m_staNum;
	UINT m_nPort;
	CButton m_btnListen;
	CButton m_btnClose;
	CListBox m_listMsg;
	
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
	afx_msg void OnButtonListen();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()

public:
	CLSocket* m_pLSocket;
	CPtrList m_connList;
public:
	void OnAccept();
	void OnRecieve(CCSocket* pSocket);
	void backClients(CMsg* pMsg);
};
