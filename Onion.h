#include "Toppings.h"

#pragma once

class Onion: public Toppings
{
private:
	int Quantity;

public:
	Onion();
	~Onion();

	void setQuantity(int quantity);
	int getQuantity() const { return Quantity; }
};

