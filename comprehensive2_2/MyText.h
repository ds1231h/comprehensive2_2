#pragma once
#include "fig.h"

// MyText dialog

class MyText : public CDialogEx
{
	DECLARE_DYNAMIC(MyText)

public:
	MyText(CWnd* pParent = NULL);   // standard constructor
	virtual ~MyText();

// Dialog Data
	enum { IDD = IDD_TEXT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString Text;
	afx_msg void OnBnClickedOk();
};
