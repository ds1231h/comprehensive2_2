// MyText.cpp : implementation file
//

#include "stdafx.h"
#include "comprehensive2_2.h"
#include "MyText.h"
#include "afxdialogex.h"


// MyText dialog

IMPLEMENT_DYNAMIC(MyText, CDialogEx)

MyText::MyText(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyText::IDD, pParent)
	, Text(_T(""))
{

}

MyText::~MyText()
{
}

void MyText::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Text);
}


BEGIN_MESSAGE_MAP(MyText, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyText::OnBnClickedOk)
END_MESSAGE_MAP()


// MyText message handlers


void MyText::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(Text);		
 	//new MyCtext(NULL, Text);
	CDialogEx::OnOK();
}
