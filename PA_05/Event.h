#ifndef EVENT
#define EVENT

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Event
{

	public:
		Event();
		Event(char, int, int);
		~Event();

		char getType() const;
		int getStartTime() const;
		int getLength() const;

		void setStartTime(int);
		void randomizeLength(int);

		friend ostream& operator<<(ostream&, const Event&);

	private:
		char type;
		int startTime;
		int length;

};

#endif
