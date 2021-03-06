// Class Header File Information //////////////////////////////////////////////
/**
  * @file SimulationLinked3.h
  *
  * @brief Definition file for SimulationLinked3 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the SimulationLinked3 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of SimulationLinked3 class
  *
  * @note None
  *
  */

#ifndef SIMULATION_LINKED3
#define SIMULATION_LINKED3

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "LinkedListQueue.cpp"
#include "Customer.h"

class SimulationLinked3
{

	public:
		SimulationLinked3(int = 99999);
		~SimulationLinked3();

		void getArrivals(char*);
		int getTellerAvailability();
		int getTeller();

		void simulate();
		void processArrival(LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<int>&);
		void processDeparture(LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<Event>&, LinkedListQueue<int>&);

	private:
		bool firstSim;

		LinkedListQueue<Customer> customerQueue;
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
