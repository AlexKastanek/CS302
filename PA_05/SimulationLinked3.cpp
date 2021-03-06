// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file SimulationLinked3.cpp
  *
  * @brief Implementation file for SimulationLinked3 class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the SimulationLinked class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of SimulationLinked3 class
  *
  * @note Requires SimulationLinked3.h
  *
  * @note None
  *
  */

#include "SimulationLinked3.h"

/**
  * @brief Constructor for class SimulationLinked3
  *
  * @details Able to construct a SimulationLinked3 object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param a defaults at 99999
  *
  * @exception None
  *
  * @note: None
  */
SimulationLinked3::SimulationLinked3(int a)
{
	firstSim = 0;

	numOfCustomers = a;
	numOfEvents = a * 2;
	averageWaitTime = 0;
	maxWaitTime = 0;
	totalWaitTime = 0;
	averageLengthOfLine = 0;
	maxLengthOfLine = 0;
	totalLengthOfLine = 0;
	totalIdleTime1 = totalIdleTime2 = totalIdleTime3 = 0;
	idleStart1 = idleStart2 = idleStart3 = 0;
	idleEnd1 = idleEnd2 = idleEnd3 = 0;
	arrivals = new Event[numOfCustomers];

}

/**
  * @brief Destructor for class SimulationLinked3
  *
  * @details Able to destruct a SimulationLinked3 object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
SimulationLinked3::~SimulationLinked3()
{

	delete[] arrivals;
	arrivals = NULL;

}

/**
  * @brief Gets input from file
  *
  * @details Gets input from file, specifically, a file of integers in 
  *			 numerical order that will be used for the arrivalQueue
  *
  * @pre arrivals is empty
  *
  * @post arrivals contains all of the integers from the file
  *
  * @par Algorithm
  *		 For the amount of customers in this simulation, loop goes through the
  *		 specified file and sets the parameters of the array of events called
  *		 arrivals
  *
  * @param fileName
  *
  * @exception None
  *
  * @note: None
  */
void SimulationLinked3::getArrivals(char* fileName)
{

	ifstream fin;

	fin.open(fileName);
	for (int i = 0; i < numOfCustomers; i++)
	{
		int temp;
		fin >> temp;
		arrivals[i].setStartTime(temp);
		arrivals[i].randomizeLength(100);
	}

	fin.close();

}

/**
  * @brief Determines teller's availability
  *
  * @details Returns which teller is available
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Depending on the data of the individual tellers, returns specific
  *		 teller's number if it is available
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int SimulationLinked3::getTellerAvailability()
{

	if (!teller1 && !teller2 && !teller3)
	{
		tellerAvailable = false;
		return 0;
	}
	if (teller1)
	{
		return 1;
	}
	if (teller2)
	{
		return 2;
	}
	if (teller3)
	{
		return 3;
	}

}

/**
  * @brief Returns which teller is unavailable
  *
  * @details None
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 If teller is unavailable, return teller number
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int SimulationLinked3::getTeller()
{

	if (!teller1)
	{
		return 1;
	}
	if (!teller2)
	{
		return 2;
	}
	if (!teller3)
	{
		return 3;
	}

}

/**
  * @brief Simulates a bank
  *
  * @details Simulates a bank with three tellers and one lines
  *
  * @pre eventQueue, cutsomerQueue, bankLine, and departureQueue are empty
  *
  *	@pre arrivalQueue is immediately filled with arrivals
  *
  * @post As arrivalQueue is dequeued, the other queues get enqueued with data
  *		  and then dequeued according to the arrivals' specification
  *
  * @par Algorithm
  *		 My implementation is a little bit different than the book's. Instead 
  *		 of a priority queue, I used three different queues, and arrivalQueue,
  *		 departureQueue, and an eventQueue. The eventQueue does not do anything
  *		 except store all the events that occur throughout the algorithm for
  *		 output at the end of the algorithm. arrivalQueue is instantly enqueued
  *		 with all of its data and it no longer gets enqueued throughout the
  *		 algorithm. After enqueing all of the arrivals, it checks what is at
  *		 the front of the arrivalQueue and at the front of departureQueue. It
  *		 then uses this data to determine which one it will process. If the
  *		 arrivalQueue's front time is earlier than the departureQueue's, then
  *		 it will process an arrival first and vice versa. It also checks if the
  *		 departureQueue is empty, which it is at the very beginning. It then
  *		 processes an arrival if this is so, which is always true at the
  *		 beginning. The bankLine queues is used to store what 
  *		 customers are still waiting in line by simply enqueing the arrival
  *		 event when it occurs and then dequeing it once the departure time of
  *		 the event has been determined. A fifth queue, customerQueue, is only
  *		 used to store the wait time of each arriving customer. After the first
  *		 loop finishes, there are still departures that haven't been processed,
  *		 so it empties the bank line and processes the departures.
  *
  * @param None
  *
  * @exception None
  *
  * @note: Departure upon output will be out of order simply because I did not
  *		   have enough time to implement more departureQueues to correlate with
  *		   the multiple tellers. This means that the departureQueue is just out
  *		   of order because its holding what is technically three different 
  *		   queues. The algorithm is run correctly though and the data is mostly
  *		   correct as well.
  */
void SimulationLinked3::simulate()
{

	LinkedListQueue<int> departureQueue;
	LinkedListQueue<Event> arrivalQueue, eventQueue, bankLine;

	tellerAvailable = true;
	teller1 = true;
	teller2 = true;
	teller3 = true;

	for (int i = 0; i < numOfCustomers; i++)
	{
		//cout << arrivals[i];
		arrivalQueue.enqueue(arrivals[i]);
	}

	//arrivalQueue.printToFile((char*)"arrivalQueue");

	while (!arrivalQueue.isEmpty())
	{
		int arrivalTime, departureTime;
		Event temp;
		bool peek = arrivalQueue.peekFront(temp);
		arrivalTime = temp.getStartTime();
		peek = departureQueue.peekFront(departureTime);
		peek = arrivalQueue.peekFront(temp);
		transactionTime = temp.getLength();
		//departureQueue.print();
		//customerQueue.print();
		if (departureQueue.isEmpty() || arrivalTime < departureTime)
		{
			currentTime = arrivalTime;
			processArrival(arrivalQueue, eventQueue, bankLine, departureQueue);
		} else
		{
			currentTime = departureTime;
			processDeparture(arrivalQueue, eventQueue, bankLine, departureQueue);
		}
		int currentLine = bankLine.getLength();
		if (currentLine > maxLengthOfLine)
		{
			maxLengthOfLine = currentLine;
		}
		totalLengthOfLine = totalLengthOfLine + currentLine;
	}

	while (!bankLine.isEmpty())
	{
		processDeparture(arrivalQueue, eventQueue, bankLine, departureQueue);
		int currentLine = bankLine.getLength();
		totalLengthOfLine = totalLengthOfLine + currentLine;
	}

	int totalSimulatedTime;

	while (!departureQueue.isEmpty())
	{
		int departureTime;
		departureQueue.dequeue(departureTime);
		totalSimulatedTime = departureTime;
	
		Event customerDeparture('D', departureTime, 0);
		eventQueue.enqueue(customerDeparture);
	}
	
		eventQueue.printToFile((char*)"Events", !firstSim);

		averageWaitTime = ((float) totalWaitTime / numOfCustomers);
		averageLengthOfLine = (float) totalLengthOfLine / numOfEvents;

		cout << "Total simulated time: " << totalSimulatedTime << endl;
		cout << "Average wait time: " << averageWaitTime << endl;
		cout << "Maximum wait time: " << maxWaitTime << endl;
		cout << "Average length of line: " << averageLengthOfLine << endl;
		cout << "Maximum length of line: " << maxLengthOfLine << endl;
		//cout << (long int) totalLengthOfLine << endl;
		cout << "Total idle time of first teller: " << totalIdleTime1 << endl;
		cout << "Total idle time of second teller: " << totalIdleTime2 << endl;
		cout << "Total idle time of third teller: " << totalIdleTime3 << endl;

}

/**
  * @brief processes an arrival
  *
  * @details dequeus the arrivalQueue, enqueues the eventQueue, enqueues the
  *			 bankLine if necessary otherwise it enqueues the departureQueue
  *
  * @pre tellerAvailable will either be available or unavailable
  *
  * @post tellerAvailable will be unavailable if it was available
  *
  * @par Algorithm
  *		 First, it dequeues from the arrivalQueue and then enqueues that on to
  *		 the eventQueue. Then it creates a customer and sets its arrival time,
  *		 which is necessary for tracking its wait time. If the line is empty
  *		 and a teller is available, then wait time is 0, determines the
  *		 departure time, enqueues that on to departureQueue, ends the idle time
  *		 for the teller, and sets tellerAvailable to false. Otherwise it
  *		 enqueues the customer's arrival onto the correct bankLine.
  *
  * @param see details for parameter specifications
  *
  * @exception None
  *
  * @note: None
  */
void SimulationLinked3::processArrival(LinkedListQueue<Event>& arrivalQueue, LinkedListQueue<Event>& eventQueue, LinkedListQueue<Event>& bankLine, LinkedListQueue<int>& departureQueue)
{

	Event customerArrival;
	arrivalQueue.dequeue(customerArrival);
	
	eventQueue.enqueue(customerArrival);
	/*int index;
	while (customerArrival.startTime() != arrivals[i].startTime())
	{
		index++;
	}*/
	Customer newCustomer;
	//cout << currentTime << endl;
	newCustomer.setArrivalTime(currentTime);
	customerQueue.enqueue(newCustomer);

	int tellerNumber = getTellerAvailability();

	if (bankLine.isEmpty() && tellerAvailable)
	{
		Customer currentCustomer;
		customerQueue.dequeue(currentCustomer);
		//cout << currentTime << "-" << currentCustomer.getArrivalTime() << endl;
		currentCustomer.setWaitTime(currentTime);
		//cout << currentCustomer.getWaitTime() << endl;
		departureQueue.enqueue(currentTime + transactionTime);
		//tellerAvailable = false;
		//idleEnd = currentTime;
		//totalIdleTime = totalIdleTime + (idleEnd - idleStart);
		if (tellerNumber == 1)
		{
			teller1 = false;
			idleEnd1 = currentTime;
			totalIdleTime1 = totalIdleTime1 + (idleEnd1 - idleStart1);
		}
		if (tellerNumber == 2)
		{
			teller2 = false;
			idleEnd2 = currentTime;
			totalIdleTime2 = totalIdleTime2 + (idleEnd2 - idleStart2);
		}
		if (tellerNumber == 3)
		{
			teller3 = false;
			idleEnd3 = currentTime;
			totalIdleTime3 = totalIdleTime3 + (idleEnd3 - idleStart3);
		}
	} else
	{
		bankLine.enqueue(customerArrival);
	}

}

/**
  * @brief processes a departure
  *
  * @details dequeus the departure, enqueues the eventQueue, dequeues the
  *			 bankLine if necessary
  *
  * @pre tellerAvailable will either be unavailable
  *
  * @post tellerAvailable will be available if the bankLine is empty
  *
  * @par Algorithm
  *		 First, it dequeues from the departureQueue and then enqueus that on to
  *		 the eventQueue. It checks if the correct bankLine is empty. If it is
  *		 not, then it dequeus the customer from that bank line and determines
  *		 the customer's wait time. It is then able to determine the departure
  *		 time of that customer. If the correct bankLine is not empty anymore
  *		 then the teller's idleTime starts and its availability is set to true.
  *
  * @param see details for parameter specifications
  *
  * @exception None
  *
  * @note: None
  */
void SimulationLinked3::processDeparture(LinkedListQueue<Event>& arrivalQueue, LinkedListQueue<Event>& eventQueue, LinkedListQueue<Event>& bankLine, LinkedListQueue<int>& departureQueue)
{

	int departureTime;
	departureQueue.dequeue(departureTime);

	Event customerDeparture('D', departureTime, 0);
	eventQueue.enqueue(customerDeparture);

	int tellerNumber = getTeller();

	if (!bankLine.isEmpty())
	{
		Customer currentCustomer;
		customerQueue.dequeue(currentCustomer);
		currentCustomer.setWaitTime(currentTime);
		int newWaitTime = currentCustomer.getWaitTime();
		if (newWaitTime > maxWaitTime)
		{
			maxWaitTime = newWaitTime;
		}
		totalWaitTime = totalWaitTime + newWaitTime;

		Event nextCustomer;
		bankLine.dequeue(nextCustomer);
		departureQueue.enqueue(currentTime + nextCustomer.getLength());
	}
	else
	{
		tellerAvailable = true;
		//idleStart = currentTime;
		if (tellerNumber == 1)
		{
			teller1 = true;
			idleStart1 = currentTime;
		}
		if (tellerNumber == 2)
		{
			teller2 = true;
			idleStart2 = currentTime;
		}
		if (tellerNumber == 3)
		{
			teller3 = true;
			idleStart3 = currentTime;
		}
	}

}




















