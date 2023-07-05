#include "EventDuringJanuary.h"

unsigned EventDuringJanuary2023::howManyWeekdaysInAMonth(unsigned weekdayNumber) const
{
	if (weekdayNumber > 7 || weekdayNumber == 0)
	{
		throw std::exception("Error! Incorrect input!");
	}
	unsigned counter = 0;
	unsigned mask = 1;
	if (weekdayNumber == 7)
	{
		weekdayNumber = FIRST_SUNDAY;
	}
	else
	{
		weekdayNumber += 1;        //since 1st January is Sunday, all the dates in this month
	}	                          //are shifted with 1 from their initial weekdays' number (1-7)	

	for (unsigned i = weekdayNumber; i <= DAYS_IN_JANUARY; i+=WEEK_DAYS)
	{
		if (daysInJanuary & mask)
		{
			counter++;
		}
		mask <<= 1;
	}
	return counter;
}

void EventDuringJanuary2023::addDay(unsigned day)
{
	if (day == 0 || day > DAYS_IN_JANUARY)
	{
		throw std::exception("Error! Invalid data!");
	}
	unsigned mask = 1;
	mask <<= day;

	daysInJanuary |= mask;
}

void EventDuringJanuary2023::removeDay(unsigned day)
{
	if (day == 0 || day > DAYS_IN_JANUARY)
	{
		throw std::exception("Error! Invalid data!");
	}
	unsigned mask = 1;
	mask <<= day;
	mask = ~mask;
	daysInJanuary ^= mask;
}

bool EventDuringJanuary2023::containsAParticularDay(unsigned day) const
{
	if (day == 0 || day > DAYS_IN_JANUARY)
	{
		throw std::exception("Error! Invalid data!");
	}
	unsigned mask = 1;
	mask <<= day;

	return daysInJanuary & mask;
}

EventDuringJanuary2023 unionOfEvents(const EventDuringJanuary2023& first, const EventDuringJanuary2023& second)
{
	EventDuringJanuary2023 eventsUnion;

	eventsUnion.daysInJanuary = first.daysInJanuary | second.daysInJanuary;
	return eventsUnion;
}

EventDuringJanuary2023 intersectionOfEvents(const EventDuringJanuary2023& first, const EventDuringJanuary2023& second)
{
	EventDuringJanuary2023 eventsIntersection;

	eventsIntersection.daysInJanuary = first.daysInJanuary & second.daysInJanuary;
	return eventsIntersection;
}