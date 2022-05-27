
#include "Order.h"

#pragma once

class Toppings: public Order
{
private:
	double Price;
	
public:
	Toppings();
	Toppings(double Price);
	~Toppings();

	void setPrice(double Price);
	double getPrice() const { return this->Price; }
};

