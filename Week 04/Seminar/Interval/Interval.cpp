#include "Interval.h"

void Interval::setA(int a)
{
	if (a > _b)
	{
		_a = 0;
		_b = 0;
	}

	_a = a;
}

void Interval::setB(int b)
{
	if (b < _a)
	{
		_a = 0;
		_b = 0;
 	}

	_b = b;
}

int Interval::getA() const
{
	return _a;
}

int Interval::getB() const
{
	return _b;
}

Interval::Interval(): Interval(0, 0) {}

Interval::Interval(int a, int b)
{
	setA(a);
	setB(b);
}

bool Interval::isInInterval(int x) const
{
	return _a <= x && x <= _b;
}

namespace HelperFunctions
{
	bool isPrime(int n)
	{
		if (n < 2)
		{
			return false;
		}

		double temp = sqrt(n);

		for (int i = 2; i <= temp; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}

		return true;
	}

	int reverse(int n)
	{
		int reversed = 0;

		while (n != 0)
		{
			reversed = reversed * 10 + n % 10;
			n /= 10;
		}

		return reversed;
	}

	bool isPalindrome(int n)
	{
		return n == reverse(n);
	}
}

unsigned Interval::getCountCondition(bool(*predicate)(int)) const
{
	size_t count = 0;
	for (int i = _a; i < _b; i++)
	{
		if (predicate(i))
		{
			count++;
		}
	}

	return count;
}

unsigned Interval::getPrimesCount() const
{
	return getCountCondition(HelperFunctions::isPrime);
}

unsigned Interval::getPalindromeCount() const
{
	return getCountCondition(HelperFunctions::isPalindrome);
}

bool Interval::isSubinterval(const Interval& other) const
{
	return _a >= other._a && _b <= other._b;
}

Interval intersectIntervals(const Interval& lhs, const Interval& rhs)
{
	int newA = std::max(lhs.getA(), rhs.getA());
	int newB = std::min(lhs.getB(), rhs.getB());

	if (newA > newB)
	{
		std::cout << "here" << std::endl;
		throw "Error";
	}

	Interval toReturn(newA, newB);
	return toReturn;
}