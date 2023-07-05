#pragma once
#include <exception>

const unsigned WEEK_DAYS = 7;
const unsigned DAYS_IN_JANUARY = 31;
const unsigned FIRST_SUNDAY = 1;

class EventDuringJanuary2023
{
	unsigned daysInJanuary;

public:
	EventDuringJanuary2023() = default;

	unsigned howManyWeekdaysInAMonth(unsigned weekdayNumber) const;
	void addDay(unsigned day);
	void removeDay(unsigned day);
	bool containsAParticularDay(unsigned day) const;
	

	friend EventDuringJanuary2023 unionOfEvents(const EventDuringJanuary2023& first, const EventDuringJanuary2023& second);
	friend EventDuringJanuary2023 intersectionOfEvents(const EventDuringJanuary2023& first, const EventDuringJanuary2023& second);
};


