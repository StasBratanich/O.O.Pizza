
#include "pch.h"
#include "Toppings.h"

Toppings::Toppings()
{

}

Toppings::Toppings(double Price)
{
	this->Price = Price;
}

Toppings::~Toppings()
{

}

void Toppings::setPrice(double Price)
{
	this->Price = Price;
}