#include "IntervalCollection.h"
#include <iostream>

bool IntervalCollection::inInterval(int arg) const
{
	return arg >= _a && arg <= _b;
}

IntervalCollection::IntervalCollection(unsigned a, unsigned b)
{
	if (a > b)
	{
		std::swap(a, b);
	}
	
	_a = a;
	_b = b;

	unsigned interval = b - a + 1;
	resize(interval);
}

void IntervalCollection::add(int arg)
{
	if (!inInterval(arg))
	{
		return;
	}

	unsigned idx = arg - _a;
	data[idx]++;
}

void IntervalCollection::remove(int arg)
{
	if (!inInterval(arg) || !(contains))
	{
		return;
	}
	
	unsigned idx = arg - _a;
	data[idx]--;
}

size_t IntervalCollection::count(int arg) const
{
	if (!inInterval(arg))
	{
		return;
	}

	unsigned idx = arg - _a;
	return data[idx];
}

bool IntervalCollection::contains(int arg) const
{
	return (count(arg) != 0);
}