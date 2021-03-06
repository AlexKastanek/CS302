// Class Header File Information //////////////////////////////////////////////
/**
  * @file FlightMap.v2.h
  *
  * @brief Definition file for Map2 class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Map2 class
  *
  * @version 1.00
  *  		 C.S. Student (18 October 2016)
  *			 Initial development and testing of Map2 class
  *
  * @note None
  *
  */

#ifndef FLIGHT_Map_V2_HEADER_
#define FLIGHT_Map_V2_HEADER_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stack.h"

using namespace std;

class Map2 {
        public:
				Map2();
				~Map2();

				void getInput(char*, char*, char*);
				void getAdjacencyVector();

				int getCityNum(string);
				int getFlight(string, string);
				void getFlights(Stack&);
				int getTotalPrice();

				bool isPath(string, string);
				void outputPath();
				string getNextCity(int, string);
				void markVisited(string);
				void unvisitAll();
                
        private:

				Stack cityStack;

                int numOfFlights, numOfCities, numOfRequests;

				string* cities;
				vector<vector<string> > flights;
				int* flightSize;

				string* source;
				string* destination;
				int* flightNumber;
				vector<int> flightsUsed;
				int* price;

				string* reqSource;
				string* reqDestination;
				bool* visited;
				bool* noPath;
};

#endif

