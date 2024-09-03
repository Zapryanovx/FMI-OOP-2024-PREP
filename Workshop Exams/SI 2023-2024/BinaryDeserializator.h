#pragma once
#include "Deserializator.h"

class BinaryDeserializator: public Deserializator
{
public:
	BinaryDeserializator(const char* str);

	HexArray deserialize() const override;
};

