#pragma once
#include <iostream>
#include <fstream>

class MulString
{
private:
	char* data;
	size_t size;

	void copyFrom(const MulString& other);
	void moveFrom(MulString&& other);
	void free();

public:
	MulString();
	MulString(const char* data);

	MulString(const MulString& other);
	MulString& operator=(const MulString& other);

	MulString(MulString&& other) noexcept;
	MulString& operator=(MulString&& other) noexcept;

	~MulString();

	const char* c_str() const;
	size_t length() const;

	MulString& operator*=(size_t k);
	MulString& operator%=(const MulString& rhs);

	friend std::ostream& operator<<(std::ostream& os, const MulString& obj);
};

MulString operator*(const MulString& lhs, size_t k);
bool operator!=(const MulString& lhs, const MulString& rhs);
MulString operator%(const MulString& lhs, const MulString& rhs);


