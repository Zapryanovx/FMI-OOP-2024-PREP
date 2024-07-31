//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

//Пример за клас Person с име(низ с дължина най - много 20 символа) и години[5...90].
//с селектори и мутатори за името и годините

#include <iostream>
#include <cstring>

#pragma warning( disable : 4996)

//помощни функции за поставените в задачата условия
bool isSmallLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isCapitalLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

//ще я използваме, когато проверяваме дали
//всички букви след първата буква на името са малки
bool containsOnlySmallChars(const char* str)
{
	size_t len = strlen(str);

	for (size_t i = 0; i < len; i++)
	{
		if (!isSmallLetter(str[i]))
		{
			return false;
		}
	}

	return true;
}

constexpr int NAME_MAX_LEN = 20;
constexpr int NAME_MIN_LEN = 2;
constexpr int AGE_MIN = 5;
constexpr int AGE_MAX = 90;

class Person
{
private:
	char name[NAME_MAX_LEN + 1] = "Unknown"; // + '\0'
	int age = AGE_MIN;

	//помощни функции за валидиране преди запазване на данните
	bool isValidAge(int age)
	{
		return age >= AGE_MIN && age <= AGE_MAX;
	}

	bool isValidName(const char* name)
	{
		if (name == nullptr)
		{
			return false;
		}

		size_t nameLen = std::strlen(name);
		if (nameLen <= NAME_MIN_LEN || nameLen >= NAME_MAX_LEN)
		{
			return false;
		}

		//ако не започва с главна буква
		if (!isCapitalLetter(*name))
		{
			return false;
		}

		//валидиране на всички букви след първата
		return containsOnlySmallChars(name + 1);
	}

public:
	Person() = default;

	Person(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}
	
	const char* getName() const
	{
		return this->name;
	}

	int getAge() const
	{
		return this->age;
	}

	void setName(const char* name)
	{
		if (isValidName(name))
		{
			std::strcpy(this->name, name);
		}

		else
		{
			std::strcpy(this->name, "Unknown");
		}
	}

	void setAge(int age)
	{
		if (isValidAge(age))
		{
			this->age = age;
		}

		else
		{
			this->age = AGE_MIN;
		}
	}

};

int main()
{
	Person s("Ivan", 33);
	std::cout << s.getName() << " " << s.getAge() << std::endl;

	Person s2("IVan", 33);
	std::cout << s2.getName() << " " << s2.getAge() << std::endl;

	Person s3("Ivan", -3);
	std::cout << s3.getName() << " " << s3.getAge() << std::endl;

	Person s4("Ivan", 333);
	std::cout << s4.getName() << " " << s4.getAge() << std::endl;

	return 0;
}