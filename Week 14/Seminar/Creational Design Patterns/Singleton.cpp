#include <iostream>

class SingletonClass
{
private:
	SingletonClass()
	{
		std::cout << "SingletonClass was created" << std::endl;
	}

	~SingletonClass()
	{
		std::cout << "SingletonClass was destroyed" << std::endl;
	}

public:
	static SingletonClass& getInstance()  //функцията getInstance, в която се създава единственият
	{									  //обект от тип SingletonClass чрез статична променлива
			
		static SingletonClass instance;
		return instance;
	}

	SingletonClass(const SingletonClass& other) = delete;
	SingletonClass& operator=(const SingletonClass& other) = delete;

	void doStuff()
	{
		std::cout << this << std::endl;
	}
};

int main()
{
	{
		std::cout << "Hello";
		SingletonClass& s1 = SingletonClass::getInstance(); //тъй като е статична функция,
		                                                    //можем да я извикаме без обект 
															//SingletonClass()
	
	} //няма да се извика ~SingletonClass() тъй като статичните обекти се изтриват след края на програмата

	SingletonClass& s2 = SingletonClass::getInstance();
	s2.doStuff();
	SingletonClass& s3 = SingletonClass::getInstance();
	s3.doStuff();
	SingletonClass& s4 = SingletonClass::getInstance();
	s4.doStuff();

	//ще се отпечата един и същи адрес (този на уникалния ни обект от тип SingletonClass)


} //~SingletonClass()