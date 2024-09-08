#include <fstream>
#include <iostream>

class Base
{
public:
	virtual ~Base() = default;
};

class A : public Base
{
public:
	A()
	{
		std::cout << "A()<" << std::endl;
	}
};
class B: public Base
{
public:
	B()
	{
		std::cout << "B()<" << std::endl;
	};
};

class SingletonFactory
{
	size_t current = 0;
	size_t numbersSize = 0;
	size_t* numbers = nullptr;

	SingletonFactory()
	{
		std::ifstream in("data.txt");
		if (!in.is_open())
		{
			throw std::exception("Could not open data.txt");
		}

		in >> numbersSize;
		numbers = new size_t[numbersSize];
		size_t index = 0;
		while (!in.eof())
		{
			in >> numbers[index++];
		}
	}

	~SingletonFactory()
	{
		delete[] numbers;
	}

public:
	Base* create()
	{
		if (current >= numbersSize)
		{
			return nullptr;
		}

		if (numbers[current++] % 2 == 0)
		{
			return new A();
		}

		else
		{
			return new B();
		}
	}

	static SingletonFactory& getInstance()
	{
		static SingletonFactory instance;
		return instance;
	}

	SingletonFactory(const SingletonFactory& other) = delete;
	SingletonFactory& operator=(const SingletonFactory& other) = delete;
};

int main()
{
	SingletonFactory& sf = SingletonFactory::getInstance();

	Base* b1 = sf.create();
	Base* b2 = sf.create();
	Base* b3 = sf.create();


	delete b1;
	delete b2;
	delete b3;
}
