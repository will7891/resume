#pragma once


// CATMAmount dialog

class CATMAmount : public CDialogEx
{
	DECLARE_DYNAMIC(CATMAmount)

public:
	CATMAmount(CWnd* pParent = NULL);   // standard constructor
	virtual ~CATMAmount();

// Dialog Data
	enum { IDD = IDD_AMOUNT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    // Implementation
protected:
    HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
    void ReadConvertWrite(int multiplier); // reads in current amount, converts it, rewrites to view

    afx_msg void OnBnClickedOk();       // done entering amount
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedButton1();  // pressed 1
    afx_msg void OnBnClickedButton2();  // pressed 2
    afx_msg void OnBnClickedButton3();  // pressed 3
    afx_msg void OnBnClickedButton6();  // pressed 4
    afx_msg void OnBnClickedButton4();  // pressed 5
    afx_msg void OnBnClickedButton5();  // pressed 6
    afx_msg void OnBnClickedButton7();  // pressed 7
    afx_msg void OnBnClickedButton8();  // pressed 8
    afx_msg void OnBnClickedButton9();  // pressed 9
    afx_msg void OnBnClickedButton10(); // pressed 0
    afx_msg void OnEnChangeEdit1();
};
