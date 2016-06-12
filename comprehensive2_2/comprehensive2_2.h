
// comprehensive2_2.h : main header file for the comprehensive2_2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Ccomprehensive2_2App:
// See comprehensive2_2.cpp for the implementation of this class
//

class Ccomprehensive2_2App : public CWinAppEx
{
public:
	Ccomprehensive2_2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccomprehensive2_2App theApp;
