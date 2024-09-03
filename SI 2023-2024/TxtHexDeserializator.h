#pragma once
#include "Deserializator.h"

class TxtHexDeserializator: public Deserializator
{
public:
	TxtHexDeserializator(const char* str);

	HexArray deserialize() const override;

};

