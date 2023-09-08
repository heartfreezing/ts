#pragma once
#include <afxsock.h>
#include "tsDlg.h"
class CCSocket :
    public CSocket
{
public:
    CtsDlg* m_pDlg;
    CSocketFile* m_pFile;
    CArchive* m_pArchiveIn;
    CArchive* m_pArchiveOut;
    virtual void OnReceive(int nErrorCode);
    void Initialize();
    void SendMessage(CMsg* pMsg);
    void ReceiveMessage(CMsg* pMsg);
};

