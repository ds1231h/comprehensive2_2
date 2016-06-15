#include "stdafx.h"
#include "fig.h"

// 构造
MyCline::MyCline(CPoint m_S, CPoint m_E, COLORREF m_Pc)
{
	m_ptS = m_S;
	m_ptE = m_E;
	m_LC = m_Pc;
	m_type = DRAW_LINE;
};

// 实现
void MyCline::draw(CDC* pDC)
{
	CPen pen;
	CPen* pPen;
	pen.CreatePen(PS_SOLID, 2, m_LC);
	pPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_ptS);
	pDC->LineTo(m_ptE);
	pDC->SelectObject(pPen);
	pen.DeleteObject();
	pPen->DeleteObject();
}

void MyCline::save(CArchive& ar)
{
	ar << m_ptS << m_ptE << m_LC;
}

void MyCline::load(CArchive& ar)
{
	ar >> m_ptS >> m_ptE >> m_LC;
}

// 构造
MyCrect::MyCrect(CPoint m_S, CPoint m_E, COLORREF m_Pc, COLORREF m_BRc)
{
	m_ptS = m_S;
	m_ptE = m_E;
	m_LC = m_Pc;
	m_BC = m_BRc;
	m_type = DRAW_RECT;
};

// 实现
void MyCrect::draw(CDC* pDC)
{
	CPen pen;
	CPen* pPen;
	pen.CreatePen(PS_SOLID, 2, m_LC);
	pPen = pDC->SelectObject(&pen);
	CBrush brush;
	CBrush* pBrush;
	brush.CreateSolidBrush(m_BC);
	pBrush = pDC->SelectObject(&brush);
	pDC->Rectangle(m_ptS.x, m_ptS.y, m_ptE.x, m_ptE.y);
	pDC->SelectObject(pPen);
	pen.DeleteObject();
	pPen->DeleteObject();
	pDC->SelectObject(pBrush);
	brush.DeleteObject();
	pBrush->DeleteObject();
}

void MyCrect::save(CArchive& ar)
{
	ar << m_ptS << m_ptE << m_LC << m_BC;
}

void MyCrect::load(CArchive& ar)
{
	ar >> m_ptS >> m_ptE >> m_LC >> m_BC;
}

// 构造
MyCtext::MyCtext(CPoint m_S, CString szBuf, LOGFONT lf)
{
	m_ptS = m_S;
	m_szBuf = szBuf;
	m_type = DRAW_TEXT;
	m_f = lf;
};

// 实现
void MyCtext::draw(CDC* pDC)
{
	CFont m_font;
	CFont *pm_ft;
	m_font.CreateFontIndirect(&m_f);
	pm_ft = pDC->SelectObject(&m_font);
	pDC->TextOutW(m_ptS.x,m_ptS.y, m_szBuf);
	pDC->SelectObject(pm_ft);
	m_font.DeleteObject();
	pm_ft->DeleteObject();
}

void MyCtext::save(CArchive& ar)
{
	ar << m_ptS << m_szBuf << m_f.lfCharSet << m_f.lfCharSet << m_f.lfEscapement
		<< m_f.lfHeight << m_f.lfItalic << m_f.lfOrientation<<
		m_f.lfOutPrecision << m_f.lfPitchAndFamily << m_f.lfQuality << m_f.lfStrikeOut
		<< m_f.lfUnderline << m_f.lfWeight << m_f.lfWidth;
}

void MyCtext::load(CArchive& ar)
{
	ar >> m_ptS >> m_szBuf>> m_f.lfCharSet >> m_f.lfCharSet >> m_f.lfEscapement
		>> m_f.lfHeight >> m_f.lfItalic >> m_f.lfOrientation>>
		m_f.lfOutPrecision >> m_f.lfPitchAndFamily >> m_f.lfQuality >> m_f.lfStrikeOut
		>> m_f.lfUnderline >> m_f.lfWeight >> m_f.lfWidth;
}