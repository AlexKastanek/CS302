// Class Header File Information //////////////////////////////////////////////
/**
  * @file Simulation1.h
  *
  * @brief Definition file for Simulation1 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Simulation1 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of Simulation1 class
  *
  * @note None
  *
  */

#ifndef SIMULATION1
#define SIMULATION1

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Event.h"
#include "Queue.cpp"
#include "Customer.h"

class Simulation1
{

	public:
		Simulation1(int = 99999);
		~Simulation1();

		void getArrivals(char*);

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
		bool tellerAvailable;
		int totalIdleTime, idleStart, idleEnd;

};

#endif
