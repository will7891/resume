// ATMCheckingAccount.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMCheckingAccount.h"
#include "afxdialogex.h"


// CATMCheckingAccount dialog

IMPLEMENT_DYNAMIC(CATMCheckingAccount, CDialogEx)

CATMCheckingAccount::CATMCheckingAccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATMCheckingAccount::IDD, pParent)
{

}

CATMCheckingAccount::~CATMCheckingAccount()
{
}

void CATMCheckingAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CATMCheckingAccount, CDialogEx)
END_MESSAGE_MAP()


// CATMCheckingAccount message handlers
