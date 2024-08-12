#include "Student.h"

Student::Student(const MyString& name, size_t age):
	name(name), age(age) {}

const MyString& Student::getName() const
{
	return name;
}