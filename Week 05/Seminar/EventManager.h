#pragma once
#include "Event.h"
#include <iostream>

namespace EventManagerConstants
{
	constexpr int MAX_EVENT_SIZE = 20;
}

class EventManager
{
private:
	Event events[EventManagerConstants::MAX_EVENT_SIZE];
	size_t size = 0;

	EventManager eventsOnDate(const Date& date) const;
	int findEventByName(const char* name) const;

public:
	bool addEvent(const Event& event);
	bool removeEvent(const char* name);
	bool removeLast();

	const Event& findLongestEvent() const;
	EventManager maxEvents(const Date& date) const;

	void print() const;
};
