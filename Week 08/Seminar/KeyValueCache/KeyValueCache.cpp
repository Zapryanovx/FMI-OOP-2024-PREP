#include "KeyValueCache.h"

KeyValueCache::KeyValueCache(unsigned nullValue)
{
	for (int i = 0; i < N; i++)
	{
		_values[i] = nullValue;
	}

	_nullValue = nullValue;
}

void KeyValueCache::add(unsigned key, unsigned value)
{
	if (value == _nullValue || key >= N)
	{
		return;
	}

	_values[key] = value;
}

bool KeyValueCache::contains(unsigned key) const
{
	return _values[key] != _nullValue;
}

unsigned KeyValueCache::getValue(unsigned key) const
{
	if (!contains(key))
	{
		throw "Error";
	}

	return _values[key];
}