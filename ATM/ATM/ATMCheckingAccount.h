#pragma once


// CATMCheckingAccount dialog

class CATMCheckingAccount : public CDialogEx
{
	DECLARE_DYNAMIC(CATMCheckingAccount)

public:
	CATMCheckingAccount(CWnd* pParent = NULL);   // standard constructor
	virtual ~CATMCheckingAccount();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
