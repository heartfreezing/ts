#pragma once
#include <afx.h>
class CMsg :
    public CObject
{
    DECLARE_DYNCREATE(CMsg);
public:
    CMsg();
    virtual ~CMsg();
public:
    CString m_strText;
    BOOL m_bClose;
public:
    virtual void Serialize(CArchive& ar);
};

