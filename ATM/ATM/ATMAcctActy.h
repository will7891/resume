#pragma once

#include <vector>
using namespace std;

// CATMAcctActy dialog

class CATMAcctActy : public CDialogEx
{
	DECLARE_DYNAMIC(CATMAcctActy)

public:
	CATMAcctActy(vector<CString>& act, CWnd* pParent = NULL);   // standard constructor
	virtual ~CATMAcctActy();

// Dialog Data
	enum { IDD = IDD_ACTIVITY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
    vector<CString> activity;  // copied from CATMDLG::statements
    unsigned int currentIndex; // current index of activity
    CString actPrint;          // CString form of activity (for 0 to currentIndex + 1 lines)

    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedButton1();
};
