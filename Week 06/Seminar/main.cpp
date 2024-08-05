//#ОБЯСНЕНИЕ НА ЗАДАЧАТА
// 
//Напишете клас BitSet, който съдържа множество от числа (без повторения) в диапазона от 0 до n-1, 
//където n е подадено в началото (1 <= n <= 1000).
// 
// Класът трябва да пази дали съдържа дадено число в битове,
// т.е ако съдържа дадено число, съответвеният последователен бит ще бъде 1, в противен случай 0. 
// 
// Пример:
//{3, 4, 6} = > битове на множеството ще бъдат 00011010
//{1, 8, 9} = > 01000000 11000000
//
//Класът трябва да има следните функции.
//
//- Добавяне на число
//- Проверка дали съдържа число
//- Принтиране на всички числа, които съдържа
//- Член-функция, която приема друго множество и връща тяхното обединение
//- Член-функция, която приема друго множество и връща тяхното сечение


#pragma once
#include <iostream>
#include "BitSet.h"

int main()
{
	BitSet powersOfTwo(17);
	powersOfTwo.addNumber(1);
	powersOfTwo.addNumber(2);
	powersOfTwo.addNumber(4);
	powersOfTwo.addNumber(8);
	powersOfTwo.addNumber(16);

	BitSet even(17);
	for (size_t i = 0; i < 17; i += 2)
		even.addNumber(i);

	powersOfTwo.print();
	even.print();

	BitSet evenPowerUnion = Union(even, powersOfTwo);
	evenPowerUnion.print();

	BitSet evenPowerIntersect = Intersect(even, powersOfTwo);
	evenPowerIntersect.print();

	powersOfTwo.removeNumber(1);
	powersOfTwo.removeNumber(16);
	powersOfTwo.print();

	return 0;
}