#pragma once
#include "Deserializator.h"

class TxtDecimalDeserializator: public Deserializator
{
public:
	TxtDecimalDeserializator(const char* str);

	HexArray deserialize() const override;
};

