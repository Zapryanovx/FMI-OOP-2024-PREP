//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:
// 
// 
// Пример с клас Event (използваме клас Time и Date на готово)

#include "Event.h"
#pragma warning(disable : 4996)

//default-ният конктруктор на Event извиква друг конструктор на Event с фиксирани параметри
Event::Event() : Event("", 1, 1, 1, 0, 0, 0, 0, 0, 0) {}

Event::Event(const char* name, const Date& date, const Time& startTime, const Time& endTime):
	_date(date), _startTime(startTime), _endTime(endTime)
{
	setName(name);
	validateTimes();
}

//чрез конструкторите на Date и Time, които:
//Date - има default-ен конструктор и конструктор (day, month, year)
//Time - има default-ен конструктор и конструктор (hours, mins, secs)
//тъй като Event има член-данни от тип Date и Time,
//ще се извикат техни конструктори преди да влезем в тялото на конструктора на Event
//и можем да конкретизираме кой конструктор на Date и Time да се извика 
//например _date(day, month, year) конкретизира _date да се създаде чрез конструктора (day, month, year)
Event::Event(const char* name, unsigned day, unsigned month, unsigned year,
	unsigned startTimeHours, unsigned startTimeMins, unsigned startTimeSecs,
	unsigned endTimeHours, unsigned endTimeMins, unsigned endTimeSecs) :
		_date(day, month, year), _startTime(startTimeHours, startTimeMins, startTimeSecs), _endTime(endTimeHours, endTimeMins, endTimeSecs)
{
	setName(name);
	validateTimes();
}

const char* Event::getName() const
{
	return _name;
}

const Date& Event::getDate() const
{
	return _date;
}

const Time& Event::getStartTime() const
{
	return _startTime;
}

const Time& Event::getEndTime() const
{
	return _endTime;
}

void Event::setName(const char* str)
{
	//валидация за дължината на подаденото име + nullptr check
	if (!str || strlen(str) > 20)
	{
		return;
	}

	std::strcpy(_name, str);
}

void Event::validateTimes() //разменя старт и край, ако старт е >
{
	if (compareTimes(_startTime, _endTime) > 0)
	{
		std::swap(_startTime, _endTime);
	}
}
