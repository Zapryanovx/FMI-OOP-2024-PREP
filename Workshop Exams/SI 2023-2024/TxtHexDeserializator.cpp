#include "TxtHexDeserializator.h"
#include "Utils.h"

TxtHexDeserializator::TxtHexDeserializator(const char* str): Deserializator(str){}

HexArray TxtHexDeserializator::deserialize() const
{
	std::ifstream ifs(fileName);
	size_t size = getCharCount(ifs, ' ') + 1;
	unsigned char* res = new unsigned char[size];

	for (int i = 0; i < size; i++)
	{
		int tempByte;
		ifs >> std::hex >> tempByte;
		res[i] = tempByte;
	}

	return HexArray(res, size);
}