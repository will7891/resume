#pragma once


// CSecondDlg dialog

class CSecondDlg : public CDialog
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSecondDlg();

// Dialog Data
	enum { IDD = IDD_SECOND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
};
