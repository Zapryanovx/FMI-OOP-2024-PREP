#include "GrString.h"
#include "Utils.h"
#pragma warning(disable: 4996)

void GrString::copyFrom(const GrString& other)
{
	size = other.size;
	
	data = new char[other.size + 1];
	std::strcpy(data, other.data);
	data[size] = '\0';

}

void GrString::moveFrom(GrString&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	other.size = 0;
}

void GrString::free()
{
	delete[] data;
	data = nullptr;
}

GrString::GrString()
{
	this->size = 32;
	this->data = new char[size + 1];
	this->data[0] = '\0';

}

GrString::GrString(const char* data)
{
	this->size = std::strlen(data);
	this->data = new char[size + 1];
	std::strcpy(this->data, data);
	this->data[size] = '\0';

}

GrString::GrString(const GrString& other)
{
	copyFrom(other);
}

GrString& GrString::operator=(const GrString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

GrString::GrString(GrString&& other) noexcept
{
	moveFrom(std::move(other));
}

GrString& GrString::operator=(GrString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

GrString::~GrString()
{
	free();
}

const char* GrString::c_str() const
{
	return data;
}

size_t GrString::length() const
{
	return size;
}

GrString& GrString::operator+=(const GrString& rhs)
{
	size_t newSize = size + rhs.size;
	char* newData = new char[newSize + 1];
	newData[0] = '\0';

	std::strcat(newData, data);
	std::strcat(newData, rhs.data);

	free();
	data = newData;
	size = newSize;

	return *this;
}

GrString operator+(const GrString& lhs, const GrString& rhs)
{
	GrString res(lhs);
	res += rhs;
	return res;
}

bool operator==(const GrString& lhs, const GrString& rhs)
{
	return weightOf(lhs.c_str()) == weightOf(rhs.c_str());
}

std::istream& operator>>(std::istream& is, GrString& obj)
{
	char buff[1024];
	is >> buff;
	size_t buffSize = std::strlen(buff);

	std::strcpy(obj.data, buff);
	obj.size = buffSize;

	return is;
}

GrString& GrString::operator/=(const GrString& rhs)
{
	diff(data, rhs.data);
	size = std::strlen(data);

	return *this;
}

GrString operator/(const GrString& lhs, const GrString& rhs)
{
	GrString res(lhs);
	res /= rhs;
	return res;
}