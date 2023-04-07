// CodeInjectDlg.h : ͷ�ļ�
//
 
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "disasm.h"
 
 
// CCodeInjectDlg �Ի���
class CCodeInjectDlg : public CDialog
{
// ����
public:
	CCodeInjectDlg(CWnd* pParent = NULL);	// ��׼���캯��
 
// �Ի�������
	enum { IDD = IDD_CODEINJECT_DIALOG };
 
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
 
 
// ʵ��
protected:
	HICON m_hIcon;
 
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnToolTip(UINT id,NMHDR *pNMHDR,LRESULT *pResult);
	afx_msg void OnBnClickedButtonProcess();
	DECLARE_MESSAGE_MAP()
public:
	DWORD m_dwPid;
	CString m_strPid;
	CString m_strProcessName;
	afx_msg void OnBnClickedButtonInject();
	CRichEditCtrl m_reAsmCode;
	bool Asm2Machinecode(char* pAsmcode, DWORD dwAddrress, __out t_asmmodel* pMachinecode);
	bool Asm2Machinecode(TCHAR* pSrcAsmcode, DWORD dwAddrress, __out t_asmmodel* pMachinecode);
};
