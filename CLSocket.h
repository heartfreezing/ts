
#include <afxsock.h>
#include "tsDlg.h"
class CTsDlg;

class CLSocket :public CSocket
{
    DECLARE_DYNAMIC(CLSocket);
public:
    CLSocket(CtsDlg* pDlg);
    virtual ~CLSocket();

public:
    CtsDlg* m_pDlg;

protected:
    virtual void OnAccept(int nErrorCode);
};
// !defined(AFX_LSOCKET_H_INCLUDED_)
