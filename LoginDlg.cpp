
// LoginDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Login.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"
#include "NewWindow.h"

// Custom Code Starts
#include <string>
#include "cereal/archives/xml.hpp"
#include <fstream>
// Custom Code Ends

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Custom Code Starts
bool If_Member;
const CString username = _T("user");
const CString password = _T("pass");

struct userData {
	std::string user;
	std::string password;

	// This method lets cereal know which data members to serialize
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(user, password); // serialize things by passing them to the archive
	}
};
// Custom Code Ends
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLoginDlg dialog



CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editCtrl1);
	DDX_Control(pDX, IDC_EDIT2, m_editCtrl2);
	DDX_Control(pDX, IDC_CHECK1, savePassword);

	// Ser Code Starts
	{
		std::ifstream file("out.xml");
		if (file.is_open()) {

			cereal::XMLInputArchive archive(file); // depending on the archive type, data may be
													  // output to the stream as it is serialized, or
													  // only on destruction
			userData newUser;

			archive(CEREAL_NVP(newUser.user), CEREAL_NVP(newUser.password));
			m_editCtrl1.SetWindowTextW(CString(newUser.user.c_str()));
			m_editCtrl2.SetWindowTextW(CString(newUser.password.c_str()));
			savePassword.SetCheck(1);
		}
	}
	// Ser Code Ends
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CLoginDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLoginDlg::OnPaint()
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
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLoginDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CString userName = _T("");
	m_editCtrl1.GetWindowTextW(userName);
	CString userPassword = _T("");
	m_editCtrl2.GetWindowTextW(userPassword);

	int checkBoxValue = savePassword.GetCheck(); // Get CheckBox Value; 1 = checked : 0 = unchecked

	if (userName.IsEmpty()){
		AfxMessageBox(_T("You must provide a username"));
		m_editCtrl1.SetFocus();
		return;
	}
	// Don't allow a blank password
	else if (userPassword.IsEmpty())
	{
		AfxMessageBox(_T("Blank passwords are not allowed\n"
			"Please provide a password"));
		m_editCtrl2.SetFocus();
		return;
	}
	else if(userName == username && userPassword == password){

		If_Member = 1;
		CDialogEx::OnOK();
	}
	else {
		AfxMessageBox(_T("Invalid Credentials"));
		m_editCtrl1.SetFocus();
		return;
	}

	if (checkBoxValue == 1) {
		// Perform Serialization on Credentials to store

		CT2CA pszConvertedAnsiString(userName);
		CT2CA pszConvertedAnsiString2(userPassword);
		// construct a std::string using the LPCSTR input
		std::string strStd(pszConvertedAnsiString);
		std::string strStd2(pszConvertedAnsiString2);

		userData newUser;
		newUser.user = strStd;
		newUser.password = strStd2;

		{
			std::ofstream file("out.xml");
			cereal::XMLOutputArchive archive(file); // depending on the archive type, data may be
													  // output to the stream as it is serialized, or
													  // only on destruction
			archive(CEREAL_NVP(newUser.user), CEREAL_NVP(newUser.password));
		}

		AfxMessageBox(_T("Password Saved!"));

	}
	else
	{
		// Perform Serialization on Credentials to store

		CT2CA pszConvertedAnsiString(userName);
		CT2CA pszConvertedAnsiString2(userPassword);
		// construct a std::string using the LPCSTR input
		std::string strStd(pszConvertedAnsiString);
		std::string strStd2(pszConvertedAnsiString2);

		userData newUser;
		newUser.user = "";
		newUser.password = "";

		{
			std::ofstream file("out.xml");
			cereal::XMLOutputArchive archive(file); // depending on the archive type, data may be
													  // output to the stream as it is serialized, or
													  // only on destruction
			archive(CEREAL_NVP(newUser.user), CEREAL_NVP(newUser.password));
		}
	}
	NewWindow* newDlg = new NewWindow();
	newDlg->DoModal();

	delete newDlg;
	UpdateData(FALSE);

}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	If_Member = 0;

	CDialogEx::OnOK();

	NewWindow* newDlg = new NewWindow();
	newDlg->DoModal();

	delete newDlg;
}


void CLoginDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}
