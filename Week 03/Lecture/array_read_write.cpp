//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:
// 
// Пример за запазване / четене на масив от обекти(от един тип) във файл.

#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning( disable : 4996)

struct Student
{
	//външен ресурс
	char* name;

	int age;
	int fn;
};

Student init(const char* name, int age, int fn)
{
	Student st;
	
	st.name = new char[strlen(name) + 1]; // + '\0'
	strcpy(st.name, name);
	
	st.age = age;
	st.fn = fn;

	return st;
}

void freeStudent(Student& st)
{
	delete[] st.name;
	st.age = st.fn = 0;
}

void saveToBinaryFile(std::ofstream& ofs, const Student& st)
{
	//ако не запишем размера във файла:
	//1) при четене няма да знаем колко точно памет 
	//   да заделим за член-данната, в която ще го запазим
	//2) при четене няма да знаем къде свършва масива и започват
	//   останалите член-данни 
	//   (в случая знаем заради '\0', но при всички останали масиви няма как да знаем)
	
	//записваме името
	int nameLen = strlen(st.name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(st.name, nameLen + 1); // + '\0'

	//записваме останалите член-данни
	ofs.write((const char*)&st.age, sizeof(st.age));
	ofs.write((const char*)&st.fn, sizeof(st.fn));

}

Student readFromBinaryFile(std::ifstream& ifs)
{
	Student st2;

	int nameLen;
	ifs.read((char*)&nameLen, sizeof(int));

	st2.name = new char[nameLen + 1];
	ifs.read(st2.name, nameLen + 1);

	ifs.read((char*)&st2.age, sizeof(st2.age));
	ifs.read((char*)&st2.fn, sizeof(st2.fn));

	return st2;
}

void printStudent(const Student& st)
{
	std::cout << st.name << " " << st.age << " " << st.fn << std::endl;
}

void saveStudentsArrayToFile(std::ofstream& ofs, const Student* arr, size_t arraySize)
{
	//записваме размера на масива от студенти
	ofs.write((const char*)&arraySize, sizeof(arraySize));

	for (int i = 0; i < arraySize; i++)
	{
		//вече имаме функция, която може да запише студент
		saveToBinaryFile(ofs, arr[i]);
	}

}

void readStudentsArrayFromFile(std::ifstream& ifs, Student*& arr, size_t& size)
{
	//прочитаме размера на масива от студенти
	ifs.read((char*)&size, sizeof(size));
	std::cout << size << std::endl;
	//заделяме памет с размер [size], който вече сме прочели
	arr = new Student[size];

	for (int i = 0; i < size; i++)
	{
		//вече имаме функция, която може да прочете студент
		arr[i] = readFromBinaryFile(ifs);

	}
}

int main()
{
	{
		std::ofstream ofs("arrStudents.dat", std::ios::out | std::ios::binary);
		if (!ofs.is_open())
			return -1;

		Student arr[3];
		arr[0] = init("Ivan", 10, 20);
		arr[1] = init("Peter", 41, 44);
		arr[2] = init("Nikolay", 99, 0);


		saveStudentsArrayToFile(ofs, arr, 3);

		freeStudent(arr[0]);
		freeStudent(arr[1]);
		freeStudent(arr[2]);
	}

	{

		std::ifstream ifs("arrStudents.dat", std::ios::in | std::ios::binary);
		if (!ifs.is_open())
			return -1;
		Student* arr;
		size_t size;

		readStudentsArrayFromFile(ifs, arr, size);

		for (int i = 0; i < size; i++)
		{
			printStudent(arr[i]);
		}

		for (size_t i = 0; i < size; i++)
		{
			freeStudent(arr[i]);
		}
	}

	return 0;
}