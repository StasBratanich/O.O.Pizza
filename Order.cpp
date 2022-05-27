
#include "pch.h"
#include "Order.h"

unsigned int Order::ID = 1;

Order::Order()
{
	ClubMember = false;
	TotalPrice = 0.0;
}

Order::~Order()
{

}

void Order::setTotalPrice(double price) 
{
	TotalPrice = price;
}

void Order::setClubMember(bool ClubMember)
{
	this->ClubMember = ClubMember;
}

unsigned int Order::setID()
{
	ID++;

	return ID;
}

unsigned int Order::lowerID()
{
	ID--;

	return ID;
}