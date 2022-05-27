
#include "pch.h"
#include "Pizza.h"


Pizza::Pizza()
{

}

Pizza::~Pizza() // Destructor
{

}

void Pizza::setPrice(double Price)
{
	this->Price = Price;
}

void Pizza::setQuantity(int Quantity)
{
	this->Quantity = Quantity;
}