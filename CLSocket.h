
#include <afxsock.h>
#include "tsDlg.h"
class CLSocket :
    public CSocket
{
public:
    CtsDlg* m_pDlg;
    virtual void OnAccept(int nErrorCode);
};
