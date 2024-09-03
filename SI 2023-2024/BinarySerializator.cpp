#include "BinarySerializator.h"

BinarySerializator::BinarySerializator(const char* str, const HexArray& arr)
	: Serializator(str, arr) {}

void BinarySerializator::serialize()
{
	std::ofstream ofs(fileName, std::ios::binary);
	ofs.write((const char*)arr.c_str(), arr.getSize());
}

Serializator* BinarySerializator::clone() const
{
	return new BinarySerializator(*this);
}

