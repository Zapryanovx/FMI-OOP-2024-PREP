#pragma once
#include "HexArray.h"

class Deserializator
{
protected:
	char fileName[128];

public:
	Deserializator(const char* str);

	virtual HexArray deserialize() const = 0;
	
	virtual ~Deserializator() = default;
};

