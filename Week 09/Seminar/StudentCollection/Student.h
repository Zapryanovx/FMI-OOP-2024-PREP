#pragma once
#include "MyString.h"

class Student
{
private:
	MyString name;
	size_t age;

public:
	Student(const MyString& name, size_t age);

	const MyString& getName() const;
};

