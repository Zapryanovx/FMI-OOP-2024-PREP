#pragma once
#include <iostream>

class Person
{
	char* name = nullptr;
	int age = 0;

	void copyFrom(const Person& other);
	void moveFrom(Person&& other);
	void free();

public:
	Person() = default;
	Person(const char* name, int age);

	Person(const Person& other);
	Person& operator=(const Person& other);

	Person(Person&& other) noexcept;
	Person& operator=(Person&& other) noexcept;

	const char* getName() const;
	int getAge() const;

	void print() const;
	
	~Person();

protected:
	void setName(const char* name);
	void setAge(int age);
}; 

