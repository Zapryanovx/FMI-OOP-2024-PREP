#include <iostream>

struct Event
{
	char name[17];
	DayOfWeek day;
    int duration;
};

enum class DayOfWeek
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};


// print event
void printEvent(const Event& event)
{
    std::cout << event.name << " " << (int) event.day << " " << event.duration << std::endl;
}

// print events on given day
void printEventsOn(DayOfWeek day, const Event* events, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (events[i].day == day)
        {
            printEvent(events[i]);
        }
    }
}

int main()
{
    Event event = {"event", DayOfWeek::MONDAY, 3};
    Event eventTwo = { "event2", DayOfWeek::THURSDAY, 3 };
    Event eventThree = { "event3", DayOfWeek::MONDAY, 3 };

    Event eventArr[3] = { event, eventTwo, eventThree };
    printEventsOn(DayOfWeek::MONDAY, eventArr, 3);

	return 0;
}