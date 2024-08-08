#include "ImmutableString.h"
#pragma warning(disable: 4996)

StringPool ImmutableString::_pool;

ImmutableString::ImmutableString(const char* data)
{
	_data = _pool.getAllocatedString(data);
	_length = strlen(_data);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	copyFrom(other);
}

ImmutableString::~ImmutableString()
{
	free();
}

void ImmutableString::free()
{
	_pool.releaseString(_data);
	_data = nullptr;
}

void ImmutableString::copyFrom(const ImmutableString& other)
{
	_data = _pool.getAllocatedString(other._data);
	_length = other._length;
}

size_t ImmutableString::length() const
{
	return _length;
}

const char* ImmutableString::c_str() const
{
	return _data;
}

char ImmutableString::operator[](size_t index) const
{
	return _data[index];
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
	return os << str.c_str();
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

