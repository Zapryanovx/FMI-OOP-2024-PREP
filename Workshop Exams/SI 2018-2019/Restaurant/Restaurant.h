#pragma once
#include "RestaurantItem.h"
#include "Food.h"
#include "Drink.h"

class Restaurant
{
private:
	RestaurantItem** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();

	void resize(size_t newCap);

public:
	Restaurant();
	
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);

	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;

	~Restaurant();

	void addProduct(const RestaurantItem& other);
	void removeProduct(size_t index);
	void changePrice(size_t index, double newPrice);
	void changeName(size_t index, const char* newName);

	void printAll() const;
	void printNonAlcoholic() const;

};

