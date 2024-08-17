#pragma once
#include "CollectionSupersetOperation.h"
#include "Collection.h"

class IntersectionSupersetOperation: public CollectionSupersetOperation
{
public:
	IntersectionSupersetOperation(const Collection& l, const Collection& r);

	void add(int arg) override;
	void remove(int arg) override;
	size_t count(int arg) const override;
	bool contains(int arg) const override;
};

