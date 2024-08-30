#pragma once
#include <iostream>

enum Product
{
	DEFAULT,
	FOOD,
	DRINK
};

class RestaurantItem
{
private:
	Product product = Product::DEFAULT;
	unsigned quantity = 0;
	double price = 0.00;
	char* name = nullptr;

	void copyFrom(const RestaurantItem& other);
	void moveFrom(RestaurantItem&& other);
	void free();

public:
	RestaurantItem() = default;
	RestaurantItem(Product product, unsigned quantity, double price, const char* name);

	RestaurantItem(const RestaurantItem& other);
	RestaurantItem& operator=(const RestaurantItem& other);

	RestaurantItem(RestaurantItem&& other) noexcept;
	RestaurantItem& operator=(RestaurantItem&& other) noexcept;

	virtual ~RestaurantItem();

	Product getProduct() const;
	unsigned getQuantity() const;
	double getPrice() const;
	const char* getName() const;

	void setProduct(Product product);
	void setQuantity(unsigned quantity);
	void setPrice(double price);
	void setName(const char* name);

	virtual RestaurantItem* clone() const = 0;
	virtual void print() const = 0;


};

