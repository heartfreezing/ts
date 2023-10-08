#include "pch.h"
#include "CMsg.h"
CMsg::CMsg()
{
	m_strText = _T("");
	m_bClose=FALSE;
}
CMsg::~CMsg()
{
}
void CMsg::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)m_bClose;
		ar << m_strText;
	}
	else {
		WORD wd;
		ar >> wd;
		m_bClose = (BOOL)wd;
		ar >> m_strText;
	}
}
IMPLEMENT_DYNAMIC(CMsg,CObject)
