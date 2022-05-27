
// LoginDlg.h : header file
//

#pragma once


// CLoginDlg dialog
class CLoginDlg : public CDialogEx
{
// Construction
public:
	CLoginDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG };
#endif

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
	afx_msg void OnBnClickedOk();
	CEdit m_editCtrl1;
	CEdit m_editCtrl2;
	CString userCheck;
	afx_msg void OnBnClickedButton1();
	CButton savePassword;
	afx_msg void OnBnClickedCheck1();
};
