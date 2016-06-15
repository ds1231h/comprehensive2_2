#ifndef _FIG_H_
#define _FIG_H_

#include <windows.h>
#include "stdafx.h"

class CFIG
{
public:
	virtual void draw(CDC */*pDC*/) = 0; //��ʾ�������ʵ�ֽӿ�
	virtual void save(CArchive &ar) = 0;
	virtual void load(CArchive &ar) = 0;
	int m_type;

protected:

	POINT m_ptS;
	POINT m_ptE;
	CString m_szBuf;
	COLORREF m_LC; // ��ɫ
	COLORREF m_BC; // ˢɫ
	LOGFONT m_f;
	// HFONT m_font;
	static CONST int DRAW_LINE = 1;
	static CONST int DRAW_RECT = 2;
	static CONST int DRAW_TEXT = 3;
};

class MyCline:public CFIG
{
public:
	MyCline(CPoint, CPoint, COLORREF);
	MyCline(){};
	void draw(CDC */*pDC*/);
	void save(CArchive &ar);
	void load(CArchive &ar);
};


class MyCrect:public CFIG
{
public:
	MyCrect(CPoint, CPoint, COLORREF, COLORREF);
	MyCrect(){};
	void draw(CDC */*pDC*/);
	void save(CArchive &ar);
	void load(CArchive &ar);
};

class MyCtext:public CFIG
{
public:
	// MyCtext(CPoint, CString, CFont*);
	MyCtext(CPoint, CString, LOGFONT);
	MyCtext(){};
	void draw(CDC */*pDC*/);
	void save(CArchive &ar);
	void load(CArchive &ar);
};

#endif
