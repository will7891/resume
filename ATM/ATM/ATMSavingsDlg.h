#pragma once


// ATMSavingsDlg dialog

class ATMSavingsDlg : public CDialog
{
	DECLARE_DYNAMIC(ATMSavingsDlg)

public:
	ATMSavingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ATMSavingsDlg();

// Dialog Data
	enum { IDD = IDD_ATMSAVINGSDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
};
