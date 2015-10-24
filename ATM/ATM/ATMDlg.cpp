
// ATMDlg.cpp : implementation file
//   gets pin and calls CMainMenuDlg (starter Dlg)
//   uses public static member variables to pass daa <-> dialogs
//   

#include "stdafx.h"
#include "ATM.h"
#include "ATMDlg.h"
#include "afxdialogex.h"

#include "ATMMainMenu.h" // to call CATMMainMenuDlg

#include <sstream>
#include <fstream>
using namespace std;
#include <cassert>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//// CAboutDlg dialog used for App About \\\\

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

// CAboutDlg constructor
CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

// CAboutDlg DoDataExchange
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

// CAboutDlg Message map
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


//// CATMDlg dialog \\\\


// static members
CString CATMDlg::savings = 0;        // savings account
CString CATMDlg::checking = 0;       // checking account
vector<CString> CATMDlg::statements; // record of transactions


// standard constructor
CATMDlg::CATMDlg(CWnd* pParent /*=NULL*/): CDialogEx(CATMDlg::IDD, pParent) {m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);}

// DoDataExchange
void CATMDlg::DoDataExchange(CDataExchange* pDX) {CDialogEx::DoDataExchange(pDX);}

// Message Map
BEGIN_MESSAGE_MAP(CATMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDOK, &CATMDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CATMDlg::OnBnClickedCancel)
    ON_WM_CREATE()
END_MESSAGE_MAP()


// CATMDlg message handlers

// Initialize Dlg
BOOL CATMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// customize Dlg
    SetWindowText(_T("Automated Teller Machine: Enter Pin")); // set caption Dlg
    SetWindowLongPtr(m_hWnd, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
    SetBackgroundColor(RGB(254,120,120)); // light pink

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// system menu, if active
void CATMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}

    else
    {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CATMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CATMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// get pin, call MainMenu
void CATMDlg::OnBnClickedOk()
{      
    // get pin
    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
    CString pin;
    pEdit->GetWindowText(pin);

    // open file database
    fstream file; 
    file.open("transactions.txt", ios::in | ios::out);
    if (!file.good()) {MessageBox(CString("file failed to open")); return;}

    // file I/O
    char buf[100];  // line read in from file
    CString line;   // CString version of line read in from file

    // find match for pin in database
    while (!file.eof())
    {
        file.getline(buf, 100); line = buf;
        if (line.GetLength() == 0) continue; // blank line
        if (line == pin) break;             // found pin
    }

    // if reached end of file -> pin not in database
    if (file.eof()) {MessageBox(CString("no pin matched")); return;}

    // get savings
    file.getline(buf, 100); savings = buf;

    // get checking
    file.getline(buf, 100); checking = buf;
    //if (file.eof()) {MessageBox(CString("EOF")); return;}

    // get list of transactions
    while (!file.eof())
    {
        file.getline(buf, 100); line = buf;
        if (line.GetLength() <= 6) break;
        statements.push_back(line);
    }

    // close file
    file.clear(); file.close();

    // save current size of statements
    UINT oldStateSize = statements.size();
    
    // launch main menu
    CATMMainMenu Dlg;
    Dlg.DoModal();

    // if no transactions made -> don't bother w/ rewriting file
	if (oldStateSize == statements.size()) return;
    
    // open old file, create new file
    CFileException excpt1, excpt2;
    CStdioFile std, tempF;
    std.Open("transactions.txt", CFile::modeRead, &excpt1);
    tempF.Open("NewTransactions.txt", CFile::modeCreate | CFile::modeWrite, &excpt2);

    // copy over file, replace old data with new data
    pin += '\n';       // ReadString(LPTSTR lpsz, UINT nMax) does NOT remove '\n'
    std.SeekToBegin(); // ensure get pointer at beginning of old file
    while (std.ReadString(buf, 100)) // while !EOF
    {
        // get next line, test for pin match
        line = buf;
        if (line != pin)// || 0 == line.GetLength())       // no match
          {tempF.Write(line, line.GetLength()); continue;} // copy line to new file
        
        // else pin matched, copy new data to new file          
          // write pin to new file
          tempF.Write(pin, pin.GetLength());

          // move get pointer past savings, write new savings to new file
          std.ReadString(buf, 100); line = savings + '\n';
          tempF.Write(line, line.GetLength());  
        
          // move get pointer past checking, write new checking to new file
          std.ReadString(buf, 100); line = checking + '\n';
          tempF.Write(line, line.GetLength());

          // write new statements to new file, move get pointer past each in old file
          for (UINT i = 0; i < statements.size(); i++)
          {
              line = statements[i] + '\n';
              tempF.Write(line, line.GetLength());

              // ONLY move get pointer until reached end of old statements
              if (i < oldStateSize) std.ReadString(buf, 100);
          }
    } // while

    // delete vector of statements
    statements.clear();

    // close old file, remove it
    std.Close(); std.Remove("transactions.txt"); 

    // rename new file as old file, close it
    tempF.Close(); 
    tempF.Rename("NewTransactions.txt", "transactions.txt");
} // OnBnClickedOk

void CATMDlg::OnBnClickedCancel() {CDialogEx::OnCancel();}
