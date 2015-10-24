#pragma once


// CATMAccount dialog

class CATMAccount : public CDialogEx
{
	DECLARE_DYNAMIC(CATMAccount)

public:
	CATMAccount(CString title, CWnd* pParent = NULL);          // usual constructor
    //CATMAccount(bool isTrans, bool inTransTo, bool isS,        // adjusted constructor for transfers
    //            bool isC, CString title, CWnd* pParent =NULL);  
    //CATMAccount(CWnd* pParent = NULL)
	virtual ~CATMAccount();

// Dialog Data
	enum { IDD = IDD_ACCOUNT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    HICON m_hIcon;
    CString DlgTitle;  // title to add to Dlg

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedButton1(); // savings
    afx_msg void OnBnClickedButton2(); // checking
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
};
