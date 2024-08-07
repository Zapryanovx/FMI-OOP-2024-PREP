//#ОБЯСНЕНИЕ НА ЗАДАЧАТА
// 
//Да се реализира клас String за работа с низове.Класът трябва да поддържа :
//
//Конструктор по подразбиране
//Конвертиращ конструктор от const char*
//Оператор == (и съответно != ).
//Оператрор < .
//Оператор за конкатенация на два низа(+, +=).
//Оператор за достъп на елемент на подаден индекс([])
//Функция за получаване на c style указател.
//Оператор за записване и четене на низ от поток(<< и >> ).

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	MyString test = "test str";

	std::cout << test << " ";
	std::cout << test.getSize() << " " << test.getCapacity() << std::endl;

	MyString test2;
	std::cin >> test2;

	MyString test3 = test + test2;
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;

	test3 += test3;
	//std::cout << test3;

	return 0;
}