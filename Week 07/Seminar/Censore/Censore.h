#pragma once
#include <iostream>
#include <fstream>

class Censore
{
private:
	std::ostream& os;
	bool(*pred)(char);
public:
	Censore(bool(*pred)(char), std::ostream& os);

	friend Censore& operator<<(Censore& c, const char* str);
};

