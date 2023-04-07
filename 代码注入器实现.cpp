// CodeInjectDlg.cpp : ʵ���ļ�
//
 
#include "stdafx.h"
#include "CodeInject.h"
#include "CodeInjectDlg.h"
#include "ProcessDlg.h"
 
 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
 
 
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
 
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
 
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };
 
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
 
// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};
 
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}
 
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
 
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()
 
 
// CCodeInjectDlg �Ի���
 
 
 
 
CCodeInjectDlg::CCodeInjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodeInjectDlg::IDD, pParent)
	, m_strPid(_T(""))
	, m_strProcessName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_dwPid = 0;
}
 
void CCodeInjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PID, m_strPid);
	DDX_Text(pDX, IDC_EDIT_PROCESSNAME, m_strProcessName);
	DDX_Control(pDX, IDC_RICHEDIT21, m_reAsmCode);
}
 
BEGIN_MESSAGE_MAP(CCodeInjectDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, OnToolTip)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_PROCESS, &CCodeInjectDlg::OnBnClickedButtonProcess)
	ON_BN_CLICKED(IDC_BUTTON_INJECT, &CCodeInjectDlg::OnBnClickedButtonInject)
END_MESSAGE_MAP()
 
 
// CCodeInjectDlg ��Ϣ�������
 
BOOL CCodeInjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
 
	// ��������...���˵�����ӵ�ϵͳ�˵��С�
 
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
 
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
 
	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
 
 
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	EnableToolTips(TRUE);
 
	// ���ð�ťͼƬ
	HICON hIcon = (HICON)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDI_ICON_PROCESS),
		IMAGE_ICON,
		16,
		16,
		LR_DEFAULTCOLOR);
 
	((CButton*)GetDlgItem(IDC_BUTTON_PROCESS))->SetIcon(hIcon);
 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
 
void CCodeInjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}
 
// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�
 
void CCodeInjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
 
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
 
		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
 
		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
 
//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CCodeInjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
 
BOOL CCodeInjectDlg::OnToolTip( UINT id,NMHDR *pNMHDR,LRESULT *pResult )
{
	TOOLTIPTEXT *pTTT = (TOOLTIPTEXT*)pNMHDR;
	HWND hWnd = (HWND)pNMHDR->idFrom;
	int nID = 0;
	if (pTTT->uFlags & TTF_IDISHWND)
		nID = ::GetDlgCtrlID(hWnd);
 
	if (nID == 0)
		return FALSE;
 
	switch (nID)
	{
	case IDC_BUTTON_PROCESS:
		pTTT->lpszText = _T("ѡ��Ŀ�����");
		break;
	}
 
	return TRUE;
}
 
void CCodeInjectDlg::OnBnClickedButtonProcess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CProcessDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_strProcessName = dlg.m_strProcessName;
		m_strPid = dlg.m_strPid;
		int nFind1 = m_strPid.Find('[');
		int nFind2 = m_strPid.Find(']');
		if (nFind2 > 0)
		{
			CString str = m_strPid.Mid(nFind1 + 1, nFind2 - nFind1 - 1);
			m_dwPid = _ttoi(str);
		}
		UpdateData(FALSE);
	}
}
 
void CCodeInjectDlg::OnBnClickedButtonInject()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_dwPid == 0)
		return;
 
	int nMaxCmdSize = (m_reAsmCode.GetLineCount() + 1) * MAXCMDSIZE; //���������ڴ��С
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPid);
	PVOID pLibRemote = ::VirtualAllocEx(hProcess, NULL, nMaxCmdSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	DWORD dwStartAddr = (DWORD)(PDWORD)pLibRemote;
 
	t_asmmodel am;
	memset(&am, 0, sizeof(am));
	TCHAR *pBuf;
	int nLineLength;
	bool bOK = true;
	for (int i = 0; i < m_reAsmCode.GetLineCount(); i++)
	{
		nLineLength = m_reAsmCode.LineLength(i);
		if (nLineLength == 0)
			continue;
 
		pBuf = new TCHAR[nLineLength + 4];
		m_reAsmCode.GetLine(i, pBuf, nLineLength + 4);
 
		if (Asm2Machinecode(pBuf, dwStartAddr, &am)) //���ת������
		{
			::WriteProcessMemory(hProcess, (void*)dwStartAddr, (void*)am.code, am.length, NULL);
			dwStartAddr += am.length;
		}
		else
			bOK = false;
 
		delete []pBuf;
	}
	
	Asm2Machinecode(_T("xor eax,eax"), dwStartAddr, &am);
	::WriteProcessMemory(hProcess, (void*)dwStartAddr, (void*)am.code, am.length, NULL);
	dwStartAddr += am.length;
	Asm2Machinecode(_T("retn 0"), dwStartAddr, &am);
	::WriteProcessMemory(hProcess, (void*)dwStartAddr, (void*)am.code, am.length, NULL);
 
	if (bOK)
	{
		HANDLE hThread;
		CString strThreadAddr;
		hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pLibRemote, NULL, 0, 0);
		strThreadAddr.Format(_T("%08X"), pLibRemote);
		SetDlgItemText(IDC_EDIT_THREADADDR, strThreadAddr);
		CloseHandle(hThread);
	}
	else
	{
		AfxMessageBox(_T("��������"));
	}
	::VirtualFreeEx(hProcess, pLibRemote, nMaxCmdSize, MEM_RELEASE);
	CloseHandle(hProcess);
}
 
bool CCodeInjectDlg::Asm2Machinecode(char* pAsmcode, DWORD dwAddrress, __out t_asmmodel* pMachinecode)
{
	bool bResult;
	char errtext[TEXTLEN];
	Assemble(pAsmcode,dwAddrress,pMachinecode,0,0,errtext);
	bResult = pMachinecode->length > 0;
 
	return bResult;
}
 
bool CCodeInjectDlg::Asm2Machinecode(TCHAR* pSrcAsmcode, DWORD dwAddrress, __out t_asmmodel* pMachinecode)
{
	bool bResult;
	char errtext[TEXTLEN];
 
	//UnicodeתAnsi
	int nLen = WideCharToMultiByte(CP_OEMCP, 0, pSrcAsmcode, -1, NULL, 0, NULL, FALSE);
	char* pAsmcode = new char[nLen];
	WideCharToMultiByte(CP_OEMCP, 0, pSrcAsmcode, -1, pAsmcode, nLen, NULL, FALSE);
	//=====================================================================================
	for (size_t i = 0; i < strlen(pAsmcode); i++)
	{
		if (pAsmcode[i] == '\r' || pAsmcode[i] == '\n')
			pAsmcode[i] = 0;
	}
	Assemble(pAsmcode,dwAddrress,pMachinecode,0,0,errtext);
	//TRACE(pAsmcode);
	delete []pAsmcode;
	bResult = pMachinecode->length > 0;
 
	return bResult;
}
