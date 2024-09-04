#include "MulString.h"

int main()
{
	MulString first("abcd");
	MulString second("bctttt");
	std::cout << first.c_str() << std::endl;

	first *= 3;

	std::cout << first.c_str() << std::endl;

	std::ofstream ofs("text.txt");
	ofs << first;
	ofs.close();

	MulString fourth("abcd");

	MulString fifth = (first % second);

	std::cout << (first != fourth) << std::endl;
	std::cout << (first != second) << std::endl;

	std::cout << fifth.c_str() << std::endl;
	std::cout << fifth << std::endl;

	return 0;
}