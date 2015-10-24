// ATMSavingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMSavingsDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"///////????????/

// ATMSavingsDlg dialog

IMPLEMENT_DYNAMIC(ATMSavingsDlg, CDialog)

ATMSavingsDlg::ATMSavingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ATMSavingsDlg::IDD, pParent)
{

}

ATMSavingsDlg::~ATMSavingsDlg()
{
}

void ATMSavingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ATMSavingsDlg, CDialog)
    ON_BN_CLICKED(IDOK, &ATMSavingsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ATMSavingsDlg message handlers


void ATMSavingsDlg::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialog::OnOK();
}
