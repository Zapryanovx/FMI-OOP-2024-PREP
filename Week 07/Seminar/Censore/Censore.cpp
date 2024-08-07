#include "Censore.h"

Censore::Censore(bool (*pred)(char), std::ostream& os): pred(pred), os(os){}

Censore& operator<<(Censore& c, const char* str)
{
	while (*str)
	{

		//ако функцията с подаден символ от стринга върне true, се цензурира
		if (c.pred(*str))
		{
			c.os << '*';
		}

		//ако функцията с подаден символ от стринга върне false, се запазва 
		else
		{
			c.os << *str;
		}

		//минаваме на следващия символ от str
		++str;
	}

	return c;
}