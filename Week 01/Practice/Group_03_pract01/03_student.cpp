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
//		case 1:
//			student.course = Course::First;
//			break;
//		case 2:
//			student.course = Course::Second;
//			break;
//		case 3:
//			student.course = Course::Third;
//			break;
//		case 4:
//			student.course = Course::Forth;
//			break;
//		default:
//			std::cout << "[ERROR] Invalid course." << std::endl;
//			return;
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
//		case Course::First:
//			std::cout << "First" << std::endl;
//			break;
//		case Course::Second:
//			std::cout << "Second" << std::endl;
//			break;
//		case Course::Third:
//			std::cout << "Third" << std::endl;
//			break;
//		case Course::Forth:
//			std::cout << "Forth" << std::endl;
//			break;
//		default:
//			break;
//	}
//
//	std::cout << "Average Grade: " << student.avgGrade << std::endl;
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