#pragma once
#include <iostream>
#include <fstream>

class GrString
{
private:
	char* data;
	size_t size;

	void copyFrom(const GrString& other);
	void moveFrom(GrString&& other);
	void free();

public:
	GrString();
	GrString(const char* data);

	GrString(const GrString& other);
	GrString& operator=(const GrString& other);

	GrString(GrString&& other) noexcept;
	GrString& operator=(GrString&& other) noexcept;

	~GrString();

	const char* c_str() const;
	size_t length() const;

	GrString& operator+=(const GrString& rhs);
	GrString& operator/=(const GrString& rhs);

	friend std::istream& operator>>(std::istream& is, GrString& obj);
};

GrString operator+(const GrString& lhs, const GrString& rhs);
GrString operator/(const GrString& lhs, const GrString& rhs);
bool operator==(const GrString& lhs, const GrString& rhs);

