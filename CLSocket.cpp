#include "pch.h"
#include "CLSocket.h"
#include "tsDlg.h"

CLSocket::CLSocket(CtsDlg* pDlg)
{
	m_pDlg = pDlg;
}

CLSocket::~CLSocket()
{
	m_pDlg = NULL;
}

void CLSocket::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CSocket::OnAccept(nErrorCode);
	m_pDlg->OnAccept();
}
IMPLEMENT_DYNAMIC(CLSocket,CSocket)
