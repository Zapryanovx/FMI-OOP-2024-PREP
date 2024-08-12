//#ОБЯСНЕНИЕ НА ЗАДАЧАТА
// 
// Пример с човек, студент и преподавател

#include "Person.h"
#include "Teacher.h"
#include "Student.h"

int main()
{

	char subjects[3][20] = { "English", "Mathematics", "Physics" };

	char** subjectsPointers = new char* [3];
	subjectsPointers[0] = subjects[0];
	subjectsPointers[1] = subjects[1];
	subjectsPointers[2] = subjects[2];

	Teacher t("Prof. Ivanov", 33, subjectsPointers, 3);

	std::cout << t.getName() << std::endl;

	//трябва да изтрием масива (вече сме го копирали в [t]),
	//но не и съдържанието му, тъй като го използваме в [t]
	//и в Teacher се грижим да бъде изтрито

	delete[] subjectsPointers; //only the pointers - not the data!

	return 0;
}