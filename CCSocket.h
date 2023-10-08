#pragma once
#include <afxsock.h>
#include "tsDlg.h"
class CTsDlg;
class CMsg;

class CCSocket : public CSocket
{
    DECLARE_DYNAMIC(CCSocket);
public:
    CCSocket(CtsDlg* pDlg);
    virtual ~CCSocket();
public:
    CtsDlg* m_pDlg;
    CSocketFile* m_pFile;
    CArchive* m_pArchiveIn;
    CArchive* m_pArchiveOut;
public:
    void Initialize();
    void SendMessage(CMsg* pMsg);
    void ReceiveMessage(CMsg* pMsg);

protected:
    virtual void OnReceive(int nErrorCode);
};

