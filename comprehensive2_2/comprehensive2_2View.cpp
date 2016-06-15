
// comprehensive2_2View.cpp : implementation of the Ccomprehensive2_2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "comprehensive2_2.h"
#endif

#include "comprehensive2_2Doc.h"
#include "comprehensive2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccomprehensive2_2View

IMPLEMENT_DYNCREATE(Ccomprehensive2_2View, CView)

BEGIN_MESSAGE_MAP(Ccomprehensive2_2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ccomprehensive2_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_LINE, &Ccomprehensive2_2View::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &Ccomprehensive2_2View::OnDrawRect)
	ON_COMMAND(ID_DRAW_TEXT, &Ccomprehensive2_2View::OnDrawText)
	ON_COMMAND(ID_CALCULTE_ADD, &Ccomprehensive2_2View::OnCalculteAdd)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &Ccomprehensive2_2View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &Ccomprehensive2_2View::OnUpdateDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TEXT, &Ccomprehensive2_2View::OnUpdateDrawText)
	ON_COMMAND(ID_PROPERTY_LINECOLOR, &Ccomprehensive2_2View::OnPropertyLinecolor)
	ON_COMMAND(ID_PROPERTY_PAINTCOLOR, &Ccomprehensive2_2View::OnPropertyPaintcolor)
	ON_COMMAND(ID_PROPERTY_FONT, &Ccomprehensive2_2View::OnPropertyFont)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Ccomprehensive2_2View construction/destruction

Ccomprehensive2_2View::Ccomprehensive2_2View()
{
	DrawMode = new int;
	*DrawMode = 1;
	p = nullptr;
	m_Brcolor = RGB(255, 255, 255);
}

Ccomprehensive2_2View::~Ccomprehensive2_2View()
{
	delete DrawMode;
}

BOOL Ccomprehensive2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Ccomprehensive2_2View drawing

void Ccomprehensive2_2View::OnDraw(CDC* pDC)
{
	Ccomprehensive2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < pDoc->m_figures.GetSize(); i++)
	{
		int a = pDoc->m_figures.GetSize();
		pDoc->m_figures[i]->draw(pDC);
	}
}


// Ccomprehensive2_2View printing


void Ccomprehensive2_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ccomprehensive2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Ccomprehensive2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Ccomprehensive2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Ccomprehensive2_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ccomprehensive2_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ccomprehensive2_2View diagnostics

#ifdef _DEBUG
void Ccomprehensive2_2View::AssertValid() const
{
	CView::AssertValid();
}

void Ccomprehensive2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ccomprehensive2_2Doc* Ccomprehensive2_2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ccomprehensive2_2Doc)));
	return (Ccomprehensive2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Ccomprehensive2_2View message handlers


void Ccomprehensive2_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_s = point;

	CView::OnLButtonDown(nFlags, point);
}


void Ccomprehensive2_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_e = point;

	switch(*DrawMode)
	{
	case 1:
		p = new MyCline(m_s, m_e, m_color);
		break;

	case 2:
		p = new MyCrect(m_s, m_e, m_color, m_Brcolor);;
		break;

	case 3:
		MyText text;
		if (text.DoModal() == IDOK)
		{
			szBuf = text.Text; // 先声明类对象，再用对象去访问另一个类定义的变量
			p = new MyCtext(m_s, szBuf, lf);
		}
		break;
	}

	if (p != NULL)
	{
		GetDocument()->m_figures.Add(p);
		InvalidateRect(NULL);
	}

	CView::OnLButtonUp(nFlags, point);
}


void Ccomprehensive2_2View::OnDrawLine()
{
	*DrawMode = 1;
}


void Ccomprehensive2_2View::OnDrawRect()
{
	*DrawMode = 2;
}


void Ccomprehensive2_2View::OnDrawText()
{
	*DrawMode = 3;
}


void Ccomprehensive2_2View::OnCalculteAdd()
{
	Add add;
	add.DoModal();
}


void Ccomprehensive2_2View::OnUpdateDrawLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(*DrawMode == 1);
}


void Ccomprehensive2_2View::OnUpdateDrawRect(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(*DrawMode == 2);
}


void Ccomprehensive2_2View::OnUpdateDrawText(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(*DrawMode == 3);
}


void Ccomprehensive2_2View::OnPropertyLinecolor()
{
	COLORREF color = RGB(255, 0, 0); 
	CColorDialog colorDlg(color);         // 构造颜色对话框，传入初始颜色值   

	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
	{   
		color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值    
		m_color = color;
	}
}


void Ccomprehensive2_2View::OnPropertyPaintcolor()
{
	COLORREF color = RGB(255, 0, 0); 
	CColorDialog colorDlg(color);         // 构造颜色对话框，传入初始颜色值   

	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
	{   
		color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值    
		m_Brcolor = color;
	}
}


void Ccomprehensive2_2View::OnPropertyFont()
{
	// LOGFONT lf;

	memset(&lf, 0, sizeof(LOGFONT)); // 将lf所有字节清零
	// 构造字体对话框，初始选择字体名为“宋体”
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T("宋体"));
	CFontDialog fontDlg(&lf);

	if (IDOK != fontDlg.DoModal())
	{
		return ;
	}
}


void Ccomprehensive2_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
// 	CMenu m,*pm;
// 	if(!m.LoadMenu(IDR_POPUP_EDIT)) MessageBox(_T("err"));
// 	pm=m.GetSubMenu(0);
// 	GetCursorPos(&point);
// 	pm->TrackPopupMenu(TPM_LEFTALIGN,point.x, point.y, this);
}
