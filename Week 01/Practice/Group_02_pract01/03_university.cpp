//#include <iostream>
//
//enum class Degree
//{
//	bachelor,
//	master,
//	doctor
//};
//
//struct Teachers
//{
//	char name[20];
//	Degree degree;
//	int failedStudents;
//};
//
//struct University
//{
//	char name[40];
//	int yearFounded;
//	Teachers* teachers;
//	int numOfTeachers;
//	double avgFailedStudents;
//};
//
//void createUniversity(University& university)
//{
//	std::cin >> university.name;
//	std::cin >> university.yearFounded;
//
//	university.teachers[0] = { "Angel Dimitriev", Degree::doctor, 80 };
//	university.teachers[1] = { "Angel Lazov", Degree::doctor, 45 };
//	university.teachers[2] = { "Preslav Petrov", Degree::doctor, 20 };
//	university.numOfTeachers = 3;
//
//}
//
//double getAvgFailedStudents(const University& university)
//{
//	int sum = 0;
//	for (int i = 0; i < university.numOfTeachers; i++)
//	{
//		sum += university.teachers[i].failedStudents;
//	}
//
//	return (sum * 1.00) / university.numOfTeachers;
//}
//
//int getTeachersWithBonus(const University& university, int minFailedStudentsCriteria)
//{
//	int countTeachersWithBonus = 0;
//
//	for (int i = 0; i < university.numOfTeachers; i++)
//	{
//		if (university.teachers[i].failedStudents >= minFailedStudentsCriteria)
//		{
//			countTeachersWithBonus++;
//		}
//	}
//	
//	return countTeachersWithBonus;
//}
//
//void sortTeachersByFailedStudents(University& university)
//{
//	double *avgFailedStudents = new double[university.numOfTeachers];
//	for (int i = 0; i < university.numOfTeachers; i++)
//	{
//		avgFailedStudents[i] = university.teachers[i].failedStudents;
//	}
//
//	int minIdx = 0;
//	for (int i = 0; i < university.numOfTeachers - 1; i++)
//	{
//		minIdx = i;
//		for (int j = i + 1; j < university.numOfTeachers; j++)
//		{
//			if (university.teachers[j].failedStudents < university.teachers[minIdx].failedStudents)
//			{
//				minIdx = j;
//			}
//		}
//
//		if (minIdx != i)
//		{
//			std::swap(minIdx, i);
//			std::swap(university.teachers[minIdx], university.teachers[i]);
//		}
//	}
//
//}
//
//void printTeachers(const University& university)
//{
//	for (int i = 0; i < university.numOfTeachers; i++)
//	{
//		std::cout << university.teachers[i].name << std::endl;
//	}
//
//}
//
//int main()
//{
//	University university;
//	createUniversity(university);
//
//	university.avgFailedStudents = getAvgFailedStudents(university);
//	std::cout << university.avgFailedStudents << std::endl;
//
//	std::cout << getTeachersWithBonus(university, 10) << " ";
//	std::cout << getTeachersWithBonus(university, 50) << " ";
//	std::cout << getTeachersWithBonus(university, 90) << std::endl;
//
//	sortTeachersByFailedStudents(university);
//	printTeachers(university);
//
//	delete[] university.teachers;
//
//	return 0;
//}