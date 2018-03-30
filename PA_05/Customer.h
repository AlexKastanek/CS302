#ifndef CUSTOMER
#define CUSTOMER

#include <iostream>
#include <fstream>

using namespace std;

class Customer
{

	public:
		Customer();
		~Customer();

		int getArrivalTime() const;
		int getWaitTime() const;

		void setArrivalTime(int);
		void setWaitTime(int);

		Customer& operator=(const Customer&);

		friend ostream& operator<<(ostream&, const Customer&);

	private:
		int arrivalTime;
		int waitTime;

};

#endif
