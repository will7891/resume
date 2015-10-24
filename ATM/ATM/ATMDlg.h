
// ATMDlg.h : header file
//

#pragma once

#include <vector>
using namespace std;

// CATMDlg dialog
class CATMDlg : public CDialogEx
{
// Construction
public:
	CATMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ATM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
    static CString savings;           // savings account
    static CString checking;          // checking account
    static vector<CString> statements;// record of transactions

    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
};

