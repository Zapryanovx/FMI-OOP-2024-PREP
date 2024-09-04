#include "Dictionary.h"

int main()
{
	Dictionary dictOne;
	Dictionary dictTwo;

	dictOne.add("word", "desc");
	dictOne.add("wordTwo", "descTwo");
	dictOne.add("wordThree", "descThree");
	dictOne.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	dictOne.remove("word");
	dictOne.add("wordTwo", "test");
	dictOne.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	dictTwo.add("wordTwo", "2222");

	Dictionary dictThree = dictOne + dictTwo;
	dictThree.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	dictOne += dictTwo;
	dictOne.print();




	return 0;
}