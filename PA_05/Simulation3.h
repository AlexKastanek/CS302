// Class Header File Information //////////////////////////////////////////////
/**
  * @file Simulation3.h
  *
  * @brief Definition file for Simulation3 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Simulation3 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of Simulation3 class
  *
  * @note None
  *
  */

#ifndef SIMULATION3
#define SIMULATION3

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "Queue.cpp"
#include "Customer.h"

class Simulation3
{

	public:
		Simulation3(int = 99999);
		~Simulation3();

		void getArrivals(char*);
		int getTellerAvailability();
		int getTeller();

		void simulate();
		void processArrival(Queue<Event>&, Queue<Event>&, Queue<Event>&, Queue<int>&);
		void processDeparture(Queue<Event>&, Queue<Event>&, Queue<Event>&,      Queue<int>&);

	private:
		bool firstSim;

		Queue<Customer> customerQueue;
		Event customer;
		Event* arrivals;
		int numOfCustomers, numOfEvents, currentTime, transactionTime;
		int maxWaitTime, totalWaitTime;
		int maxLengthOfLine;
		float averageWaitTime, averageLengthOfLine, totalLengthOfLine;
		bool tellerAvailable, teller1, teller2, teller3;
		int totalIdleTime1, idleStart1, idleEnd1;
		int totalIdleTime2, idleStart2, idleEnd2;
		int totalIdleTime3, idleStart3, idleEnd3;

};

#endif
