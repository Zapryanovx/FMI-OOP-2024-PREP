#pragma once
#include "RestaurantItem.h"

class Food: public RestaurantItem
{
private:
	double weight = 0;

public:
	Food();
	Food(const char* name, unsigned quantity, double price, double weight);

	void setWeight(double weight);
	friend bool operator>(const Food& lhs, const Food& rhs);

	void print() const override;
	RestaurantItem* clone() const override;
};

