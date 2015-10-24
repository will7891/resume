// ATMAcctActy.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMAcctActy.h"
#include "afxdialogex.h"

#include <vector>
using namespace std;

//// CATMAcctActy dialog \\\\

IMPLEMENT_DYNAMIC(CATMAcctActy, CDialogEx)

// constructor
CATMAcctActy::CATMAcctActy(vector<CString>& act, CWnd* pParent /*=NULL*/)
	: CDialogEx(CATMAcctActy::IDD, pParent)
{
    activity = act;
    currentIndex = 0;
    actPrint = "";
}

// destructor
CATMAcctActy::~CATMAcctActy() {}

// DoDataExchange
void CATMAcctActy::DoDataExchange(CDataExchange* pDX) {CDialogEx::DoDataExchange(pDX);}

// Message maps
BEGIN_MESSAGE_MAP(CATMAcctActy, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &CATMAcctActy::OnBnClickedButton1)
END_MESSAGE_MAP()


//// CATMAcctActy message handlers \\\\

// Initialize Dlg, show 1st 10 transactions
BOOL CATMAcctActy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Customize Dlg
    SetWindowText(_T("Account Activity")); // set caption Dlg
    SetBackgroundColor(RGB(40,40,40));     // gray-navy

    // display first 10 transactions
    CEdit* p = (CEdit*)GetDlgItem(IDC_EDIT1);
    for (; currentIndex < activity.size() && currentIndex < 10; currentIndex++)
      {actPrint += activity[currentIndex]; actPrint+= "\r\n";}
    p->SetWindowText(actPrint);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CATMAcctActy::OnBnClickedButton1() // show 10 more
{
    // reached end of vector
    if (activity.size() - 1 <= currentIndex) return;

    // print up to 10 more transactions    
    CEdit* p = (CEdit*)GetDlgItem(IDC_EDIT1);
    unsigned int limit = currentIndex + 10;
    for (; currentIndex < activity.size() && currentIndex < limit; currentIndex++)
      {actPrint += activity[currentIndex]; actPrint += "\r\n";}
    p->SetWindowText(actPrint);
}

void CATMAcctActy::OnBnClickedOk() {CDialogEx::OnOK();}