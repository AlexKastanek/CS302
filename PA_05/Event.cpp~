#include "Event.h"

Event::Event()
{

	type = 'A';
	startTime = 0;
	length = 0;

}

Event::Event(char a, int b, int c)
{

	type = a;
	startTime = b;
	length = c;

}

Event::~Event()
{



}

char Event::getType() const
{

	return type;

}

int Event::getStartTime() const
{

	return startTime;

}

int Event::getLength() const
{

	return length;

}

void Event::setStartTime(int newTime)
{

	startTime = newTime;

}

void Event::randomizeLength(int range)
{

	length = rand() % range + 1;

}

ostream& operator<<(ostream& os, const Event& source)
{

	if (source.getType() == 'A')
	{
		os << "Arrival ";
	} else
	{
		os << "Departure ";
	}

	os << "at time " << source.getStartTime() << " for " << source.getLength() << " units of time." << endl;

	return os;

}













