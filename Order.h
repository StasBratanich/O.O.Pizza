
#pragma once

class Order
{
private:
	double TotalPrice;
	bool ClubMember;

	static unsigned int ID;

public:
	Order();
	~Order();

	void setTotalPrice(double price);
	double getPrice() const { return this->TotalPrice; }
	void setClubMember(bool ClubMember);
	bool getClubMember() const { return ClubMember; }
	static unsigned int setID();
	int getID() const { return this->ID; }
	static unsigned int lowerID();
};