#include <iostream>

enum class Major
{
	SI,
	KN,
	IS,
	INF
};

struct Student
{
	char name[17];
	int facultyNumber;
	Major major;
};

struct Course
{
	Student students[20];
	int studentsCount;
};

int studentsCountInMajor(const Course& course, const Major& major, Student *students)
{
	int count = 0;
	for (int i = 0; i < course.studentsCount; i++)
	{
		if (course.students[i].major == major)
		{
			students[i] = course.students[i];
			count++;
		}
	}

	return count;
}

int main()
{
	Major major = Major::KN;
	Course course = { {"test", 123456, major,
					   "test", 123456, Major::SI,}, 2};

	Student students[2] = {};
	std::cout << students[1].name << " "<<students[1].facultyNumber <<" " << (char) students[1].major << 1 <<std::endl;
	std::cout << studentsCountInMajor(course, major, students);

	return 0;
}