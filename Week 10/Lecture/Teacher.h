#pragma once
#include "Person.h"

class Teacher: public Person
{
	char** subjects;
	size_t subjectsCount;

	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
	void free();

public:
	Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount);

	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(Teacher&& other) noexcept;

	~Teacher();
};

