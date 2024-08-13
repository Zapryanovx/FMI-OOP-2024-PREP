#pragma once
#include "DynamicSet.h"

class SetByString: private DynamicSet
{
	char* str;

	void extractNumberFromString();
	
	void copyFrom(const SetByString& other);
	void moveFrom(SetByString&& other);
	void free();

public:
	SetByString(unsigned n, const char* data);

	SetByString(const SetByString& other);
	SetByString(SetByString&& other) noexcept;

	SetByString& operator=(const SetByString& other);
	SetByString& operator=(SetByString&& other) noexcept;

	~SetByString();

	bool contains(int i) const;
	void print() const;
	void setAt(unsigned ind, char ch);
};

