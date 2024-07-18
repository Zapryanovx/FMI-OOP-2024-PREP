//Задача 3:

//- Да се напише initStudent(...),
//която приема като параметри имената, факултетния номер, средния успех и специалността на студента
//Функцията трябва да върне студент с тези входни данни.
//- Да се напише функция, която създава студент четейки данни от конзолата.
//(Можете да си създадете помощни функции)

#include <iostream>

enum class Major
{
	SI = 1,
	KN,
	IS,
	INF
};

struct Student
{
	char firstName[16];
	char lastName[16];
	int facultyNum;
	double avgGrade;
	Major major;

};

void myStrCopyFirstName(Student& student, const char strFrom[])
{
	int size = 0;
	while (strFrom[size++]);

	for (int i = 0; i < size; i++)
	{
		student.firstName[i] = strFrom[i];
	}
	student.firstName[size] = '\0';
}

void myStrCopyLastName(Student& student, const char strFrom[])
{
	int size = 0;
	while (strFrom[size++]);

	for (int i = 0; i < size; i++)
	{
		student.lastName[i] = strFrom[i];
	}
	student.lastName[size] = '\0';
}

Student initStudent(const char firstNameInput[], const char lastNameInput[],
	const int facultyNumInput, const double avgGradeInput, const Major& MajorInput)
{
	Student studentRes;
	myStrCopyFirstName(studentRes, firstNameInput);
	myStrCopyLastName(studentRes, lastNameInput);

	studentRes.facultyNum = facultyNumInput;
	studentRes.avgGrade = avgGradeInput;

	studentRes.major = MajorInput;

	return studentRes;
}

void printStudent(const Student& student)
{
	std::cout << "First name: " << student.firstName << std::endl;
	std::cout << "Last name: " << student.lastName << std::endl;
	std::cout << "Faculty number: " << student.facultyNum << std::endl;
	std::cout << "Average grade: " << student.avgGrade << std::endl;

	switch (student.major)
	{
		case Major::SI:
			std::cout<< "Major: SI" << std::endl;
			break;
		case Major::KN:
			std::cout << "Major: KN" << std::endl;
			break;

		case Major::IS:
			std::cout << "Major: IS" << std::endl;
			break;

		case Major::INF:
			std::cout << "Major: INF" << std::endl;
			break;

		default:
			break;
	}
}

int main()
{
	Student student = { "ilian", "baychev", 32133, 6.00, Major::KN };
	printStudent(student);
	std::cout << "--------------------------------" << std::endl;
	printStudent(initStudent("yoan", "yonkata", 11111, 2.50, Major::IS));

	return 0;
}