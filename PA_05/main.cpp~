#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Queue.cpp"
#include "LinkedListQueue.cpp"
#include "Event.h"
#include "RadixSort.h"
#include "Simulation1.h"
#include "Simulation2.h"
#include "Simulation3.h"
#include "SimulationLinked1.h"
#include "SimulationLinked2.h"
#include "SimulationLinked3.h"

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{

		int* arrivalTimes = new int[99999];

		for (int j = 0; j < 99999; j++)
		{
			arrivalTimes[j] = rand() % 100000 + 1;
		}

		RadixSort radix;

		radix.sort(arrivalTimes, 99999, 6);

		ofstream fout;

		fout.open("arrivalTimes");

		for (int j = 0; j < 99999; j++)
		{
			fout << arrivalTimes[j] << endl;
		}

		fout.close();

		fout.open("Events", ios_base::app);
		fout << "================================================================================" << endl;
		fout << "================================================================================" << endl;
		fout << "running...RUN" << i << endl;
		fout << "================================================================================" << endl;
		fout << "================================================================================" << endl << endl;

		fout << "================================================================================" << endl;
		fout << "********************************************************************************" << endl;
		fout << "ARRAY-BASED ONE LINE ONE TELLER" << endl;
		fout << "********************************************************************************" << endl;
		fout << "================================================================================" << endl << endl;

		fout.close();

		cout << "======================================" << endl;
		cout << "running...RUN" << i << endl;
		cout << "======================================" << endl << endl;

		cout << "--------------------------------------" << endl;
		cout << "ARRAY-BASED ONE LINE ONE TELLER" << endl;
		cout << "--------------------------------------" << endl << endl;

		clock_t time1;
		time1 = clock();
		Simulation1 singleTeller;
		singleTeller.getArrivals((char*)"arrivalTimes");
		singleTeller.simulate();
		time1 = clock() - time1;
		cout << "Total CPU time: " << ((float)time1/CLOCKS_PER_SEC) << " seconds." << endl << endl;

		fout.open("Events", ios_base::app);

		fout << endl << "================================================================================" << endl;
		fout << "********************************************************************************" << endl;
		fout << "ARRAY-BASED THREE LINES THREE TELLERS" << endl;
		fout << "********************************************************************************" << endl;
		fout << "================================================================================" << endl << endl;

		fout.close();

		cout << "--------------------------------------" << endl;
		cout << "ARRAY-BASED THREE LINES THREE TELLERS" << endl;
		cout << "--------------------------------------" << endl << endl;

		clock_t time2;
		time2 = clock();
		Simulation2 tripleTeller1;
		tripleTeller1.getArrivals((char*)"arrivalTimes");
		tripleTeller1.simulate();
		time2 = clock() - time2;
		cout << "Total CPU time: " << ((float)time2/CLOCKS_PER_SEC) << " seconds." 	<< endl << endl;
	
		fout.open("Events", ios_base::app);
	
		fout << endl << 	"================================================================================" 	<< endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << "ARRAY-BASED ONE LINE THREE TELLERS" << endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << 	"================================================================================" 	<< endl << endl;
	
		fout.close();
	
		cout << "--------------------------------------" << endl;
		cout << "ARRAY-BASED ONE LINE THREE TELLERS" << endl;
		cout << "--------------------------------------" << endl << endl;
	
		clock_t time3;
		time3 = clock();
		Simulation3 tripleTeller2;
		tripleTeller2.getArrivals((char*)"arrivalTimes");
		tripleTeller2.simulate();
		time3 = clock() - time3;
		cout << "Total CPU time: " << ((float)time3/CLOCKS_PER_SEC) << " seconds." 	<< endl << endl;
	
		fout.open("Events", ios_base::app);
	
		fout << 	"================================================================================" 	<< endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << "LINKED-LIST ONE LINE ONE TELLER" << endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << 	"================================================================================" 	<< endl << endl;
	
		fout.close();
	
		cout << "--------------------------------------" << endl;
		cout << "LINKED-LIST ONE LINE ONE TELLER" << endl;
		cout << "--------------------------------------" << endl << endl;
	
		clock_t time4;
		time4 = clock();
		SimulationLinked1 singleTellerL;
		singleTellerL.getArrivals((char*)"arrivalTimes");
		singleTellerL.simulate();
		time4 = clock() - time4;
		cout << "Total CPU time: " << ((float)time4/CLOCKS_PER_SEC) << " seconds." 	<< endl << endl;
	
		fout.open("Events", ios_base::app);
	
		fout << endl << 	"================================================================================" 	<< endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << "LINKED-LIST THREE LINES THREE TELLERS" << endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << 	"================================================================================" 	<< endl << endl;
	
		fout.close();
	
		cout << "--------------------------------------" << endl;
		cout << "LINKED-LIST THREE LINES THREE TELLERS" << endl;
		cout << "--------------------------------------" << endl << endl;
	
		clock_t time5;
		time5 = clock();
		SimulationLinked2 tripleTeller1L;
		tripleTeller1L.getArrivals((char*)"arrivalTimes");
		tripleTeller1L.simulate();
		time5 = clock() - time5;
		cout << "Total CPU time: " << ((float)time5/CLOCKS_PER_SEC) << " seconds." 	<< endl << endl;
	
		fout.open("Events", ios_base::app);
	
		fout << endl << 	"================================================================================" 	<< endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << "LINKED-LIST ONE LINE THREE TELLERS" << endl;
		fout << 	"********************************************************************************" 	<< endl;
		fout << 	"================================================================================" 	<< endl << endl;
	
		fout.close();
	
		cout << "--------------------------------------" << endl;
		cout << "LINKED-LIST ONE LINE THREE TELLERS" << endl;
		cout << "--------------------------------------" << endl << endl;
	
		clock_t time6;
		time6 = clock();
		SimulationLinked3 tripleTeller2L;
		tripleTeller2L.getArrivals((char*)"arrivalTimes");
		tripleTeller2L.simulate();
		time6 = clock() - time6;
		cout << "Total CPU time: " << ((float)time6/CLOCKS_PER_SEC) << " seconds." 	<< endl << endl;
	
	}

}


