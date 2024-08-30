#include "RestaurantItem.h"
#pragma warning(disable:4996)

void RestaurantItem::copyFrom(const RestaurantItem& other)
{
	name = new char[std::strlen(other.name) + 1];
	std::strcpy(name, other.name);

	product = other.product;
	quantity = other.quantity;
	price = other.price;
}

void RestaurantItem::moveFrom(RestaurantItem&& other)
{
	name = other.name;
	other.name = nullptr;

	product = other.product;
	other.product = Product::DEFAULT;

	quantity = other.quantity;
	other.quantity = 0;
	
	price = other.price;
	other.price = 0;
}

void RestaurantItem::free()
{
	delete[] name;
}

RestaurantItem::RestaurantItem(Product product, unsigned quantity, double price, const char* name)
{
	setProduct(product);
	setQuantity(quantity);
	setPrice(price);
	setName(name);
}

RestaurantItem::RestaurantItem(const RestaurantItem& other)
{
	copyFrom(other);
}

RestaurantItem& RestaurantItem::operator=(const RestaurantItem& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}


RestaurantItem::RestaurantItem(RestaurantItem&& other) noexcept
{
	moveFrom(std::move(other));
}

RestaurantItem& RestaurantItem::operator=(RestaurantItem&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

RestaurantItem::~RestaurantItem()
{
	free();
}

Product RestaurantItem::getProduct() const
{
	return product;
}

unsigned RestaurantItem::getQuantity() const
{
	return quantity;
}

double RestaurantItem::getPrice() const
{
	return price;
}

const char* RestaurantItem::getName() const
{
	return name;
}

void RestaurantItem::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[std::strlen(name) + 1];
	std::strcpy(this->name, name);
}

void RestaurantItem::setProduct(Product product)
{
	this->product = product;
}

void RestaurantItem::setQuantity(unsigned quantity)
{
	this->quantity = quantity;
}

void RestaurantItem::setPrice(double price)
{
	this->price = price;
}

void RestaurantItem::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Quantity: " << this->quantity << std::endl;
	std::cout << "Price: " << this->price << std::endl;
}