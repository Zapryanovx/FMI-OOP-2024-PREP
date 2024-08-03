////#ОБЯСНЕНИЕ НА ЗАДАЧАТА:
//// 
//// Да се напише клас за работа с крайно множество от събития(най - много 30).Класът трябва да съдържа :
//
//- Добавяне на събитие
//- Намиране на най - дългото събитие
//- Премахване на последното събитие
//- Премахване на събитие по име.
//- Приемане на дата и връщане на максималния брой събития, които може да се посетят в този ден. 
//       (за да се посетят 2 събития, те трябва да не се пресичат).

#include "EventManager.h"

EventManager EventManager::eventsOnDate(const Date& date) const
{
	//добавяме всички Event-и на дадена дата в нов EventManager, който връщаме
	EventManager res;

	for (int i = 0; i < size; i++)
	{
		//ако подадената дата съвпада с тази на i-тия event
		if (compareDates(date, events[i].getDate()) == 0)
		{
			//го добавяме в новия EventManager
			res.addEvent(events[i]);
		}
	}

	return res;
}

int EventManager::findEventByName(const char* name) const
{
	//nullptr check
	if (!name)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (std::strcmp(events[i].getName(), name) == 0)
		{
			return i;
		}
	}

	return -1;
}

bool EventManager::addEvent(const Event& event)
{
	if (size >= 30)
	{
		return false;
	}

	events[size++] = event;
	return true;
}

bool EventManager::removeEvent(const char* name)
{

	int index = findEventByName(name);
	if (index == -1 || !name)
	{
		return false;
	}

	//за да спестим shift-ване наляво, тъй като ни предстои
	//да премахнем вече намерения елемент, може просто да сложим
	//последния Event върху намерения
	events[index] = events[size - 1];

	size--;
	return true;
}

bool EventManager::removeLast()
{
	if (size <= 0)
	{
		return false;
	}

	size--;
	return true;
}

const Event& EventManager::findLongestEvent() const
{
	Time maxLen = events[0].getLenght();
	int index = 0;

	for (int i = 1; i < size; i++)
	{
		Time currLen = events[i].getLenght();
		if (currLen.greater(maxLen))
		{
			index = i;
			maxLen = currLen;
		}
	}

	return events[index];
	
}

EventManager EventManager::maxEvents(const Date& date) const
{
	//взимаме всички Event-и на подадената дата в нов EventManager
	EventManager sameDateBuff = eventsOnDate(date);

	//първо ще сортираме всички Event-и на дадената дата спрямо
	//времето, по което свършват, така взимайки постепенно следващия Event
	//с непреплитащо се начало и с най-ранен край ще намерим кои събития можем да посетим (най-много на брой)
	
	//selection sort
	for (int i = 0; i < size - 1; i++)
	{
		size_t currMinIdx = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (sameDateBuff.events[currMinIdx].getEnd().greater(events[j].getEnd()))
			{
				currMinIdx = j;
			}
		}

		if (currMinIdx != i)
		{
			std::swap(sameDateBuff.events[currMinIdx], sameDateBuff.events[i]);
		}
	}

	//правим нов EventManager, съдържащ най-голямото множество от Event-и,
	//които можем да посетим
	EventManager toReturn;
	toReturn.addEvent(sameDateBuff.events[0]);

	for (int i = 1; i < sameDateBuff.size; i++)
	{
		//сравняваме i-тия Event в буфера с последния в множеството от най-много Event-и,
		//с цел да проверим дали може да бъде залепен в това множество 
		//(дали i-тия почва след края на последния в toReturn)
		if (sameDateBuff.events[i].getStart().greater(toReturn.events[toReturn.size - 1].getEnd()))
		{
			toReturn.addEvent(sameDateBuff.events[i]);
		}
	}

	return toReturn;
}

void EventManager::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << events[i].getName() << std::endl;
	}
}