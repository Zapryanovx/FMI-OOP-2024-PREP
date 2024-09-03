#pragma once
#include "Serializator.h"

class RecSerializator: public Serializator
{
private:
	Serializator* ser;

public:
	RecSerializator(const char* str, const HexArray& arr);
	RecSerializator(const RecSerializator& other);
	~RecSerializator();

	void serialize() override;
	Serializator* clone() const override;

};

