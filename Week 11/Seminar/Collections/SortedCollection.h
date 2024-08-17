#pragma once
#include "DynamicCollection.h"

class SortedCollection: DynamicCollection
{
	int lowerBound(int x) const;
	int upperBound(int x) const;

public:
    void add(int arg) override;
    void remove(int arg) override;
    size_t count(int arg) const override;
    bool contains(int arg) const override;
};

