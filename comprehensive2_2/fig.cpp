#include "stdafx.h"
#include "fig.h"

// ����
MyCline::MyCline(CPoint m_S, CPoint m_E)
{
	m_ptS = m_S;
	m_ptE = m_E;
	m_type = DRAW_LINE;
};

// ʵ��
void MyCline::draw(CDC* pDC)
{
	pDC->MoveTo(m_ptS);
	pDC->LineTo(m_ptE);
}

void MyCline::save(CArchive& ar)
{
	ar << m_ptS << m_ptE;
}

void MyCline::load(CArchive& ar)
{
	ar >> m_ptS >> m_ptE;
}

// ����
MyCrect::MyCrect(CPoint m_S, CPoint m_E)
{
	m_ptS = m_S;
	m_ptE = m_E;
	m_type = DRAW_RECT;
};

// ʵ��
void MyCrect::draw(CDC* pDC)
{
	pDC->Rectangle(m_ptS.x, m_ptS.y, m_ptE.x, m_ptE.y);
}

void MyCrect::save(CArchive& ar)
{
	ar << m_ptS << m_ptE;
}

void MyCrect::load(CArchive& ar)
{
	ar >> m_ptS >> m_ptE;
}

// ����
MyCtext::MyCtext(CPoint m_S, CString szBuf)
{
	m_ptS = m_S;
	m_szBuf = szBuf;
	m_type = DRAW_RECT;
};

// ʵ��
void MyCtext::draw(CDC* pDC)
{
	CString a;
	// ���ַ���ӡ�ڿͻ���
	pDC->TextOutW(m_ptS.x,m_ptS.y, m_szBuf);
}

void MyCtext::save(CArchive& ar)
{
	ar << m_ptS << m_ptE;
}

void MyCtext::load(CArchive& ar)
{
	ar >> m_ptS >> m_ptE;
}