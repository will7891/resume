// ATMSavingsAccount.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMSavingsAccount.h"
#include "afxdialogex.h"

#include "ATMAmount.h"////////////////////
// CATMSavingsAccount dialog

IMPLEMENT_DYNAMIC(CATMSavingsAccount, CDialogEx)

CATMSavingsAccount::CATMSavingsAccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATMSavingsAccount::IDD, pParent)
{

}

CATMSavingsAccount::~CATMSavingsAccount()
{
}

void CATMSavingsAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CATMSavingsAccount, CDialogEx)
        ON_BN_CLICKED(IDC_BUTTON1, &CATMSavingsAccount::OnBnClickedButton1)
END_MESSAGE_MAP()


// CATMSavingsAccount message handlers
BOOL CATMSavingsAccount::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    return TRUE;
}

void CATMSavingsAccount::OnBnClickedButton1()
{





}
