#include "Toppings.h"

#pragma once

class Mushrooms: public Toppings
{
private:
	int Quantity;

public:
	Mushrooms();
	~Mushrooms();

	void setQuantity(int quantity);
	int getQuantity() const { return Quantity; }
};

