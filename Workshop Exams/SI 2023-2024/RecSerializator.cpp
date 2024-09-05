#include "RecSerializator.h"

RecSerializator::RecSerializator(const char* str, const HexArray& arr): Serializator(str, arr)
{
	std::ifstream ifs(str);
	char recFileName[128];
	ifs >> recFileName;

	 ser = serializatorFactory(arr, recFileName);
}

void RecSerializator::serialize()
{
	ser->serialize();
}

Serializator* RecSerializator::clone() const
{
	return new RecSerializator(*this);
}

RecSerializator::RecSerializator(const RecSerializator& other) : Serializator(other)
{
	ser = other.ser->clone();
}

RecSerializator::~RecSerializator()
{
	delete ser;
}
