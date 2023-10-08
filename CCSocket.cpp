#include "pch.h"
#include "CCSocket.h"
#include"tsDlg.h"
#include "CMsg.h"
CCSocket::CCSocket(CtsDlg* pDlg)
{
	m_pDlg = pDlg;
	m_pFile = NULL;
	m_pArchiveIn = NULL;
	m_pArchiveOut = NULL;
}

CCSocket::~CCSocket()
{
	m_pDlg = NULL;
	if (m_pArchiveOut != NULL)delete m_pArchiveOut;
	if (m_pArchiveIn != NULL)delete m_pArchiveIn;
	if (m_pFile != NULL)delete m_pFile;
}

void CCSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	CSocket::OnReceive(nErrorCode);
	m_pDlg->OnRecieve(this);
}

void CCSocket::Initialize()
{
	m_pFile = new CSocketFile(this,TRUE);
	m_pArchiveIn = new CArchive(m_pFile, CArchive::load);
	m_pArchiveOut = new CArchive(m_pFile, CArchive::store);
}

void CCSocket::SendMessage(CMsg* pMsg)
{
	if (m_pArchiveOut != NULL)
	{
		pMsg->Serialize(*m_pArchiveOut);
		m_pArchiveOut->Flush();
	}
}

void CCSocket::ReceiveMessage(CMsg* pMsg)
{
	pMsg->Serialize(*m_pArchiveIn);
}
IMPLEMENT_DYNAMIC(CCSocket,CSocket)