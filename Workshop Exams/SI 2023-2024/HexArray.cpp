#include "HexArray.h"

void HexArray::copyFrom(const HexArray& other)
{
	size = other.size;
	data = createAndFillByteArray(size, other.data, other.size);
}

void HexArray::moveFrom(HexArray&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;
}

void HexArray::free()
{
	delete[] data;
}

HexArray::HexArray(const unsigned char* initData, size_t initSize)
{
	size = initSize;
	data = createAndFillByteArray(size, initData, initSize);
}

HexArray::HexArray(const HexArray& other)
{
	copyFrom(other);
}

HexArray& HexArray::operator=(const HexArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

HexArray::HexArray(HexArray&& other) noexcept
{
	moveFrom(std::move(other));
}

HexArray& HexArray::operator=(HexArray&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

HexArray::~HexArray()
{
	free();
}

const unsigned char* HexArray::c_str() const
{
	return data;
}

size_t HexArray::getSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const HexArray& arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		if (isValidSymbol(arr.data[i]))
		{
			os << std::hex << arr.data[i];
		}
		
		else
		{
			os << '.' << " ";
		}
	}

	os << std::endl;

	for (int i = 0; i < arr.size; i++)
	{
		os << std::hex << (int)arr.data[i] << " ";
	}

	return os;
}
