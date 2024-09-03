#include "TxtDecimalDeserializator.h"

TxtDecimalDeserializator::TxtDecimalDeserializator(const char* str): Deserializator(str){}

HexArray TxtDecimalDeserializator::deserialize() const
{
	std::ifstream ifs(fileName);
	size_t size = getCharCount(ifs, ' ') + 1;
	unsigned char* res = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		int tempByte;
		ifs >> tempByte;
		res[i] = tempByte;
	}

	return HexArray(res, size);
}

