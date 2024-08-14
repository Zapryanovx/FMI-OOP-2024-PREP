//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

//Реализирайте клас Time, който ще се използва за работа с часове(13 : 05 : 45)
//Вашият клас трябва да има следния интерфейс :
//
//Подразбиращ се контруктор, който създава часа на 00 : 00 : 00.
//Конструктор, който приема три параметъра - час, минути и секунди.
//
//Член - функция, която връща оставащото време до полунощ.
//Член - функция, която увеличава часа с 1 секунда.
//
//Член - функция, която връща дали е време за вечеря.
//       В рамките на задачата време за вечеря е между 20 : 30 и 22 : 00.
//
//Член - функция, която приема друг обект от тип Time и връща обект от тип Time, 
//       което е разликата между двете времена.
//
//Член - функция, която която приема друг обект от тип Time и сравнява двата обекта(по - къснен / по - ранен)
//Член - функция за принтиране на часа.

#include <iostream>

constexpr unsigned SECONDS_IN_HOURS = 3600;
constexpr unsigned SECONDS_IN_MINUTE = 60;
constexpr unsigned DAY_SECONDS = 24 * 3600;

class Time
{
private:
	void initializeFromSeconds(unsigned secondsFromMidnight)
	{
		//ако потребителя надхвърли интервала от секунди, 
		//то ще запазим 00 : 00 : 00 като час
		if (secondsFromMidnight >= DAY_SECONDS)
		{
			secondsFromMidnight = 0;
		}

		setHours(secondsFromMidnight / SECONDS_IN_HOURS);
		secondsFromMidnight %= SECONDS_IN_HOURS;

		setMinutes(secondsFromMidnight / SECONDS_IN_MINUTE);
		secondsFromMidnight %= SECONDS_IN_MINUTE;

		setSeconds(secondsFromMidnight);
	}

	unsigned hrs;
	unsigned mins;
	unsigned secs;

public:

	//подразбиращ се контруктор, който задава часа на 00 : 00 : 00,
	//използвайки конструктора, приемащ (hours, minutes, seconds),
	//като му подава (0, 0, 0)
	Time(): Time(0, 0, 0) {}

	Time(unsigned hours, unsigned minutes, unsigned seconds)
	{
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
	}

	//конструктор, приемащ само секунди и трябва да ги
	//конвертираме в час сами
	Time(unsigned secondsFromMidnight)
	{
		initializeFromSeconds(secondsFromMidnight);
	}

	void setHours(unsigned hours)
	{
		//ако часовете са невалидни
		if (hours >= 24)
		{
			return;
		}

		this->hrs = hours;
	}

	void setMinutes(unsigned minutes)
	{
		//ако минутите са невалидни
		if (minutes >= 60)
		{
			return;
		}

		this->mins = minutes;
	}

	void setSeconds(unsigned seconds)
	{
		//ако секундите са невалидни
		if (seconds >= 60)
		{
			return;
		}

		this->secs = seconds;
	}

	unsigned getSecondsFromMidnight() const
	{
		return SECONDS_IN_HOURS * this->hrs + SECONDS_IN_MINUTE * this->mins + this->secs;
	}

	//оставащото време е разликата на 
	//секундите в един ден и секундите, на текущия час
	Time getTimeToMidnight() const
	{
		return Time(DAY_SECONDS - getSecondsFromMidnight());
	}

	void tick()
	{
		initializeFromSeconds(getSecondsFromMidnight() + 1);
	}

	bool lessThan(const Time& other) const
	{
		return getSecondsFromMidnight() < other.getSecondsFromMidnight();
	}

	bool isTimeForDinner() const
	{
		//интервалът за вечеря [ 20:30 - 22:00 ]
		Time lower(20, 30, 0);
		Time upper(22, 0, 0);

		return lessThan(upper) && !lessThan(lower);
	}

	Time difference(const Time& other) const
	{
		unsigned mySeconds = getSecondsFromMidnight();
		unsigned otherSeconds = other.getSecondsFromMidnight();

		if (mySeconds > otherSeconds)
		{
			return Time(mySeconds - otherSeconds);
		}
		return Time(otherSeconds - mySeconds);
	}
	

	void print() const
	{
		std::cout << this->hrs << " : " << this->mins << " : " << this->secs << std::endl;
	}
};

int main()
{
	Time t(18, 25, 0);
	t.print();

	Time mid = t.getTimeToMidnight();
	std::cout << "Time to midnight: ";
	mid.print();
	
	std::cout << t.isTimeForDinner() << std::endl;
	t.tick();
	t.print();

	Time t2(21, 30, 10);
	Time t3(16, 0, 0);

	std::cout << t2.isTimeForDinner() << std::endl;

	std::cout << std::endl;
	t.difference(t2).print();
	t.difference(t3).print();

	std::cout << std::endl;
	std::cout << t2.lessThan(t3) << std::endl;
	std::cout << t3.lessThan(t2) << std::endl;


	return 0;
}