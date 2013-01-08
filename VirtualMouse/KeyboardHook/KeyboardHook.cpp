// KeyboardHook.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "KeyboardHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CKeyboardHookApp

BEGIN_MESSAGE_MAP(CKeyboardHookApp, CWinApp)
END_MESSAGE_MAP()


// CKeyboardHookApp ����

CKeyboardHookApp::CKeyboardHookApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CKeyboardHookApp ����

CKeyboardHookApp theApp;


// CKeyboardHookApp ��ʼ��


// void SaveLog(char* c)
// {
// 	CTime tm=CTime::GetCurrentTime();
// 	CString name;
// 	name.Format("c:\\Key_%d_%d.log",tm.GetMonth(),tm.GetDay());
// 	CFile file;
// 	if(!file.Open(name,CFile::modeReadWrite))
// 	{
// 		file.Open(name,CFile::modeCreate|CFile::modeReadWrite);
// 	}
// 	file.SeekToEnd();
// 	file.Write(c,1);
// 	file.Close();
// }
HHOOK g_hHook = NULL;
HWND g_hWnd = NULL;
UINT g_nMsg = 0;
BOOL g_bActive = FALSE;

LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)
{
	if(nCode==HC_ACTION)
	{
		if(SendMessage(g_hWnd,g_nMsg,wParam,lParam) != 0)
		{
			return 1;
		}
	}
 	return CallNextHookEx(g_hHook,nCode,wParam,lParam);
}
DllExport void WINAPI InstallKbHook(HWND hWnd,UINT msg)
{
	g_hHook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)LauncherHook,theApp.m_hInstance,0);

	g_hWnd = hWnd;
	g_nMsg = msg;
}

BOOL CKeyboardHookApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}

int CKeyboardHookApp::ExitInstance()
{
	if (g_hHook != NULL)
	{
		UnhookWindowsHookEx(g_hHook);
	}

	return CWinApp::ExitInstance();
}
