// ATMAccount.cpp : implementation file
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMAccount.h"
#include "afxdialogex.h"
#include "afxwin.h"

#include "ATMMainMenu.h" // to access booleans class
#include "ATMAmount.h"   // to cal CATMAmountDlg's

//// CATMAccount dialog \\\\

IMPLEMENT_DYNAMIC(CATMAccount, CDialogEx)

// usual constructor
CATMAccount::CATMAccount(CString title, CWnd* pParent /*=NULL*/)
	: CDialogEx(CATMAccount::IDD, pParent)
{
    DlgTitle = title;
}

// standard destructor
CATMAccount::~CATMAccount() {}

// DoDataExchangge
void CATMAccount::DoDataExchange(CDataExchange* pDX) {CDialogEx::DoDataExchange(pDX);}

// Message Maps
BEGIN_MESSAGE_MAP(CATMAccount, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &CATMAccount::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CATMAccount::OnBnClickedButton2)
END_MESSAGE_MAP()


//// CATMAccount message handlers \\\\

// Initialize Dlg  
BOOL CATMAccount::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// customize Dlg
    SetWindowText(_T("Choose Account") + DlgTitle);  // set caption of Dlg
    SetBackgroundColor(RGB(120,120,250));            // lavender

    return TRUE;  // return TRUE  unless you set the focus to a control
}


// clicked savings
void CATMAccount::OnBnClickedButton1()
{
    booleans::Savings = TRUE;
    booleans::Checking = FALSE;

    // get amount
    CATMAmount Dlg;
    if (IDOK == Dlg.DoModal())
    {
        // got amount -> exit
        CDialog::EndDialog(IDOK); // return IDOK upon exit (2nd Dlg if transferring)
        return;                   // go to end of handler
    }

    else 
        booleans::Savings = FALSE;
} // savings


// clicked checking
void CATMAccount::OnBnClickedButton2()
{
    booleans::Savings = FALSE;
    booleans::Checking = TRUE;

    // get amount
    CATMAmount Dlg;
    if (IDOK == Dlg.DoModal())
    {      
        // got amount -> exit
        CDialog::EndDialog(IDOK); // return IDOK upon exit (2nd Dlg if transferring)
        return;                   // go to end of handler
    }

    else 
        booleans::Checking = FALSE;
} // checking


    /* SAVINGS BUTTON
    if (transfer && !inTransferTo) // doing transfer, not in 'Transfer To' Dlg
    {
        // run 'Transfer From' Dlg
        booleans::Savings = TRUE;/////////////
        isSavings = TRUE;                     // removing from savings
        inTransferTo = TRUE;                  // so below call doesn't loop
        CATMMainMenu::transferType += "SavingsTo";
        
        CATMAccount Dlg(transfer, inTransferTo, booleans::Savings, booleans::Checking, CString(" To Transfer TO"));
        //CATMSavingsAccount Dlg1();
        if (IDOK == Dlg.DoModal())            // run 'Transfer To' Dlg
        {
            transfer = inTransferTo = FALSE;  // reset for safety
            isSavings = isChecking = FALSE;   // same reason
            booleans::Savings = booleans::Checking = FALSE; ///////////////////
            EndDialog(IDOK);                  // return IDOK upon exit (1st Dlg)
            return;                           // go to end of handler  
        }

        else // canceled out 2nd AcctDlg
        {
            isSavings = FALSE;                // reset isSavings
            booleans::Savings = FALSE;///////////////
            inTransferTo = FALSE;             // reset so won't skip above 'if'
            CATMMainMenu::transferType = "";  // remove "SavingsTo"
            if (!CATMMainMenu::isDeposit)
                {isSavings = FALSE;            // no longer removing from savings
                 booleans::Savings = FALSE;}///////////////////////
            return;                           // don't do anything else
        }    
    } // if transfer, in 'Transfer From' Dlg

    // if doing getCash -> check amount in savings in CATMAmountDlg
    if (!booleans::isD && !transfer) {isSavings = TRUE;booleans::Savings = TRUE;}/////////

    // get amount
    CATMAmount Dlg(booleans::deposit);
    if (IDOK == Dlg.DoModal())
    {
        // set stuff for use in other Dlg's        
        amt = booleans::amt; 
        CATMMainMenu::savings = TRUE; // for GetCash and Deposit
        booleans::Savings = FALSE; /////////////////////
        isSavings = FALSE;

        // do transfer stuff here so canceling AmountDlg doesn't require undoing it
        if (transfer)
        {
            CATMMainMenu::transferType += "Savings";
            transfer = inTransferTo = FALSE;
            isSavings = isChecking = FALSE;   // same reason
            booleans::Savings = booleans::Checking = FALSE;/////////////////
        }

        CDialog::EndDialog(IDOK); // return IDOK upon exit (2nd Dlg if transferring)
        return;                   // go to end of handler
    }
    
    // else canceled CAmountDlg -> undo isSavings if not doing a transfer
    else if (!CATMMainMenu::isDeposit && !transfer) {isSavings = FALSE; booleans::Savings;}////////////
    */


    /* CHECKING BUTTON
    if (transfer && !inTransferTo) // doing transfer, not in 'Transfer To' Dlg
    {
        // run 'Transfer From' Dlg
        isChecking = TRUE;                    // removing from checking
        booleans::Checking = TRUE;/////////////////
        inTransferTo = TRUE;                  // so below call doesn't loop
        CATMMainMenu::transferType += "CheckingTo";

        CATMAccount Dlg(transfer, inTransferTo, booleans::Savings, booleans::Checking, CString(" To Transfer TO"));
        // CATMSavingsAccount Dlg1();
        if (IDOK == Dlg.DoModal())            // run 'Transfer To' Dlg
        {
            transfer = inTransferTo = FALSE;  // reset for safety
            isSavings = isChecking = FALSE;   // same reason
            booleans::Savings = booleans::Checking = FALSE; /////////////
            EndDialog(IDOK);                  // return IDOK upon exit (1st Dlg)
            return;                           // done
        }

        else // canceled out 2nd AcctDlg
        {
            inTransferTo = FALSE;             // reset so won't skip above 'if'
            CATMMainMenu::transferType = "";  // remove "CheckingTo"
            if (!CATMMainMenu::isDeposit)
              {isChecking = FALSE;             // no longer removing from checking
                booleans::Checking = FALSE;}///////////////
            return;                           // don't do anything else
        }
    } // if transfer, in 'Transfer From' Dlg

    // if doing getCash -> check amount in checking in CATMAmountDlg
    if (!CATMMainMenu::isDeposit && !transfer) {isChecking = TRUE;booleans::Checking = TRUE;}///////////
      
    // get amount
    CATMAmount Dlg(booleans::deposit);
    if (IDOK == Dlg.DoModal())
    {
        // set stuff for use in other Dlg's
        //amt = Dlg.amt;
        CATMMainMenu::checking = TRUE; // for GetCash and Deposit
        isChecking = FALSE; 
        booleans::Checking = FALSE;///////////////

        // do transfer stuff here so canceling AmountDlg doesn't require undoing it
        if (transfer)
        {
            CATMMainMenu::transferType += "Checking";
            transfer = inTransferTo = FALSE;
            isSavings = isChecking = FALSE;
        }

        CDialog::EndDialog(IDOK); // return IDOK upon exit (2nd Dlg if transferring)
        return;                   // go to end of handler
    }

    // else canceled CAmountDlg -> undo isChecking if not doing a transfer
    else if (!CATMMainMenu::isDeposit && !transfer) isChecking = FALSE;
    */