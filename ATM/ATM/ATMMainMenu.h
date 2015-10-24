#pragma once


// CATMMainMenu dialog

class CATMMainMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CATMMainMenu)

public:
	CATMMainMenu(CWnd* pParent = NULL);   // standard constructor
	virtual ~CATMMainMenu();

// Dialog Data
	enum { IDD = IDD_MAINMENU_DLG };

    protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
    static CString transaction;  // transaction that has occured

    afx_msg void OnBnClickedCancel();  
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedButton1(); // Return Card
    afx_msg void OnBnClickedButton2(); // Get Cash
    afx_msg void OnBnClickedButton3(); // Deposit
    afx_msg void OnBnClickedButton4(); // Account Info 
    afx_msg void OnBnClickedButton5(); // Transfer
    afx_msg void OnBnClickedButton6(); // Account Activity
};

struct booleans
{
    static bool Savings;
    static bool Checking;
    static CString amt;
    static bool deposit;
    static bool transfer;
};
