// SecondDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "SecondDlg.h"
#include "afxdialogex.h"


// CSecondDlg dialog

IMPLEMENT_DYNAMIC(CSecondDlg, CDialog)

CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSecondDlg::IDD, pParent)
{

}

CSecondDlg::~CSecondDlg()
{
}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondDlg, CDialog)
END_MESSAGE_MAP()

// CSecondDlg dialog

//CATMDlg constructor
CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSecondDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//CATMDlg thing
void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSecondDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CSecondDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CSecondDlg::OnBnClickedCancel)
    ON_WM_CREATE()
END_MESSAGE_MAP()


// CSecondDlg message handlers


