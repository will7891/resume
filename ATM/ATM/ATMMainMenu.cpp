// ATMMainMenu.cpp : implementation file
// ***all the account modifications happen here***
// displays menu of options
//


#include "stdafx.h"
#include "ATM.h"
#include "ATMMainMenu.h"
#include "afxdialogex.h"

#include "ATMDlg.h"     // to access CString savings/checking + vector<CString> statements
#include "ATMAccount.h" // to call CATMAcountDlg's
#include "ATMAcctActy.h"// to call CATMAcctActyDlg for printing record of transactions

//// CATMMainMenu dialog \\\\

IMPLEMENT_DYNAMIC(CATMMainMenu, CDialogEx)


// CATMMainMenu's statics
CString CATMMainMenu::transaction;

// booleans' vars
bool booleans::Savings = FALSE;
bool booleans::Checking = FALSE;
bool booleans::deposit = FALSE;
bool booleans::transfer = FALSE;
CString booleans::amt = "";

// standard constructor
CATMMainMenu::CATMMainMenu(CWnd* pParent /*=NULL*/): CDialogEx(CATMMainMenu::IDD, pParent) {}

// standard destructor
CATMMainMenu::~CATMMainMenu() {}

// DoDataExchange
void CATMMainMenu::DoDataExchange(CDataExchange* pDX) {CDialogEx::DoDataExchange(pDX);}

// Message maps
BEGIN_MESSAGE_MAP(CATMMainMenu, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON2, &CATMMainMenu::OnBnClickedButton2) // GetCash
    ON_BN_CLICKED(IDC_BUTTON3, &CATMMainMenu::OnBnClickedButton3) // Deposit
    ON_BN_CLICKED(IDC_BUTTON5, &CATMMainMenu::OnBnClickedButton5) // Transfer
    ON_BN_CLICKED(IDC_BUTTON4, &CATMMainMenu::OnBnClickedButton4) // Account Info
    ON_BN_CLICKED(IDC_BUTTON6, &CATMMainMenu::OnBnClickedButton6) // Account Activity
    ON_BN_CLICKED(IDC_BUTTON1, &CATMMainMenu::OnBnClickedButton1) // Return Card
END_MESSAGE_MAP()


//// CATMMainMenu message handlers \\\\

BOOL CATMMainMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Customize Dlg
    SetWindowText(_T("Main Menu: Choose Option")); // set caption Dlg
    SetBackgroundColor(RGB(4,120,120));            // turquoise

	return TRUE;  // return TRUE  unless you set the focus to a control
}

//// Main Menu Items \\\\

void CATMMainMenu::OnBnClickedButton2() // Get Cash
{
    booleans::Savings = booleans::Checking = booleans::deposit = booleans::transfer = FALSE;

    CATMAccount Dlg(CString(" To Get Cash From"));
    if (Dlg.DoModal() == IDCANCEL) return;
    else // not needed
    {
        CString amt = booleans::amt;
        double money = _ttof(amt);
        amt.Format(("%.*f"), CATMApp::setp, money); // reformat amt to setprecision(2)
        double acctMoney;
        if (booleans::Savings) 
        {
            // perform transaction
            acctMoney = _ttof(CATMDlg::savings);
            acctMoney -= money;
            CATMDlg::savings.Format(("%.*f"), CATMApp::setp, acctMoney);
            
            // store transaction
            CString size; size.Format(_T("%i"), CATMDlg::statements.size());
            transaction = size + " Get Cash from savings, $" + amt;
            CATMDlg::statements.push_back(transaction);
        }

        else if (booleans::Checking)
        {
            // perform transaction
            acctMoney = _ttof(CATMDlg::checking);
            acctMoney -= money;
            CATMDlg::checking.Format(("%.*f"), CATMApp::setp, acctMoney);

            // store transaction
            CString size; size.Format(_T("%i"), CATMDlg::statements.size());
            transaction = size + " Get Cash from checking, $" + amt;
            CATMDlg::statements.push_back(transaction);
        }
        // else nothing (no message box)
    } // if AccountDlg exited w/ OK
} // Get Cash


void CATMMainMenu::OnBnClickedButton3() // Deposit
{
    booleans::Savings = booleans::Checking = booleans::transfer = FALSE;
    booleans::deposit = TRUE;

    CATMAccount Dlg(CString(" To Deposit To"));   
    if (Dlg.DoModal() == IDCANCEL) return;
    else // not needed
    {
        CString amt = booleans::amt;
        double money = _ttof(amt);
        amt.Format(("%.*f"), CATMApp::setp, money); // reformat amt to setprecision(2)
        double acctMoney;

        if (booleans::Savings)
        {
            // perform transaction
            acctMoney = _ttof(CATMDlg::savings);
            acctMoney += money;
            CATMDlg::savings.Format(("%.*f"), CATMApp::setp, acctMoney);

            // store transaction
            CString size; size.Format(_T("%i"), CATMDlg::statements.size());
            transaction = size + " Deposit to savings, $" + amt;
            CATMDlg::statements.push_back(transaction);
        }
        else if (booleans::Checking)
        {
            // perform transaction
            acctMoney = _ttof(CATMDlg::checking);
            acctMoney += money;
            CATMDlg::checking.Format(("%.*f"), CATMApp::setp, acctMoney);

            // store transaction
            CString size; size.Format(_T("%i"), CATMDlg::statements.size());
            transaction = size + " Deposit to checking, $" + amt;
            CATMDlg::statements.push_back(transaction);
        }
    } // if AccountDlg exited w/ OK
} // Deposit


// Transfer from 1 account to another ('TO' account picked automatically)
void CATMMainMenu::OnBnClickedButton5() // Transfer
{
    //savings = checking = FALSE;
    booleans::Savings = booleans::Checking = booleans::deposit = FALSE;
    booleans::transfer = TRUE;

    // get amount to transfer
    CATMAccount Dlg(CString(" to Transfer FROM, will transfer to other account"));
    if (IDCANCEL == Dlg.DoModal()) return;   

    // apply transfer
    CString amt = booleans::amt;
    double c = _ttof(CATMDlg::checking);
    double s = _ttof(CATMDlg::savings);
    double a = _ttof(amt);
    amt.Format(("%.*f"), CATMApp::setp, a); // reformat amt to setprecision(2)

    if (booleans::Savings) // transfer from Savings to Checking
    {
        // perform transaction
        s -= a; c += a; // remove from savings, add to checking
        CString size; size.Format(_T("%i"), CATMDlg::statements.size()); // for storing transaction
        transaction = size + " Transfer from savings to checking, $" + amt;
    }
    else // transfer from Checking to Savings
    {
        // perform transaction
        s += a; c -= a; // add to savings, remove from checking
        CString size; size.Format(_T("%i"), CATMDlg::statements.size()); // for storing transaction
        transaction = size + " Transfer from checking to savings, $" + amt;
    }
    CATMDlg::statements.push_back(transaction); // store transaction

    // convert 's' and 'c' to new savings and checking, reset transfer type
    CATMDlg::savings.Format(("%.*f"), CATMApp::setp, s);
    CATMDlg::checking.Format(("%.*f"), CATMApp::setp, c);
} // Transfer


void CATMMainMenu::OnBnClickedButton4() // Account Info
{
    CString s("savings: ");
    CString msg = s + CATMDlg::savings + "\r\nchecking: "
                    + CATMDlg::checking + "\r\nlast transaction: ";
    if (0 != CATMDlg::statements.size()) // predominant case
      msg += CATMDlg::statements[CATMDlg::statements.size() - 1];
    else msg = "none"; 
    MessageBox(msg);
}

// change to Dlg editWindow
void CATMMainMenu::OnBnClickedButton6() // Account Activity
{
    /* for debugging
    CString act;// never used?
    for (unsigned int i = 0; i < CATMDlg::statements.size(); i++)
        //MessageBox(CATMDlg::statements[i]);
        {act += CATMDlg::statements[i];
        act += "\r\n";}
        */
    CATMAcctActy dlg(CATMDlg::statements);
    dlg.DoModal();
}

void CATMMainMenu::OnBnClickedButton1() {CDialogEx::OnCancel();} // Return Card 
