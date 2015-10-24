#pragma once


// CATMSavingsAccount dialog

class CATMSavingsAccount : public CDialogEx
{
	DECLARE_DYNAMIC(CATMSavingsAccount)

public:
    CATMSavingsAccount(CWnd* pParent = NULL);  // standard constructor
	virtual ~CATMSavingsAccount();

// Dialog Data
	enum { IDD = IDD_SAVINGS_ACCT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

// Implementation
protected:
    // Generated message map functions
	virtual BOOL OnInitDialog();

public:
    afx_msg void OnBnClickedButton1();
};
