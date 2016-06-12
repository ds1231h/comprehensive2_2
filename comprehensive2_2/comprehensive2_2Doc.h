
// comprehensive2_2Doc.h : interface of the Ccomprehensive2_2Doc class
//

#include "fig.h"
#pragma once


class Ccomprehensive2_2Doc : public CDocument
{
protected: // create from serialization only
	Ccomprehensive2_2Doc();
	DECLARE_DYNCREATE(Ccomprehensive2_2Doc)

// Attributes
public:
	CArray <CFIG*, CFIG*> m_figures;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~Ccomprehensive2_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
