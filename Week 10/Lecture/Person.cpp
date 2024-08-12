#include "Person.h"
#include <cstring>
#pragma warning(disable:4996)

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
}

void Person::moveFrom(Person&& other)
{
	name = other.name;
	other.name = nullptr;

	age = other.age;
	other.age = 0;
}

void Person::free()
{
	delete[] name;
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::print() const
{
	std::cout << name << " " << age << std::endl;
}

void Person::setName(const char* name)
{
	if (name == nullptr || this->name == name) //setName(getName()) check
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setAge(int age)
{
	// < 0 check

	this->age = age;
}

Person::~Person()
{
	free();
}