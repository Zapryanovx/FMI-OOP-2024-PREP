#include "Food.h"

Food::Food()
{
	setProduct(Product::FOOD);
}

Food::Food(const char* name, unsigned quantity, double price, double weight) : RestaurantItem(Product::FOOD, quantity, price, name)
{
	setWeight(weight);
}

void Food::setWeight(double weight)
{
	this->weight = weight;
}

void Food::print() const
{
	RestaurantItem::print();
	std::cout << "Weight " << weight << std::endl;
}

RestaurantItem* Food::clone() const
{
	return new Food(*this);
}

bool operator>(const Food& lhs, const Food& rhs)
{
	return lhs.weight > rhs.weight;
}
