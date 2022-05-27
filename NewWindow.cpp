// NewWindow.cpp : implementation file
//

#include "pch.h"
#include "Login.h"
#include "NewWindow.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Order.h"
#include "Pizza.h"
#include "Toppings.h"
#include "Mushrooms.h"
#include "Olives.h"
#include "Onion.h"

// NewWindow dialog

// OOPizza Prices //

#define TOPPINGSPRICE 6.0
#define PIZZAPRICE 25.0

// OOPizza Objects //

Order MyOrder;
Pizza MyPizza;
Olives MyOlives;
Onion MyOnions;
Mushrooms MyMushrooms;

extern bool If_Member;
int Sum = 0;
bool Olive = 0;
bool Onions = 0;
bool Mushroom = 0;
bool CheckIfReady = 0;


CTypedPtrArray<CObArray, Order> orders;
Order* currentOrder;

IMPLEMENT_DYNAMIC(NewWindow, CDialogEx)

// Sum Template //

template<typename T>
T adder(T first) {
	return first;
}

NewWindow::NewWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGNew, pParent)
	
	, field_Quantity(0)
	, TotalOrderPrice(0)
{
	
}


NewWindow::~NewWindow()
{
	
}



void NewWindow::DoDataExchange(CDataExchange* pDX)

{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IF_MEMBER1, m_strTest);


	if (If_Member)
	{
		m_strTest.SetWindowTextW(L"Is a member");
	}
	else
	{
		m_strTest.SetWindowTextW(L"Is a guest");
	}
	DDX_Text(pDX, IDC_EDIT_QUANTITY, field_Quantity);


	DDX_Control(pDX, IDC_PICTURE_CONTROL, picture_control_);
	cbitmap_.LoadBitmap(IDB_BITMAP3);
	picture_control_.SetBitmap((HBITMAP)cbitmap_.Detach());

	DDX_Text(pDX, IDC_EDIT3, TotalOrderPrice);
	DDX_Text(pDX, IDC_EDIT3, TotalOrderPrice);
}



BEGIN_MESSAGE_MAP(NewWindow, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewWindow::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &NewWindow::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK_OLIVES, &NewWindow::OnBnClickedCheckOlives)
	ON_BN_CLICKED(IDC_CHECK_Mushrooms, &NewWindow::OnBnClickedCheckMushrooms)
	ON_BN_CLICKED(IDC_CHECK_ONION, &NewWindow::OnBnClickedCheckOnion)
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &NewWindow::OnBnClickedButtonSubmit)
	ON_BN_CLICKED(IDC_DELETE_ORDER, &NewWindow::OnBnClickedDeleteOrder)
END_MESSAGE_MAP()

void NewWindow::OnBnClickedOk()
{
	Sum = 0;
	Olive = 0;
	Onions = 0;
	Mushroom = 0;

	CDialogEx::OnOK();
	CLoginDlg* loginDlg = new CLoginDlg();
	loginDlg->DoModal();
	delete loginDlg;
}

void NewWindow::OnBnClickedCheckOlives()
{
	// TODO: Add your control notification handler code here

	Olive = !Olive;
	if (Olive == true)
	{
		Sum = Sum + 1;
		MyOlives.setQuantity(1);
	}
	else
	{
		Sum = Sum - 1;
		MyOlives.setQuantity(0);
	}

	if (Sum == 0)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP3);
	}

	if (Sum == 1)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP9);
	}

	if (Sum == 10)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP4);
	}
	if (Sum == 11)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP6);
	}
	if (Sum == 100)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP10);
	}
	if (Sum == 101)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP8);
	}
	if (Sum == 110)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP5);
	}
	if (Sum == 111)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP7);
	}
	picture_control_.SetBitmap((HBITMAP)cbitmap_.Detach());
	
}

void NewWindow::OnBnClickedCheckMushrooms()
{
	// TODO: Add your control notification handler code here
	Mushroom = !Mushroom;
	if (Mushroom == true)
	{
		Sum = Sum + 10;
		MyMushrooms.setQuantity(1);
	}
	else
	{
		Sum = Sum - 10;
		MyMushrooms.setQuantity(0);
	}

	if (Sum == 0)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP3);
	}

	if (Sum == 1)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP9);
	}

	if (Sum == 10)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP4);
	}
	if (Sum == 11)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP6);
	}
	if (Sum == 100)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP10);
	}
	if (Sum == 101)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP8);
	}
	if (Sum == 110)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP5);
	}
	if (Sum == 111)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP7);
	}
	picture_control_.SetBitmap((HBITMAP)cbitmap_.Detach());
}

void NewWindow::OnBnClickedCheckOnion()
{
	// TODO: Add your control notification handler code here
	Onions = !Onions;
	if (Onions == true)
	{
		Sum = Sum + 100;
		MyOnions.setQuantity(1);
	}
	else
	{
		Sum = Sum - 100;
		MyOnions.setQuantity(0);
	}

	if (Sum == 0)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP3);
	}

	if (Sum == 1)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP9);
	}

	if (Sum == 10)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP4);
	}
	if (Sum == 11)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP6);
	}
	if (Sum == 100)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP10);
	}
	if (Sum == 101)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP8);
	}
	if (Sum == 110)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP5);
	}
	if (Sum == 111)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP7);
	}
	picture_control_.SetBitmap((HBITMAP)cbitmap_.Detach());
}

void NewWindow::OnBnClickedButtonSubmit()
{
	if (CheckIfReady == 0)
	{
		AfxMessageBox(_T("Never pay before you checked the total price"));
	}

	else if (TotalOrderPrice == 0)
	{
		AfxMessageBox(_T("Emptry order"));
	}

	else
	{
		CString CheckID;
		CheckID.Format(_T("%d"), MyOrder.getID());

		CString MessageForFinish;
		MessageForFinish.Format(_T("Thank you for order #%d - %.2lf NIS"), MyOrder.getID(), TotalOrderPrice);
		AfxMessageBox(MessageForFinish);
		Sum = 0;
		Olive = 0;
		Onions = 0;
		Mushroom = 0;
		CheckIfReady = 0;

		currentOrder = new Order();
		currentOrder->setID();

		CDialogEx::OnOK();
		CLoginDlg* loginDlg = new CLoginDlg();
		loginDlg->DoModal();
		delete loginDlg;
	}
}

void NewWindow::OnBnClickedButton1()
{	
	CheckIfReady = 1;
	Order* pPizza = &MyPizza;
	MyPizza.setPrice(PIZZAPRICE);

	Toppings* pOlives = &MyOlives;
	Toppings* pOnions = &MyOnions;
	Toppings* pMushrooms = &MyMushrooms;

	pOlives->setPrice(TOPPINGSPRICE);
	pOnions->setPrice(TOPPINGSPRICE);
	pMushrooms->setPrice(TOPPINGSPRICE);


	UpdateData(TRUE);
	int num = field_Quantity;
	MyPizza.setQuantity(num);

	TotalOrderPrice = adder<double>((MyPizza.getPrice() * MyPizza.getQuantity()));
	TotalOrderPrice += adder<double>(MyMushrooms.getQuantity() * MyMushrooms.getPrice() * MyPizza.getQuantity());
	TotalOrderPrice += adder<double>(MyOlives.getQuantity() * MyOlives.getPrice() * MyPizza.getQuantity());
	TotalOrderPrice += adder<double>(MyOnions.getQuantity() * MyOnions.getPrice() * MyPizza.getQuantity());

	if (If_Member)
	{
		pPizza->setClubMember(true);
		TotalOrderPrice -= TotalOrderPrice / 10;
	}

	UpdateData(FALSE);


	if (Sum == 0)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP3);
	}

	if (Sum == 1)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP9);
	}

	if (Sum == 10)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP4);
	}
	if (Sum == 11)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP6);
	}
	if (Sum == 100)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP10);
	}
	if (Sum == 101)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP8);
	}
	if (Sum == 110)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP5);
	}
	if (Sum == 111)
	{
		cbitmap_.LoadBitmap(IDB_BITMAP7);
	}
	picture_control_.SetBitmap((HBITMAP)cbitmap_.Detach());
}

void NewWindow::OnBnClickedDeleteOrder()
{
	if (currentOrder->getID() > 1)
	{
		currentOrder->lowerID();
		AfxMessageBox(_T("Last order has been deleted !"));
	}

	else
	{
		AfxMessageBox(_T("There are no more orders to delete !!!"));
	}
}
