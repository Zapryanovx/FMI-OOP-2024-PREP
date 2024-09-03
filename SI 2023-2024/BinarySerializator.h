#pragma once
#include "Serializator.h"

class BinarySerializator : public Serializator
{
public:
	BinarySerializator(const char* str, const HexArray& arr);

	void serialize() override;
	Serializator* clone() const override;
};

