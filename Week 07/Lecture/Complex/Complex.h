#pragma once
#include <iostream>

class Complex
{
private:
	double real;
	double im;

public:
	Complex();
	Complex(double real, double im);

	double getReal() const;
	double getIm() const;

	void setReal(double newReal);
	void setIm(double newIm);

	//комплексно спрегнато
	Complex getConjugated() const; 

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	friend std::ostream& operator<<(std::ostream& ofs, const Complex& r);
	friend std::istream& operator>>(std::istream& ifs, Complex& r);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);


