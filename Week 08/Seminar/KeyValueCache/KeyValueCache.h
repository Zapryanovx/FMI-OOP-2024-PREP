#pragma once

constexpr unsigned N = 100;

class KeyValueCache
{
public:
	KeyValueCache(unsigned nullValue);
	void add(unsigned key, unsigned value);
	bool contains(unsigned key) const;
	unsigned getValue(unsigned key) const;
	
private:
	unsigned _values[N];
	unsigned _nullValue;
};

