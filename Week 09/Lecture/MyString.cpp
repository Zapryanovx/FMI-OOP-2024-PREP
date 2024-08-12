#include "MyString.h"
#include "MyString.h"
#include <cstring>
#include <algorithm>
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;

	return v;
}

static unsigned dataToAllocByStringLen(unsigned stringLength)
{
	return std::max(roundToPowerOfTwo(stringLength + 1), 16u); // + '\0'
}

void MyString::resize(unsigned newAllocatedDataSize)
{
	char* newData = new char[newAllocatedDataSize];
	std::strcpy(newData, _data);
	delete[] _data;
	_data = newData;
	_allocatedDataSize = newAllocatedDataSize;
}

//big four
// 
// 
//default-ният конструктор извиква друг с параметър const char*
MyString::MyString() : MyString("") {}

MyString::MyString(const char* data)
{
	//size - текущ размер

	//allocatedDataSize - общ размер
	//(нещо като максимален размер, който може обаче да се увеличава)

	_size = std::strlen(data);
	_allocatedDataSize = dataToAllocByStringLen(_size);
	_data = new char[_allocatedDataSize];
	std::strcpy(_data, data);

}

MyString::MyString(size_t stringLength)
{
	_allocatedDataSize = dataToAllocByStringLen(stringLength);
	_size = 0;

	_data = new char[_allocatedDataSize];
	_data[0] = '\0';
}

void MyString::copyFrom(const MyString& other)
{
	_allocatedDataSize = other._allocatedDataSize;
	_size = other._size;

	_data = new char[_allocatedDataSize];
	std::strcpy(_data, other._data);
}

void MyString::free()
{
	delete[] _data;
	_size = _allocatedDataSize = 0;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

void MyString::moveFrom(MyString&& other)
{

	//крадем пойнтъра и го правим на nullptr, за да нямаме 2 пойнтъра към една и съща памет
	_data = other._data;
	other._data = nullptr;

	//крадем размера и капацитета
	_size = other._size;
	_allocatedDataSize = other._allocatedDataSize;
	
	//добра практика
	other._size = other._allocatedDataSize = 0;

}

MyString::MyString(MyString&& other) noexcept
{
	//помним, че макар и rvalue reference,
	//other се третира като lvalue в тялото на функцията
	//и трябва да използваме std::move, за да го превърнем в xvalue
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();

		//помним, че макар и rvalue reference,
		//other се третира като lvalue в тялото на функцията
		//и трябва да използваме std::move, за да го превърнем в xvalue
		moveFrom(std::move(other));
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

//selectors
size_t MyString::getCapacity() const
{
	return _allocatedDataSize - 1;
}

size_t MyString::getSize() const
{
	return _size;
}

const char* MyString::c_str() const
{
	return _data;
}

//predefined operators
MyString& MyString::operator+=(const MyString& other)
{
	if (_size + other._size + 1 > _allocatedDataSize)
	{
		resize(dataToAllocByStringLen(_size + other._size));
	}

	//[!] ако използваме strcat ще залепим и празните клетки на other._data, тъй като
	//няма да уточним броя на клетките, които искаме да залепим, което може да доведе до грешка,
	//тъй като има шанс да нямаме достатъчно other._allocatedDataSize място в _data 
	std::strncat(_data, other._data, other._size);
	_size += other._size;

	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	//MyString toReturn(lhs);
	//toReturn += rhs;
	//return toReturn;

	MyString toReturn(lhs.getSize() + rhs.getSize());
	toReturn += lhs;
	toReturn += rhs;
	return toReturn;
}

char& MyString::operator[](size_t index)
{
	//no security check
	return _data[index];
}

const char& MyString::operator[](size_t index) const
{
	//no security check
	return _data[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
	return os << obj._data;
}

std::istream& operator>>(std::istream& is, MyString& ref)
{
	//четем съдържанието на файла
	char buff[1024];
	is >> buff;
	size_t buffStringSize = std::strlen(buff);

	//ако не може да се побере в ref, увеличаваме капацитета на ref
	if (buffStringSize > ref.getCapacity())
	{
		ref.resize(dataToAllocByStringLen(buffStringSize));
	}

	//запазваме съдържанието на файла в ref
	strcpy(ref._data, buff);
	ref._size = buffStringSize;
	return is;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}