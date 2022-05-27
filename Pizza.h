#include "Order.h"

#pragma once

class Pizza: public Order
{
private:
	double Price;
	int Quantity;


public:
	Pizza();
	~Pizza();

	void setPrice(double Price);
	void setQuantity(int Quantity);
	double getPrice() const { return this->Price; }
	double getQuantity() const { return this->Quantity; }
};

