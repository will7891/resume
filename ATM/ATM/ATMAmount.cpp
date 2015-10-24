// ATMAmount.cpp : implementation file
//  retrieves amount for transaction
//  requires ATMDlg::savings/checking to check if amount is too large
//           ATMAccount::isSavings/isChecking to determine which account to check
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMAmount.h"
#include "afxdialogex.h"

#include "ATMDlg.h"     // for checking amount w/ current savings/checking
#include "ATMMainMenu.h"// for determining which account to check on

//// CATMAmount dialog \\\\

// Smthg that's req'd
IMPLEMENT_DYNAMIC(CATMAmount, CDialogEx)

// standard constructor
CATMAmount::CATMAmount(CWnd* pParent /*=NULL*/): CDialogEx(CATMAmount::IDD, pParent) {}

// standard destructor
CATMAmount::~CATMAmount() {}

// doDataExchange
void CATMAmount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

// Message maps
BEGIN_MESSAGE_MAP(CATMAmount, CDialogEx)
    ON_BN_CLICKED(IDOK, &CATMAmount::OnBnClickedOk)
    ON_EN_CHANGE(IDC_EDIT1, &CATMAmount::OnEnChangeEdit1)
    ON_BN_CLICKED(IDCANCEL, &CATMAmount::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON1, &CATMAmount::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CATMAmount::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CATMAmount::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON6, &CATMAmount::OnBnClickedButton6)
    ON_BN_CLICKED(IDC_BUTTON4, &CATMAmount::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &CATMAmount::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON7, &CATMAmount::OnBnClickedButton7)
    ON_BN_CLICKED(IDC_BUTTON8, &CATMAmount::OnBnClickedButton8)
    ON_BN_CLICKED(IDC_BUTTON9, &CATMAmount::OnBnClickedButton9)
    ON_BN_CLICKED(IDC_BUTTON10, &CATMAmount::OnBnClickedButton10)
END_MESSAGE_MAP()


//// CATMAmount message handlers \\\\

// Initialize Dlg
BOOL CATMAmount::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// customize Dlg
      // set caption and background
      SetWindowText(_T("Enter Amount"));    // set caption Dlg
      SetBackgroundColor(RGB(120,0,120));   // purple

      // default '$0.00' to view
      CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
      pEdit->SetWindowText("0.00");

	return TRUE;  // return TRUE  unless you set the focus to a control
} // ReadConvertWrite


// Reads view, converts amount to new #, writes to view (called by button1-10)
void CATMAmount::ReadConvertWrite(int multiplier)
{
    // get amount from view
    CString amount;
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
    pEdit->GetWindowText(amount);
    double num = _ttof(amount);

    // convert num accounting for new # (multiplier)
    if (num < .01)                 // if multiplier is 1st non-zero # punched in
      if (multiplier == 0) return; //   and is 0 -> do nothing
      else num = .01 * multiplier; //   otherwise amount is between $.01 and $.09
    else num = (num * 10) + (.01 * multiplier); // do conversion

    // reformat amount, set window
    amount.Format(("%.*f"), CATMApp::setp, num);
    pEdit->SetWindowText(amount);
}

// Get amount, message user if amount is too great
void CATMAmount::OnBnClickedOk()
{
    // get amount
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
    pEdit->GetWindowText(booleans::amt);

    // check if amt > money in account (for Get Cash and Transfer only)
    if (!booleans::deposit)
    {
        if (booleans::Savings)//CATMAccount::isSavings)
        {
            if (_ttof(booleans::amt) > _ttof(CATMDlg::savings))
                {MessageBox(CString("Not enough in savings")); return;}           
        }
        else if (booleans::Checking)//CATMAccount::isChecking)
        {
            if (_ttof(booleans::amt) > _ttof(CATMDlg::checking))
                {MessageBox(CString("Not enough in checking")); return;}           
        }
    }

    CDialogEx::OnOK(); // exit this Dlg
} // OnBnClickedOk

void CATMAmount::OnBnClickedButton10() {ReadConvertWrite(0);}
void CATMAmount::OnBnClickedButton1()  {ReadConvertWrite(1);}
void CATMAmount::OnBnClickedButton2()  {ReadConvertWrite(2);}
void CATMAmount::OnBnClickedButton3()  {ReadConvertWrite(3);}
void CATMAmount::OnBnClickedButton4()  {ReadConvertWrite(4);}
void CATMAmount::OnBnClickedButton5()  {ReadConvertWrite(5);}
void CATMAmount::OnBnClickedButton6()  {ReadConvertWrite(6);}
void CATMAmount::OnBnClickedButton7()  {ReadConvertWrite(7);}
void CATMAmount::OnBnClickedButton8()  {ReadConvertWrite(8);}
void CATMAmount::OnBnClickedButton9()  {ReadConvertWrite(9);}
void CATMAmount::OnEnChangeEdit1()     {}
void CATMAmount::OnBnClickedCancel()   {CDialogEx::OnCancel();}
