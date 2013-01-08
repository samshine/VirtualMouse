// VMouseDlg.h : ͷ�ļ�
//

#pragma once
#include "Ntray.h"


// CVMouseDlg �Ի���
class CVMouseDlg : public CDialog
{
// ����
public:
	CVMouseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VMOUSE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CTrayNotifyIcon m_trayIcon;
	
	// ����ģʽ
	BOOL m_bActive;
	// ����ģʽ
	BOOL m_bScrollPressed;
	// ����ģʽ
	BOOL m_bLocked;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	LRESULT OnTrayNotification( WPARAM wParam, LPARAM lParam );
	afx_msg LRESULT OnKeyEvent(WPARAM wParam,LPARAM lParam);
	afx_msg void OnTrayShow();
	afx_msg void OnTrayExit();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnBnClickedHide();
};
