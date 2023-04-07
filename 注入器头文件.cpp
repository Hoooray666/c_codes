// CodeInjectDlg.h : 头文件
//
 
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "disasm.h"
 
 
// CCodeInjectDlg 对话框
class CCodeInjectDlg : public CDialog
{
// 构造
public:
	CCodeInjectDlg(CWnd* pParent = NULL);	// 标准构造函数
 
// 对话框数据
	enum { IDD = IDD_CODEINJECT_DIALOG };
 
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
 
 
// 实现
protected:
	HICON m_hIcon;
 
	// 生成的消息映射函数
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
