
// comprehensive2_2Doc.cpp : implementation of the Ccomprehensive2_2Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "comprehensive2_2.h"
#endif

#include "comprehensive2_2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ccomprehensive2_2Doc

IMPLEMENT_DYNCREATE(Ccomprehensive2_2Doc, CDocument)

BEGIN_MESSAGE_MAP(Ccomprehensive2_2Doc, CDocument)
END_MESSAGE_MAP()


// Ccomprehensive2_2Doc construction/destruction

Ccomprehensive2_2Doc::Ccomprehensive2_2Doc()
{
	// TODO: add one-time construction code here

}

Ccomprehensive2_2Doc::~Ccomprehensive2_2Doc()
{
	for (int i = 0; i < m_figures.GetSize(); i++)
		delete m_figures[i];
}

BOOL Ccomprehensive2_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Ccomprehensive2_2Doc serialization

void Ccomprehensive2_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_figures.GetSize();
		for (int i = 0; i < m_figures.GetSize(); i++)
		{
			ar << m_figures[i]->m_type;
			m_figures[i]->save(ar);
		}
	}
	else
	{
		int iCount = 0;
		ar >> iCount;
		for (int i = 0; i < iCount; i++)
		{
			int iType; 	CFIG *p = NULL;
			ar >> iType;
			switch (iType)
			{
			case 1: p = new MyCline();	break; // »­Ïß
			case 2: p = new MyCrect();	break; // »­¾ØÐÎ
				break;
			}
			if (p!= NULL){
				p->load(ar);
				m_figures.Add(p);
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void Ccomprehensive2_2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void Ccomprehensive2_2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Ccomprehensive2_2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Ccomprehensive2_2Doc diagnostics

#ifdef _DEBUG
void Ccomprehensive2_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ccomprehensive2_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ccomprehensive2_2Doc commands
