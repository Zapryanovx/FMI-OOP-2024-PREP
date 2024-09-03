#pragma once
#include "HexArray.h"

class Serializator
{
protected:
	char fileName[128];
	const HexArray& arr;

public:
	Serializator(const char* str, const HexArray& arr);

	virtual void serialize() = 0;
	virtual Serializator* clone() const = 0;

	virtual ~Serializator() = default;
};

