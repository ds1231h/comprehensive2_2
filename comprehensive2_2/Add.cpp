// Add.cpp : implementation file
//

#include "stdafx.h"
#include "comprehensive2_2.h"
#include "Add.h"
#include "afxdialogex.h"


// Add dialog

IMPLEMENT_DYNAMIC(Add, CDialogEx)

Add::Add(CWnd* pParent /*=NULL*/)
	: CDialogEx(Add::IDD, pParent)
	, Add1(0)
	, Add2(0)
	, Result(0)
{

}

Add::~Add()
{
}

void Add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Add1);
	DDX_Text(pDX, IDC_EDIT2, Add2);
	DDX_Text(pDX, IDC_EDIT3, Result);
}


BEGIN_MESSAGE_MAP(Add, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Add::OnBnClickedButton1)
END_MESSAGE_MAP()


// Add message handlers


void Add::OnBnClickedButton1()
{
	UpdateData(TRUE);
	Result = Add1 + Add2;
	UpdateData(FALSE);
}
