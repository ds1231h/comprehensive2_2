
// comprehensive2_2View.h : interface of the Ccomprehensive2_2View class
//
#include "fig.h"
#include "Add.h"
#include "MyText.h"
#pragma once


class Ccomprehensive2_2View : public CView
{
protected: // create from serialization only
	Ccomprehensive2_2View();
	DECLARE_DYNCREATE(Ccomprehensive2_2View)

// Attributes
public:
	Ccomprehensive2_2Doc* GetDocument() const;

// Operations
protected:
	int *DrawMode;
	CFIG *p;
	CPoint m_s;
	CPoint m_e;
	CString szBuf;
	CFont m_font;
	DWORD *rgbCurrent;
	LOGFONT lf;
	COLORREF m_color;
	COLORREF m_Brcolor;

public:
	

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Ccomprehensive2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawText();
	afx_msg void OnCalculteAdd();
	afx_msg void OnUpdateDrawLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDrawText(CCmdUI *pCmdUI);
	afx_msg void OnPropertyLinecolor();
	afx_msg void OnPropertyPaintcolor();
	afx_msg void OnPropertyFont();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in comprehensive2_2View.cpp
inline Ccomprehensive2_2Doc* Ccomprehensive2_2View::GetDocument() const
   { return reinterpret_cast<Ccomprehensive2_2Doc*>(m_pDocument); }
#endif

