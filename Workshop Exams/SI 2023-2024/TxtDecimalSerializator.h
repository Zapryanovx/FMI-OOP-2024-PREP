#pragma once
#include "Serializator.h"

class TxtDecimalSerializator: public Serializator
{
public:
	TxtDecimalSerializator(const char* str, const HexArray& arr);

	void serialize() override;
	Serializator* clone() const override;
};

