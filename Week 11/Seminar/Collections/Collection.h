#pragma once

class Collection
{
public:
	virtual void add(int arg) = 0;
	virtual void remove(int arg) = 0;
	virtual size_t count(int arg) const = 0;
	virtual bool contains(int arg) const = 0;

	virtual ~Collection() = default;
};

