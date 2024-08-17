#pragma once
#include "Collection.h"

class DynamicCollection: public Collection
{
protected:
	int* data;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const DynamicCollection& other);
	void moveFrom(DynamicCollection&& other);
	void free();
	
	void resize(size_t newCap);
	DynamicCollection(size_t cap);

public:
	DynamicCollection();

	DynamicCollection(const DynamicCollection& other);
	DynamicCollection(DynamicCollection&& other) noexcept;

	DynamicCollection& operator=(const DynamicCollection& other);
	DynamicCollection& operator=(DynamicCollection&& other) noexcept;

	~DynamicCollection();

};

