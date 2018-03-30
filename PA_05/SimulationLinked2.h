// Class Header File Information //////////////////////////////////////////////
/**
  * @file SimulationLinked2.h
  *
  * @brief Definition file for SimulationLinked2 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the SimulationLinked2 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of SimulationLinked2 class
  *
  * @note None
  *
  */

#ifndef SIMULATION_LINKED2
#define SIMULATION_LINKED2

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "LinkedListQueue.cpp"
#include "Customer.h"

class SimulationLinked2
{

	public:
		SimulationLinked2(int = 99999);
		~SimulationLinked2();

		void getArrivals(char*);
		int getShortestLine();
		int getCurrentLine(int);
		void getTellerAvailability(int, int);

		void simulate();
		void processArrival(LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<int>&);
		void processDeparture(LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<int>&);

	private:
		bool firstSim;

		LinkedListQueue<Customer> customerQueue;
		LinkedListQueue<Event> bankLine1, bankLine2, bankLine3;
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
