#include "Toppings.h"

#pragma once

class Olives: public Toppings
{
private:
	int Quantity;

public:
	Olives();
	~Olives();

	void setQuantity(int quantity);
	int getQuantity() const { return Quantity; }
};