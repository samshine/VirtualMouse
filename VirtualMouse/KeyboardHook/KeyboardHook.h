// KeyboardHook.h : KeyboardHook DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#define DllExport __declspec(dllexport)


// CKeyboardHookApp
// �йش���ʵ�ֵ���Ϣ������� KeyboardHook.cpp
//


class CKeyboardHookApp : public CWinApp
{
public:
	CKeyboardHookApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

DllExport void WINAPI InstallKbHook(HWND hWnd,UINT msg);