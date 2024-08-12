#pragma once
#include "Student.h"

class StudentCollection
{
private:
	Student** data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const StudentCollection& other);
	void moveFrom(StudentCollection&& other);

	void resize(size_t newCap);
	size_t getFirstFreeIndex() const;

public:
	StudentCollection();

	StudentCollection(const StudentCollection& other);
	StudentCollection& operator=(const StudentCollection& other);

	void pushAt(size_t idx, const Student& other);
	void pushAt(size_t idx, Student&& other);

	void push(const Student& other);
	void push(Student&& other);

	void removeAt(size_t idx);
	bool contains(size_t idx) const;

	size_t getSize() const;
	size_t getCapacity() const;

	const Student& at(size_t idx) const;

	StudentCollection(StudentCollection&& other) noexcept;
	StudentCollection& operator=(StudentCollection&& other) noexcept;


	~StudentCollection();
};

