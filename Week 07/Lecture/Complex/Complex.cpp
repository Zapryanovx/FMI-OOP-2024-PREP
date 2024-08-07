#include "Complex.h"

Complex::Complex()
{
	real = 0.00;
	im = 0.00;
}

Complex::Complex(double real, double im)
{
	this->real = real;
	this->im = im;
}

Complex& Complex::operator+=(const Complex& other)
{
	this->real += other.real;
	this->im += other.im;

	return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
	this->real -= other.real;
	this->im -= other.im;

	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	//Ex.:
	//(3 + 5i) * (2 + 3i) = (3 * 2) + (3 * 3i) + (5i * 2) + (5i * 3i)
	//                     real part   im part    im part    real part
	//                    
	double oldReal = real;
	real = real * other.real - im * other.im;
	im = oldReal * other.im + im * other.real;

	return *this;
}


Complex& Complex::operator/=(const Complex& other)
{
	Complex conjugated = other.getConjugated();
	Complex otherCopy(other);
	
	//числител
	*this *= conjugated;

	//следвайки формулата тук трябва да остане само реална част (знаменател)
	otherCopy *= conjugated;
	
	//извършваме делението между числителя и знаменателя
	if (otherCopy.real != 0)
	{
		real /= other.real;
		im /= other.real;
	}

	return *this;
}

//можем за преизползваме операторите +=, -=, *=, /=

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex res(lhs);
	res += rhs;

	return res;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex res(lhs);
	res -= rhs;

	return res;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex res(lhs);
	res *= rhs;

	return res;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex res(lhs);
	res /= rhs;

	return res;
}

Complex Complex::getConjugated() const
{
	Complex res(*this);
	res.im *= -1;

	return res;
}

double Complex::getReal() const
{
	return real;
}

double Complex::getIm() const
{
	return im;
}

void Complex::setReal(double newReal)
{
	real = newReal;
}

void Complex::setIm(double newIm)
{
	im = newIm;
}

std::ostream& operator<<(std::ostream& ofs, const Complex& r)
{
	return ofs << r.real << ' ' << r.im << 'i';
}

std::istream& operator>>(std::istream& ifs, Complex& r)
{
	return ifs >> r.real >> r.im;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
	return lhs.getReal() == rhs.getReal() && lhs.getIm() == rhs.getIm();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}









