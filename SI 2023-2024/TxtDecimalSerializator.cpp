#include "TxtDecimalSerializator.h"

TxtDecimalSerializator::TxtDecimalSerializator(const char* str, const HexArray& arr)
	: Serializator(str, arr){}

void TxtDecimalSerializator::serialize()
{
	std::ofstream ofs(fileName);

	for (int i = 0; i < arr.getSize(); i++)
	{
		ofs << static_cast<int>(arr.c_str()[i]) << " ";
	}
}

Serializator* TxtDecimalSerializator::clone() const
{
	return new TxtDecimalSerializator(*this);
}

