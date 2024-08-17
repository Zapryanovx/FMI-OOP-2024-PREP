#pragma once
#include "DynamicCollection.h"

class IntervalCollection: public DynamicCollection
{
	unsigned _a = 0;
	unsigned _b = 0;

	bool inInterval(int arg) const;

public:
	IntervalCollection(unsigned a, unsigned b);
	void add(int arg) override;
	void remove(int arg) override;
	size_t count(int arg) const override;
	bool contains(int arg) const override;
	
};

