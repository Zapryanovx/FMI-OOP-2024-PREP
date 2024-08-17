#pragma once
#include "DynamicCollection.h"

class NormalCollection: public DynamicCollection
{
public:
	void add(int arg) override;
	void remove(int arg) override;
	size_t count(int arg) const override;
	bool contains(int arg) const override;

	~NormalCollection() override = default;
};

