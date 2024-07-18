//#include <iostream>
//
//enum class Course
//{
//	First = 1,
//	Second,
//	Third,
//	Forth
//};
//
//struct Student
//{
//	int facultyNum = 0;
//	Course course;
//	double avgGrade = 0.00;
//};
//
//const int MAX_SIZE_STUDENTS_IN_GROUP = 10;
//
//struct Group
//{
//	Student students[MAX_SIZE_STUDENTS_IN_GROUP];
//	int currentGroupSize = 0;
//	double avgGroupGrade = 0.00;
//};
//
////read data if correct 
//void initStudent(Student& student)
//{
//	std::cin >> student.facultyNum;
//	if (!(1 <= student.facultyNum / 10000 && student.facultyNum / 10000 <= 9))
//	{
//		std::cout << "[ERROR] Invalid Faculty Number" << std::endl;
//		return;
//	}
//
//	int courseIdx = 0;
//	std::cin >> courseIdx;
//
//	switch (courseIdx)
//	{
//	case 1:
//		student.course = Course::First;
//		break;
//	case 2:
//		student.course = Course::Second;
//		break;
//	case 3:
//		student.course = Course::Third;
//		break;
//	case 4:
//		student.course = Course::Forth;
//		break;
//	default:
//		std::cout << "[ERROR] Invalid course." << std::endl;
//		return;
//	}
//
//	std::cin >> student.avgGrade;
//	if (student.avgGrade < 2 || student.avgGrade > 6)
//	{
//		std::cout << "[ERROR] Invalid average grade." << std::endl;
//		return;
//	}
//}
//
//void printStudent(const Student& student)
//{
//	std::cout << "Faculty Number: " << student.facultyNum << std::endl;
//
//	std::cout << "Course: ";
//	switch (student.course)
//	{
//	case Course::First:
//		std::cout << "First" << std::endl;
//		break;
//	case Course::Second:
//		std::cout << "Second" << std::endl;
//		break;
//	case Course::Third:
//		std::cout << "Third" << std::endl;
//		break;
//	case Course::Forth:
//		std::cout << "Forth" << std::endl;
//		break;
//	default:
//		break;
//	}
//
//	std::cout << "Average Grade: " << student.avgGrade << std::endl;
//}
//
//void readGroup(Group& group)
//{
//	int size = 0;
//	std::cin >> size;
//
//	if (size > MAX_SIZE_STUDENTS_IN_GROUP)
//	{
//		std::cout << "[ERROR] Size over MAX" << std::endl;
//		return;
//	}
//
//	double sumOfGrades = 0.00;
//
//	for (int i = 0; i < size; i++)
//	{
//		initStudent(group.students[i]);
//		sumOfGrades += group.students[i].avgGrade;
//		group.currentGroupSize++;
//	}
//	group.avgGroupGrade = sumOfGrades / size;
//
//}
//
//int studentsWithScholarship(const Group& group, double criteria)
//{
//	int countStudentsWithScholarship = 0;
//	for (int i = 0; i < group.currentGroupSize; i++)
//	{
//		//if student meets criteria 
//		if (group.students[i].avgGrade >= criteria)
//		{
//			countStudentsWithScholarship++;
//		}
//	}
//
//	return countStudentsWithScholarship;
//}
//
//void printSortedStudentsWithScholarship(const Group& group, const double* aboveCriteriaGrades, int aboveCriteriaGradesIdx)
//{
//
//	for (int i = 0; i < group.currentGroupSize; i++)
//	{
//		for (int j = 0; j < aboveCriteriaGradesIdx; j++)
//		{
//			if (group.students[i].avgGrade == aboveCriteriaGrades[j])
//			{
//				printStudent(group.students[i]);
//				std::cout << "----------------------------------" << std::endl;
//			}
//		}
//	}
//}
//
//void sortStudentsWithScholarship(Group& group, double criteria)
//{
//	double aboveCriteriaGrades[MAX_SIZE_STUDENTS_IN_GROUP] = {};
//	int aboveCriteriaGradesIdx = 0;
//
//	for (int i = 0; i < group.currentGroupSize; i++)
//	{
//		//if student meets criteria 
//		if (group.students[i].avgGrade >= criteria)
//		{
//			aboveCriteriaGrades[aboveCriteriaGradesIdx++] = group.students[i].avgGrade;
//		}
//	}
//
//	int maxIdx = 0;
//	for (int i = 0; i < group.currentGroupSize - 1; i++)
//	{
//		maxIdx = i;
//		for (int j = i + 1; j < group.currentGroupSize; j++)
//		{
//			if (aboveCriteriaGrades[maxIdx] <= aboveCriteriaGrades[j])
//			{
//				maxIdx = j;
//			}
//		}
//
//		if (maxIdx != i)
//		{
//			std::swap(maxIdx, i);
//			std::swap(group.students[maxIdx], group.students[i]);
//		}
//	}
//
//	printSortedStudentsWithScholarship(group, aboveCriteriaGrades, aboveCriteriaGradesIdx);
//}
//
//int main()
//{
//	Group group;
//	readGroup(group);
//	
//	double criteria;
//	std::cin >> criteria;
//	
//	sortStudentsWithScholarship(group, criteria);
//
//	return 0;
//}