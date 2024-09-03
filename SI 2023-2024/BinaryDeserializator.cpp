#include "BinaryDeserializator.h"

BinaryDeserializator::BinaryDeserializator(const char* str): Deserializator(str){}

HexArray BinaryDeserializator::deserialize() const
{
	std::ifstream ifs(fileName, std::ios::binary);
	size_t size = getFileSize(ifs);
	
	unsigned char* res = new unsigned char[size];
	ifs.read((char*)res, size);

	return HexArray(res, size);
}