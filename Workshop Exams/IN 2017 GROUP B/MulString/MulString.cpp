#include "MulString.h"
#include "Utils.h"
#pragma warning(disable: 4996)

void MulString::copyFrom(const MulString& other)
{
	size = other.size;
	data = new char[size + 1];
	std::strcpy(data, other.data);
}

void MulString::moveFrom(MulString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;
}

void MulString::free()
{
	delete[] data;
	data = nullptr;
}

MulString::MulString()
{
	size = 8;
	data = new char[size + 1];
	data[0] = '\0';
}

MulString::MulString(const char* str)
{
	size = std::strlen(str);
	data = new char[size + 1];
	std::strcpy(data, str);
}

MulString::MulString(const MulString& other)
{
	copyFrom(other);
}

MulString& MulString::operator=(const MulString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MulString::MulString(MulString&& other) noexcept
{
	moveFrom(std::move(other));
}

MulString& MulString::operator=(MulString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MulString::~MulString()
{
	free();
}

const char* MulString::c_str() const
{
	return data;
}

size_t MulString::length() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const MulString& obj)
{
	return os << obj.data;
}

MulString& MulString::operator*=(size_t k)
{
	multi(data, k);
	size = std::strlen(data);
	return *this;
}

MulString operator*(const MulString& obj, size_t k)
{
	MulString res(obj);
	res *= k;
	return res;
}

MulString& MulString::operator%=(const MulString& rhs)
{
	const char* res = unionOf(data, rhs.data);
	size = std::strlen(res);
	
	free();
	data = new char[size + 1];
	std::strcpy(data, res);

	return *this;
}

MulString operator%(const MulString& lhs, const MulString& rhs)
{
	MulString res(lhs);
	res %= rhs;
	return res;
}

bool operator!=(const MulString& lhs, const MulString& rhs)
{
	return weightOf(lhs.c_str()) != weightOf(rhs.c_str());
}
