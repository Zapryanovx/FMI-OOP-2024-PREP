#include "Restaurant.h"

void Restaurant::copyFrom(const Restaurant& other)
{
	data = new RestaurantItem * [other.capacity];

	size = other.size;
	capacity = other.capacity;

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void Restaurant::moveFrom(Restaurant&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;

}

void Restaurant::free()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
}

void Restaurant::resize(size_t newCap)
{
	RestaurantItem** newData = new RestaurantItem * [newCap];

	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	newData = nullptr;
	capacity = newCap;
}

Restaurant::Restaurant()
{
	capacity = 8;

	data = new RestaurantItem * [capacity];
}

Restaurant::Restaurant(const Restaurant& other)
{
	copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
{
	moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Restaurant::~Restaurant()
{
	free();
}

void Restaurant::addProduct(const RestaurantItem& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size++] = obj.clone();
}

void Restaurant::removeProduct(size_t index)
{
	if (index >= size)
	{
		return;
	}

	delete data[index];
	data[index] = nullptr;

	std::swap(data[index], data[size - 1]);
	size--;
}

void Restaurant::changePrice(size_t index, double newPrice)
{
	if (index >= size)
	{
		return;
	}

	data[index]->setPrice(newPrice);
}

void Restaurant::changeName(size_t index, const char* newName)
{
	if (index >= size)
	{
		return;
	}

	data[index]->setName(newName);
}

void Restaurant::printAll() const
{
	for (int i = 0; i < size; i++)
	{
		data[i]->print();
		if (i != size - 1)
		{
			std::cout << "-----------" << std::endl;
		}
	}
}

void Restaurant::printNonAlcoholic() const
{
	Drink validator;
	validator.setAlcoholPerc(0);

	bool line = false;
	
	for (int i = 0; i < size; i++)
	{
		if (data[i]->getProduct() == Product::DRINK)
		{
			if (!(*dynamic_cast<Drink*>(data[i]) > validator))
			{
				if (line)
				{
					std::cout << "---------------------" << std::endl;
				}

				data[i]->print();
				line = true;

			}
		}
	}
}