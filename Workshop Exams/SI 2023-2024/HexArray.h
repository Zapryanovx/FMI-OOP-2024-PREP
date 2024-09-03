#pragma once
#include <iostream>
#include <sstream>
#include "Utils.h"

class HexArray
{
private:
	unsigned char* data = nullptr;
	size_t size = 0;

	void copyFrom(const HexArray& other);
	void moveFrom(HexArray&& other);
	void free();

public:
	HexArray(const unsigned char* initData, size_t initSize);

	HexArray(const HexArray& other);
	HexArray& operator=(const HexArray& other);

	HexArray(HexArray&& other) noexcept;
	HexArray& operator=(HexArray&& other) noexcept;
	
	~HexArray();

	const unsigned char* c_str() const;
	size_t getSize() const;

	template<typename T>
	friend void operator>>(const T& toSerialize, HexArray& arr);

	friend std::ostream& operator<<(std::ostream& os, const HexArray& arr);
};

template <typename T>
void operator>>(const T& toSerialize, HexArray& arr)
{
	unsigned char* newData = createAndFillByteArray(arr.size + sizeof(T), arr.data, arr.size);
	
	std::stringstream ss;
	ss.write((const char*)(&toSerialize), sizeof(T));
	ss.read((char*) (newData + arr.size), sizeof(T));

	delete[] arr.data;
	arr.data = newData;
	arr.size += sizeof(T);
}

