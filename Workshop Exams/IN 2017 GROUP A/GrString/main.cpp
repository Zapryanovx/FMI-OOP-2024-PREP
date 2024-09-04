#include "GrString.h"

int main()
{
	GrString first("abcd");
	GrString second("bc");

	first += second;

	first /= second;

	std::cout << first.c_str() << std::endl;

	GrString third;

	std::ofstream ofs("text.txt");
	ofs << "text";
	ofs.close();

	std::ifstream ifs("text.txt");
	ifs >> third;
	ifs.close();

	std::cout << third.c_str() << std::endl;

	GrString fourth("abcd");

	std::cout << (first == fourth) << std::endl;
	std::cout << (first == second) << std::endl;


	return 0;
}