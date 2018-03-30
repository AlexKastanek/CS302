// Class Header File Information //////////////////////////////////////////////
/**
  * @file Simulation2.h
  *
  * @brief Definition file for Simulation2 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Simulation2 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of Simulation2 class
  *
  * @note None
  *
  */

#ifndef SIMULATION2
#define SIMULATION2

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "Queue.cpp"
#include "Customer.h"

class Simulation2
{

	public:
		Simulation2(int = 99999);
		~Simulation2();

		void getArrivals(char*);
		int getShortestLine();
		int getCurrentLine(int);
		void getTellerAvailability(int, int);

		void simulate();
		void processArrival(Queue<Event>&, Queue<Event>&, Queue<Event>&, Queue<int>&);
		void processDeparture(Queue<Event>&, Queue<Event>&, Queue<Event>&,      Queue<int>&);

	private:
		bool firstSim;

		Queue<Customer> customerQueue;
		Queue<Event> bankLine1, bankLine2, bankLine3;
		Event customer;
		Event* arrivals;
		int numOfCustomers, numOfEvents, currentTime, transactionTime;
		int maxWaitTime, totalWaitTime;
		int maxLengthOfLine1, maxLengthOfLine2, maxLengthOfLine3;
		float averageWaitTime;
		float averageLengthOfLine1, totalLengthOfLine1;
		float averageLengthOfLine2, totalLengthOfLine2;
		float averageLengthOfLine3, totalLengthOfLine3;
		bool tellerAvailable, teller1, teller2, teller3, emptyLine, emptyLineSpec;
		int totalIdleTime1, idleStart1, idleEnd1;
		int totalIdleTime2, idleStart2, idleEnd2;
		int totalIdleTime3, idleStart3, idleEnd3;

};

#endif
