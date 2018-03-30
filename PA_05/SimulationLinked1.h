// Class Header File Information //////////////////////////////////////////////
/**
  * @file SimulationLinked1.h
  *
  * @brief Definition file for SimulationLinked1 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the SimulationLinked1 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of SimulationLinked1 class
  *
  * @note None
  *
  */

#ifndef SIMULATION_LINKED1
#define SIMULATION_LINKED1

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "LinkedListQueue.cpp"
#include "Customer.h"

class SimulationLinked1
{

	public:
		SimulationLinked1(int = 99999);
		~SimulationLinked1();

		void getArrivals(char*);

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
		bool tellerAvailable;
		int totalIdleTime, idleStart, idleEnd;

};

#endif
