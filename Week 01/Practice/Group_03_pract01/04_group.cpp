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
//	int facultyNum;
//	Course course;
//	double avgGrade;
//};
//
//const int MAX_SIZE_STUDENTS_IN_GROUP = 10;
//
//struct Group
//{
//	Student students[MAX_SIZE_STUDENTS_IN_GROUP];
//	int currentGroupSize;
//	double avgGroupGrade;
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
//Group readGroup()
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
//	Group group;
//	double sumOfGrades = 0.00;
//
//	for (int i = 0; i < size; i++)
//	{
//		initStudent(group.students[i]);
//		sumOfGrades += group.students[i].avgGrade;
//		group.currentGroupSize++;
//	}
//
//	group.avgGroupGrade = sumOfGrades / size;
//
//	return group;
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
//int main()
//{
//	Student student;
//	initStudent(student);
//	printStudent(student);
//
//	return 0;
//}