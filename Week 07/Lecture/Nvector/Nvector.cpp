#include "NVector.h"

NVector::NVector(size_t n) : size(n)
{
	data = new int[n];

	//default vector
	for (int i = 0; i < n; i++)
	{
		data[i] = 0;
	}
}

NVector::NVector(const NVector& other)
{
	copyFrom(other);
}

NVector& NVector::operator=(const NVector& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

NVector::~NVector()
{
	free();
}

void NVector::copyFrom(const NVector& other)
{
	size = other.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}

}

void NVector::free()
{
	delete[] data;
	size = 0;
}

NVector& NVector::operator+=(const NVector& other)
{
	if (size != other.size)
	{
		throw std::exception("The vectors should have the same size!");
	}

	for (int i = 0; i < size; i++)
	{
		data[i] += other.data[i];
	}

	return *this;
}

NVector& NVector::operator-=(const NVector& other)
{
	if (size != other.size)
	{
		throw std::exception("The vectors should have the same size!");
	}

	for (int i = 0; i < size; i++)
	{
		data[i] -= other.data[i];
	}

	return *this;
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{
	NVector toReturn(lhs);
	toReturn += rhs;
	return toReturn;

}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
	NVector toReturn(lhs);
	toReturn -= rhs;
	return toReturn;
}

int& NVector::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	return data[index];
}

int NVector::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	return data[index];
}

size_t NVector::operator~() const
{
	return size;
}

std::ostream& operator<<(std::ostream& os, const NVector& v)
{
	os << "[ ";
	for (int i = 0; i < v.size; i++)
	{
		os << v[i] << " ";
	}
	os << "]";

	return os;
}


//'[', ']' handling ?
std::istream& operator>>(std::istream& is, NVector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		is >> v[i];
	}

	return is;
}

bool operator||(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs)
	{
		throw std::exception("The vectors should have the same size!");
	}
	
	//два вектора са успоредни, когато единият е равен на скалар по другия
	double ratio = 0.0;
	bool ratioSet = false;

	for (int i = 0; i < ~lhs; i++)
	{
		
		//нататък, за да намерим отношението на съответните координати
		//ще се наложи да разделим на нула, затова ни трябват предварителни проверки
		if (lhs[i] == 0 && rhs[i] == 0)
		{
			continue;
		}

		//ако някое е 0, а другото не, не са успоредни
		if (lhs[i] == 0 || rhs[i] == 0)
		{
			return false;
		}

		double currRatio = lhs[i] / rhs[i];

		if (!ratioSet)
		{
			ratio = currRatio;
			ratioSet = true;
		}

		else if (std::abs(ratio - currRatio) > 1e-6)
		{
			return false;
		}
	}

	return true;
}

NVector& NVector::operator*=(size_t scalar)
{
	for (int i = 0; i < size; i++)
	{
		data[i] *= scalar;
	}

	return *this;
}


//имаме две възможности: scalar * vector или vector * scalar
NVector operator*(const NVector& lhs, size_t scalar)
{
	NVector toReturn(lhs);
	toReturn *= scalar;
	return toReturn;
}

//можем да преизползваме горния оператор, за да избегнем повтаряне на код
NVector operator*(size_t scalar, const NVector& lhs)
{
	return lhs * scalar;
}

//скаларно умножение - координат * координат
size_t operator%(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs)
	{
		throw std::exception("The vectors should have the same size!");
	}

	size_t res = 0;
	for (int i = 0; i < ~lhs; i++)
	{
		res += (lhs[i] * rhs[i]);
	}

	return res;
}

//два вектора са перпендикулярни, ако скаларното им е 0
bool operator|=(const NVector& lhs, const NVector& rhs)
{
	return lhs % rhs == 0;
}