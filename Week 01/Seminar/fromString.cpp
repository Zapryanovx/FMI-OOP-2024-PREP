//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

// Да се реализира функция, за превръщане на низ в число.
// Функцията може да допусне грешки и трябва да предоставя начин, 
// по който можем да разберем какво точно се е объркало.
// (дали всичко е ок, дали има overflow, дали низът е невалиден, дали е подаден nullptr)

#include <iostream>


enum class ErrorCode
{
	OK,
	NullPtr,
	InvalidString,
	Overflow,
};

//ще използваме структура, която ще представлява нещо като наредена двойка,
//където [value] ще пази стойността на числото, а [code] състоянието, 
//до което е довел низът, който искаме да преобразуваме в число
struct ResultPair
{
	int64_t value;
	ErrorCode code;
};

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

ResultPair fromString(const char* str)
{
	if (str == nullptr)
	{
		return { 0, ErrorCode::NullPtr };
	}

	int64_t toReturn = 0;
	
	//ако низът съдържа отрицателно число, то
	//първият символ на числото е '-'
	bool isNegative = (*str == '-'); 

	//и трябва да преминем към цифрите, 
	//в случай, че е отрицателно
	//(тоест трябва да почнем с една клетка по-напред обхождането на цифрите)
	if (isNegative)
	{
		str++; //прескачаме '-'
	}

	while (*str)
	{
		//ако намерим символ, различен от цифра, то низът е невалиден
		if (!isDigit(*str))
		{
			return { 0, ErrorCode::InvalidString };
		}

		
		int64_t temp = toReturn;

		//освобождаваме място за следващата цифра, т.е.
		//ако имаме низът "123" и ни предстои да прочетем '2'
		//то temp == 1 (тъй като toReturn е 1, защото сме прочели само '1'),

		//след което чрез temp *= 10, temp става 10, което
		//освобождава място за прочитането на следващата цифра, в случая '2'
		temp *= 10;
		
		//добавяме следващата цифра (на мястото на добавената 0 в края чрез операцията *= 10)
		temp += (*str - '0');


		//в случай че toReturn > temp,
		//то това означава, че сме надхвърлили типа int64_t
		//и temp е превъртяло стойностите, т.е. overflow
		if (toReturn > temp)
		{
			return{ toReturn, ErrorCode::Overflow };
		}

		//запазваме промените и преминаваме към следващата цифра
		toReturn = temp;
		str++;
	}

	//ако е отрицателно, отразяваме минуса, който пренебрегнахме преди обхождането
	if (isNegative)
	{
		toReturn = -toReturn;
	}

	return { toReturn, ErrorCode::OK };
}

int main()
{
	ResultPair p = fromString("1237346723");

	switch (p.code)
	{
	case ErrorCode::OK:
		std::cout << p.value;
		break;
	case ErrorCode::NullPtr:
		std::cout << "nullptr";
		break;
	case ErrorCode::InvalidString:
		std::cout << "invalid string";
		break;
	case ErrorCode::Overflow:
		std::cout << "overflow";
		break;
	default:
		std::cout << "Unknown error";
		break;
	}

	return 0;
}