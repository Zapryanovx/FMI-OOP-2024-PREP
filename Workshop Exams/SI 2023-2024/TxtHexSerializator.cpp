#include "TxtHexSerializator.h"

TxtHexSerializator::TxtHexSerializator(const char* str, const HexArray& arr)
	: Serializator(str, arr){}

void TxtHexSerializator::serialize() 
{
	std::ofstream ofs(fileName);

	for (int i = 0; i < arr.getSize(); i++)
	{
		ofs << std::hex << arr.c_str()[i] << " ";
	}
}

Serializator* TxtHexSerializator::clone() const
{
	return new TxtHexSerializator(*this);
}

