//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

//Напишете програма, която работи с рационални числа. 
//Програмата трябва да поддържа 
// -събиране
// -извличане
// -умножение 
// -деление 
//
//на две рационални числа.
// 
//-имплементирайте функция, която връща дали две рационални числа са равни.
//-имплементиране на функция, която отпечатва рационално число

#include <iostream>

//тъй като рационалните числа представляват обикновени дроби,
//те се състоят от две части - числител и знаменател,
//затова ще създадем наш нов тип чрез употребата на структора - 'Rational',
//който да съдържа именно тези две части

struct Rational
{
	int64_t numerator; //числител 
	int64_t denominator; //знаменател
};

//алгоритъм за намиране на НОД на две числа (рекурсия)
int64_t gcd(int64_t a, int64_t b)
{
	a = std::abs(a);
	b = std::abs(b);

	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

//функция, чрез която ще опростим обикновените дроби, с които работим
void cannonicalizeNumber(Rational& num)
{
	int64_t greatedCommonDivisor = gcd(num.numerator, num.denominator);
	
	num.numerator /= greatedCommonDivisor;
	num.denominator /= greatedCommonDivisor;

	//в случай, че числителят и знаменателят са отрицателни числа,
	//можем да опростим дробта чрез премахването на излишните знаци, т.е.

	if (num.numerator < 0 && num.denominator < 0)
	{
		num.numerator *= -1;
		num.denominator *= -1;
	}

}

//ще добавим функционалността да можем да подаваме единствено числител,
//когато създаваме дроб, като по подразбиране направим знаменателя да е 1,
//тъй като N ⊆ Q (с други думи всяко естествено число е рационално)
Rational createRational(int64_t numerator, int64_t denominator = 1)
{
	Rational res = Rational{ numerator, denominator };

	//опростяваме новосъздадената дроб
	cannonicalizeNumber(res);

	return res;
}

Rational sum(const Rational& first, const Rational& second)
{
	return createRational(first.numerator * second.denominator + second.numerator * first.denominator, //числител
				          first.denominator * second.denominator); //знаменател
}

Rational negativeOf(const Rational& num)
{
	return createRational(-num.numerator, num.denominator);
}

Rational subtract(const Rational& first, const Rational& second)
{
	//тъй като вече сме имплементирали функцията за събиране, то можем да я преизползваме,
	//като просто я извикаме с параметри (first, -second), тъй като first - second = first + (-second), т.е.

	return sum(first, negativeOf(second));
}

Rational multiply(const Rational& first, const Rational& second)
{
	return createRational(first.numerator * second.numerator,
						  first.denominator * second.denominator);
}

Rational divide(const Rational& first, const Rational& second)
{
	//тъй като вече сме имплементирали функцията за умножение, то можем да я преизползваме,
	//като просто я извикаме с параметри (first, 1/second), тъй като first / second = first *  (1 / second), т.е.

	return multiply(first, createRational(second.denominator, second.numerator));
}

void printRational(const Rational& num)
{
	std::cout << num.numerator;

	//ако знаменателят е 1, няма смисъл да го отпечатваме,
	//тъй като числото е цяло
	if (num.denominator != 1)
	{
		std::cout << "/" << num.denominator;
	}

	std::cout << std::endl;
}

int main()
{
	//припормняме двата начина за инициализация
	Rational first{ 7, 2 };
	Rational second = { 3, 4 };

	Rational sumRes = sum(first, second);
	Rational subtractRes = subtract(first, second);
	Rational multiplyRes = multiply(first, second);
	Rational divideRes = divide(first, second);

	printRational(sumRes);
	printRational(subtractRes);
	printRational(multiplyRes);
	printRational(divideRes);
}

