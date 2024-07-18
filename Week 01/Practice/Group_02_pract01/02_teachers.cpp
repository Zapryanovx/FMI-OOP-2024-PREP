//#include <iostream>
//
//enum class Degree
//{
//	bachelor,
//	master,
//	doctor
//};
//
//struct Teacher
//{
//	const char *idNumber;
//	Degree degree;
//	int studentsFailed;
//};
//
//Teacher initializeTeacher(const char *idNumber, const Degree& degree, const int studentsFailed)
//{
//	return { idNumber, degree, studentsFailed };
//}
//
//
//void printTeacher(const Teacher& teacher)
//{
//	std::cout << teacher.idNumber << " " << (int) teacher.degree << " " << teacher.studentsFailed << std::endl;
//}
//
//void isTeacher(const char* idNumber, const Degree& degree, const int studentsFailed)
//{
//	int digitCounter = 0;
//	while (*(idNumber++))
//	{
//		digitCounter++;
//	}
//	idNumber -= digitCounter + 1;
//
//	if (digitCounter != 5)
//	{
//		std::cout << "idNum not valid." << std::endl;
//		return;
//	}
//
//	if (!(degree == Degree::bachelor || degree == Degree::master || degree == Degree::doctor))
//	{
//		std::cout << "degree not valid." << std::endl;
//		return;
//	}
//
//	if (studentsFailed < 0)
//	{
//		std::cout << "studentsFailed not valid." << std::endl;
//		return;
//	}
//
//	const Teacher teacher = initializeTeacher(idNumber, degree, studentsFailed);
//	printTeacher(teacher);
//}
//
//
//int main()
//{
//	const char *idNumber = "10000";
//	isTeacher(idNumber, Degree::doctor , 3);
//
//	return 0;
//}