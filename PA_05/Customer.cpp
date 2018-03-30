#include "Customer.h"

Customer::Customer()
{

	arrivalTime = 0;
	waitTime = 0;

}

Customer::~Customer()
{



}

int Customer::getArrivalTime() const
{

	return arrivalTime;

}

int Customer::getWaitTime() const
{

	return waitTime;

}

void Customer::setArrivalTime(int time)
{

	arrivalTime = time;

}

void Customer::setWaitTime(int currentTime)
{

	waitTime = currentTime - arrivalTime;

}

Customer& Customer::operator=(const Customer& source)
{

	arrivalTime = source.getArrivalTime();
	waitTime = source.getWaitTime();

	return *this;

}

ostream& operator<<(ostream& os, const Customer& source)
{

	cout << source.getArrivalTime() << "," << source.getWaitTime() << ";";

}

















