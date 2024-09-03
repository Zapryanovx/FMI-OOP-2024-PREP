#pragma once
#include "Serializator.h"

class TxtHexSerializator: public Serializator
{
public:
	TxtHexSerializator(const char* str, const HexArray& arr);

	void serialize() override;
	Serializator* clone() const override;
};

