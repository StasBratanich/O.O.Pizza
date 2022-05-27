#pragma once

#include "Order.h"

// NewWindow dialog

class NewWindow : public CDialogEx
{
	DECLARE_DYNAMIC(NewWindow)

public:
	NewWindow(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewWindow();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGNew };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CStatic m_strTest;
	int field_Quantity;
	afx_msg void OnBnClickedButton1();
	CBitmap cbitmap_;
	CStatic picture_control_;
	afx_msg void OnBnClickedCheckOlives();
	afx_msg void OnBnClickedCheckMushrooms();
	afx_msg void OnBnClickedCheckOnion();
	double TotalOrderPrice;
	afx_msg void OnBnClickedButtonSubmit();
	afx_msg void OnBnClickedDeleteOrder();
};
