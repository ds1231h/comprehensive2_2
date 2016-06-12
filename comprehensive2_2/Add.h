#pragma once


// Add dialog

class Add : public CDialogEx
{
	DECLARE_DYNAMIC(Add)

public:
	Add(CWnd* pParent = NULL);   // standard constructor
	virtual ~Add();

// Dialog Data
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double Add1;
	double Add2;
	double Result;
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
