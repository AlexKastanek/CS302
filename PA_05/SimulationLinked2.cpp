// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file SimulationLinked2.cpp
  *
  * @brief Implementation file for SimulationLinked2 class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the SimulationLinked2 class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of SimulationLinked2 class
  *
  * @note Requires SimulationLinked2.h
  *
  * @note None
  *
  */

#include "SimulationLinked2.h"

/**
  * @brief Constructor for class SimulationLinked2
  *
  * @details Able to construct a SimulationLinked2 object
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
SimulationLinked2::SimulationLinked2(int a)
{
	firstSim = 0;

	numOfCustomers = a;
	numOfEvents = a * 2;
	averageWaitTime = 0;
	maxWaitTime = 0;
	totalWaitTime = 0;
	averageLengthOfLine1 = averageLengthOfLine2 = averageLengthOfLine3 = 0;
	maxLengthOfLine1 = maxLengthOfLine2 = maxLengthOfLine3 = 0;
	totalLengthOfLine1 = totalLengthOfLine2 = totalLengthOfLine3 = 0;
	totalIdleTime1 = totalIdleTime2 = totalIdleTime3 = 0;
	idleStart1 = idleStart2 = idleStart3 = 0;
	idleEnd1 = idleEnd2 = idleEnd3 = 0;
	emptyLine = true;
	arrivals = new Event[numOfCustomers];

}

/**
  * @brief Destructor for class SimulationLinked2
  *
  * @details Able to destruct a SimulationLinked2 object
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
SimulationLinked2::~SimulationLinked2()
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
void SimulationLinked2::getArrivals(char* fileName)
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
  * @brief Gets the shortest line
  *
  * @details Gets the shortest line out of three lines
  *
  * @pre shortestLine defaults at 1
  *
  * @post if any line length is less than 1, shortestLine gets that line number
  *
  * @par Algorithm
  *		 see precondition and postcondition
  *		 also sets emptyLine to true if either of the three lines are empty
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int SimulationLinked2::getShortestLine()
{

	int lineLength1 = bankLine1.getLength();
	int lineLength2 = bankLine2.getLength();
	int lineLength3 = bankLine3.getLength();

	//cout << "length: " << lineLength1 << endl;

	if (lineLength1 == 0 || lineLength2 == 0 || lineLength3 == 0)
	{
		emptyLine = true;
	}

	/*if (teller1)
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
	}*/

	int shortestLine = 1;
	if (lineLength1 > lineLength2)
	{
		shortestLine = 2;
	}
	if (lineLength2 > lineLength3)
	{
		shortestLine = 3;
	}

	return shortestLine;

}

/**
  * @brief Gets the departuring line
  *
  * @details Gets the line number for the correlating departing line
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Compares time to the front event's start time for each line and
  *		 returns the correlating line number
  *
  * @param time
  *
  * @exception None
  *
  * @note: None
  */
int SimulationLinked2::getCurrentLine(int time)
{

	//cout << "bank line 1: " << (bankLine1.peekFront()).getStartTime() << endl;
	//cout << "bank line 2: " << (bankLine2.peekFront()).getStartTime() << endl;
	//cout << "bank line 3: " << (bankLine3.peekFront()).getStartTime() << endl;

	Event frontEvent;
	bool peek;

	peek = bankLine1.peekFront(frontEvent);
	if (time == frontEvent.getStartTime())
	{
		return 1;
	}
	peek = bankLine2.peekFront(frontEvent);
	if (time == frontEvent.getStartTime())
	{
		return 2;
	}
	peek = bankLine3.peekFront(frontEvent);
	if (time == frontEvent.getStartTime())
	{
		return 3;
	}

	return 0;

}

/**
  * @brief Sets each teller's availability
  *
  * @details Sets each teller's availability and sets the general
  *			 tellerAvailable boolean based on the three tellers' individual
  *			 values. Also starts and ends idle time for each.
  *
  * @pre teller1, 2, and 3, as well as tellerAvailability
  *
  * @post preconditions get set based on parameters
  *
  * @par Algorithm
  *		 Depending on the tellerNumber, sets correlating teller's data based on
  *		 time;
  *
  * @param tellerNumber, time
  *
  * @exception None
  *
  * @note: None
  */
void SimulationLinked2::getTellerAvailability(int tellerNumber, int time)
{

	if (tellerNumber == 1)
	{
		teller1 = false;
		idleEnd1 = time;
		totalIdleTime1 = totalIdleTime1 + (idleEnd1 - idleStart1);
		idleStart2 = idleStart2 + time;
		idleStart3 = idleStart3 + time;
	}
	if (tellerNumber == 2)
	{
		teller2 = false;
		idleEnd2 = time;
		totalIdleTime2 = totalIdleTime2 + (idleEnd2 - idleStart2);
		idleStart3 = idleStart3 + time;
		idleStart1 = idleStart1 + time;
	}
	if (tellerNumber == 3)
	{
		teller3 = false;
		idleEnd3 = time;
		totalIdleTime3 = totalIdleTime3 + (idleEnd3 - idleStart3);
		idleStart1 = idleStart1 + time;
		idleStart2 = idleStart2 + time;
	}

	if (!teller1 || !teller2 || !teller3)
	{
		tellerAvailable = false;
	}
	else
	{
		tellerAvailable = true;
	}

}

/**
  * @brief Simulates a bank
  *
  * @details Simulates a bank with three tellers and three lines
  *
  * @pre eventQueue, cutsomerQueue, bankLine (3), and departureQueue are empty
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
  *		 beginning. The multiple bankLine queues, are used to store what 
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
void SimulationLinked2::simulate()
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
		//bankLine1.print();
		if (departureQueue.isEmpty() || arrivalTime < departureTime)
		{
			currentTime = arrivalTime;
			processArrival(arrivalQueue, eventQueue, bankLine, departureQueue);
		} else
		{
			currentTime = departureTime;
			processDeparture(arrivalQueue, eventQueue, bankLine, departureQueue);
		}
		int currentLine = bankLine1.getLength();
		if (currentLine > maxLengthOfLine1)
		{
			maxLengthOfLine1 = currentLine;
		}
		totalLengthOfLine1 = totalLengthOfLine1 + currentLine;
		currentLine = bankLine2.getLength();
		if (currentLine > maxLengthOfLine2)
		{
			maxLengthOfLine2 = currentLine;
		}
		totalLengthOfLine2 = totalLengthOfLine2 + currentLine;
		currentLine = bankLine3.getLength();
		if (currentLine > maxLengthOfLine3)
		{
			maxLengthOfLine3 = currentLine;
		}
		totalLengthOfLine3 = totalLengthOfLine3 + currentLine;
	}

	while (!bankLine1.isEmpty() && !bankLine2.isEmpty() && !bankLine3.isEmpty())
	{
		processDeparture(arrivalQueue, eventQueue, bankLine, departureQueue);
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

		averageWaitTime = (float) totalWaitTime / numOfCustomers;
		averageLengthOfLine1 = (float) totalLengthOfLine1 / numOfEvents;
		averageLengthOfLine2 = (float) totalLengthOfLine2 / numOfEvents;
		averageLengthOfLine3 = (float) totalLengthOfLine3 / numOfEvents;

		cout << "Total simulated time: " << totalSimulatedTime << endl;
		cout << "Average wait time: " << averageWaitTime << endl;
		cout << "Maximum wait time: " << maxWaitTime << endl;
		cout << "Average length of line 1: " << averageLengthOfLine1 << endl;
		cout << "Maximum length of line 1: " << maxLengthOfLine1 << endl;
		//cout << (long int) totalLengthOfLine << endl;
		cout << "Average length of line 2: " << averageLengthOfLine2 << endl;
		cout << "Maximum length of line 2: " << maxLengthOfLine2 << endl;
		cout << "Average length of line 3: " << averageLengthOfLine3 << endl;
		cout << "Maximum length of line 3: " << maxLengthOfLine3 << endl;
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
void SimulationLinked2::processArrival(LinkedListQueue<Event>& arrivalQueue, LinkedListQueue<Event>& eventQueue, LinkedListQueue<Event>& bankLine, LinkedListQueue<int>& departureQueue)
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

	int lineNumber = getShortestLine();
	//cout << "at time " << currentTime << endl;

	//cout << "shortest line: " << lineNumber << endl;

	//cout << tellerAvailable << endl;

	if (emptyLine && tellerAvailable)
	{
		Customer currentCustomer;
		customerQueue.dequeue(currentCustomer);
		//cout << currentTime << "-" << currentCustomer.getArrivalTime() << endl;
		currentCustomer.setWaitTime(currentTime);
		//cout << currentCustomer.getWaitTime() << endl;
		departureQueue.enqueue(currentTime + transactionTime);
		getTellerAvailability(lineNumber, currentTime);
		//cout << tellerAvailable << endl;
	} else
	{
		//bankLine.enqueue(customerArrival);
		if (lineNumber == 1)
		{
			//cout << "test" << endl;
			bankLine1.enqueue(customerArrival);
			//bankLine1.print();
		}
		if (lineNumber == 2)
		{
			bankLine2.enqueue(customerArrival);
		}
		if (lineNumber == 3)
		{
			bankLine3.enqueue(customerArrival);
		}
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
void SimulationLinked2::processDeparture(LinkedListQueue<Event>& arrivalQueue, LinkedListQueue<Event>& eventQueue, LinkedListQueue<Event>& bankLine, LinkedListQueue<int>& departureQueue)
{

	int departureTime;
	departureQueue.dequeue(departureTime);

	Event customerDeparture('D', departureTime, 0);
	eventQueue.enqueue(customerDeparture);

	Customer currentCustomer;
	bool peek = customerQueue.peekFront(currentCustomer);
	//cout << "customer: " << currentCustomer.getArrivalTime() << endl;
	int lineNumber = getCurrentLine(currentCustomer.getArrivalTime());
	//cout << lineNumber << endl;

	//cout << emptyLine << endl;

	if (lineNumber == 1)
	{
		emptyLineSpec = bankLine1.isEmpty();
	}
	if (lineNumber == 2)
	{
		emptyLineSpec = bankLine2.isEmpty();
	}
	if (lineNumber == 3)
	{
		emptyLineSpec = bankLine3.isEmpty();
	}

	if (!emptyLineSpec)
	{
		//Customer currentCustomer;
		customerQueue.dequeue(currentCustomer);
		currentCustomer.setWaitTime(currentTime);
		int newWaitTime = currentCustomer.getWaitTime();
		if (newWaitTime > maxWaitTime)
		{
			maxWaitTime = newWaitTime;
		}
		totalWaitTime = totalWaitTime + newWaitTime;

		Event nextCustomer;
		//bankLine.dequeue(nextCustomer);
		if (lineNumber == 1)
		{
			bankLine1.dequeue(nextCustomer);
		}
		if (lineNumber == 2)
		{
			bankLine2.dequeue(nextCustomer);
		}
		if (lineNumber == 3)
		{
			bankLine3.dequeue(nextCustomer);
		}
		departureQueue.enqueue(currentTime + nextCustomer.getLength());
	}
	else
	{
		tellerAvailable = true;
		//idleStart = currentTime;
		if (lineNumber == 1)
		{
			teller1 = true;
			idleStart1 = currentTime;
		}
		if (lineNumber == 2)
		{
			teller2 = true;
			idleStart2 = currentTime;
		}
		if (lineNumber == 3)
		{
			teller3 = true;
			idleStart3 = currentTime;
		}
		emptyLine = true;
	}

}




















