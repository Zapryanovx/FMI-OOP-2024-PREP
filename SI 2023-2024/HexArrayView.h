#pragma once
#include "HexArray.h"

class HexArrayView
{
private:
	const unsigned char* begin;
	const unsigned char* end;

public:
	HexArrayView(const HexArray& arr);
	HexArrayView(const unsigned char* begin, const unsigned char* end);

	size_t length() const;
	unsigned char operator[](size_t index) const;

	HexArrayView substr(size_t from, size_t length) const;
	friend std::ostream& operator<<(std::ostream& os, const HexArrayView& arr);
};

