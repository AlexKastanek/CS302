// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file FlightMap.v2.cpp
  *
  * @brief Implementation file for Map2 class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the Map2 class
  *
  * @version 1.00
  *  		 C.S. Student (18 October 2016)
  *			 Initial development and testing of Map2 class
  *
  * @note Requires FlightMap.v2.h
  *
  * @note Not much of a difference from this file to FlightMap.v1.cpp. 
  * 	  Increases the efficiency of isPath function by checking another array
  *		  of booleans, and it implements the flight numbers and prices and
  *		  outputs those.
  *
  */

#ifndef FLIGHT_Map_V2_
#define FLIGHT_Map_V2_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "stack.h"
#include "FlightMap.v2.h"

using namespace std;

/**
  * @brief Constructor for class Map2
  *
  * @details Able to construct a Map2 object
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
Map2::Map2()
{

}

/**
  * @brief Destructor for class Map2
  *
  * @details Able to destruct a Map2 object
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
  * @note: deleting these pointers causes a seg fault
  */
Map2::~Map2()
{

	/*delete[] cities;
	cities = NULL;

	delete[] flights;
	flights = NULL;

	delete[] source;
	source = NULL;

	delete[] destination;
	destination = NULL;

	delete[] flightNumber;
	flightNumber = NULL;

	delete[] price;
	price = NULL;*/

}

/**
  * @brief Gets input class Map2
  *
  * @details Using three file names as parameters, gets input for each of the
  * 		 specified files and decodes them using various ifstream functions
  *
  * @pre numOfCities
  *
  * @pre numOfFlights
  *
  * @pre numOfRequests
  *
  * @pre cities
  *
  * @pre source & destination
  * 
  * @pre reqSource & reqDestination
  *
  * @post allocates memory for and gets value for all preconditions
  *
  * @par Algorithm
  *		 uses getline function to search through cityFile
  *
  * @par Algorithm
  *		 uses various ifstream functions to search through flightFile and
  *	 	 requestFile like unget and operator >>  as well as string functions 
  *		 like at and append
  *
  * @param cityFile
  *
  * @param flightFile
  *
  * @param requestFile
  *
  * @exception None
  *
  * @note: None
  */
void Map2::getInput(char* cityFile, char* flightFile, char* requestFile)
{

	ifstream fin;

	fin.open(cityFile);
	numOfCities = 0;
	string currentLine;
	while (getline(fin, currentLine))
	{
		numOfCities++;
	}
	fin.close();
	
	//cout << numOfCities << endl; //debugging

	cities = new string[numOfCities];
	visited = new bool[numOfCities];
	noPath = new bool[numOfCities];
	fin.open(cityFile);
	for (int i = 0; i < numOfCities; i++)
	{
		getline(fin, cities[i]);
	}
	//debugging
	/*for (int i = 0; i < numOfCities; i++)
	{
		cout << cities[i] << endl;
	}*/
	fin.close();
	unvisitAll();

	fin.open(flightFile);
	numOfFlights = 0;
	while (getline(fin, currentLine))
	{
		numOfFlights++;
	}
	//cout << numOfFlights << endl; //debugging
	fin.close();

	fin.open(flightFile);
	source = new string[numOfFlights];
	destination = new string[numOfFlights];
	flightNumber = new int[numOfFlights];
	price = new int[numOfFlights];
	for (int i = 0; i < numOfFlights; i++)
	{
		fin >> source[i];
		if (source[i].at(source[i].size() - 1) != ',')
		{
			string remainingString;
			fin >> remainingString;
			source[i].append(" ");
			source[i].append(remainingString);
		}
		source[i].erase(source[i].end() - 1);
		fin >> destination[i];
		char whiteSpace, nextCharacter;
		fin.get(whiteSpace);
		fin.get(nextCharacter);
		fin.unget();
		//cout << nextCharacter << endl; //debugging
		if (nextCharacter >= 'A')
		{
			string remainingString;
			fin >> remainingString;
			destination[i].append(" ");
			destination[i].append(remainingString);
		}
		fin >> flightNumber[i];
		fin >> price[i];
	}
	fin.close();

	//debugging
	/*for (int i = 0; i < numOfFlights; i++)
	{
		cout << source[i] << " ";
		cout << destination[i] << " ";
		cout << flightNumber[i] << " ";
		cout << price[i] << endl;
	}*/

	fin.open(requestFile);
	numOfRequests = 0;
	while (getline(fin, currentLine))
	{
		numOfRequests++;
	}
	fin.close();
	//cout << numOfRequests << endl; //debugging

	fin.open(requestFile);
	reqSource = new string[numOfRequests];
	reqDestination = new string[numOfRequests];
	for (int i = 0; i < numOfRequests; i++)
	{
		fin >> reqSource[i];
		//cout << reqSource[i] << " "; //debugging
		if (reqSource[i].at(reqSource[i].size() - 1) != ',')
		{
			string remainingString;
			fin >> remainingString;
			reqSource[i].append(" ");
			reqSource[i].append(remainingString);
		}
		//cout << reqSource[i] << ","; //debugging
		reqSource[i].erase(reqSource[i].end() - 1);
		fin >> reqDestination[i];
		//cout << reqDestination[i] << " "; //debugging
		char nextCharacter;
		fin.get(nextCharacter);
		if (nextCharacter == ' ')
		{
			string remainingString;
			fin >> remainingString;
			reqDestination[i].append(" ");
			reqDestination[i].append(remainingString);
		}
		//cout << reqDestination[i] << endl; //debugging
	}
	fin.close();

	//debugging
	/*for (int i = 0; i < numOfRequests; i++)
	{
		cout << reqSource[i] << " -> " << reqDestination[i] << endl;
	}*/

}

/**
  * @brief Gets adjacency list for class Map2 using a vector
  *
  * @details Searches through flightFile and matches flights with cities in order to get an adjacency list for each city
  *
  * @pre flights
  *
  * @pre flightSize
  *
  * @post flights is a vector of vectors that gets each starting city and then
  *		  that city is the first index of another vector that gets each 
  *		  connected city
  *
  * @post flightSize is an integer that stores the size of each vector
  *
  * @par Algorithm
  *		 Begins by pushing an empty vector onto a vector until the numOfCities
  *		 is reached, this allows each city to have a connecting flight list. 
  *		 Then pushes the first city onto each vector which is as simples as 
  *		 going through cities and pushing everyone on the new vector. 
  * 	 Then compares cities and flights and pushes the destinations of 
  * 	 flights that have the same source name as whatever city the loop is
  *	 	 currently on.
  *
  * @par Algorithm
  *		 Gets each vector's size by calling the size function in the vector
  *		 library. This is so we know how many connecting flights that city has
  *		 and we don't step out of bounds.
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void Map2::getAdjacencyVector()
{

	//for the number of cities, pushes empty vector onto flights vector
	for(int i = 0; i < numOfCities; i++)
	{
		flights.push_back(vector<string>());
		//cout << cities[i] << endl; //debugging
	}

	//for the number of cities, pushes cities[i] (each city) onto flights vector
	for(int i = 0; i < numOfCities; i++)
	{
		flights[i].push_back(cities[i]);
		//cout << cities[i] << endl; //debugging
	}

	//for every adjacency list (one for each city), pushes connecting flights onto flights[i] vector (flights[i] being the adjacency list for a city)
	for(int i = 0; i < numOfCities; i++)
	{
		for(int j = 0; j < numOfFlights; j++)
		{
			//cout << cities[i] << "," << source[j] << endl; //debugging
			//finds connecting flights by comparing the adjacency list's starting city with every source, if a matching source is found (meaning the two cities are the same name), then pushes on the respective destination
			if (cities[i].compare(source[j]) == 0)
			{
				//cout << cities[i] << "," << source[j] << endl; //debugging
				flights[i].push_back(destination[j]);
			}
		}
	}

	//gets size of each city's adjacency list
	flightSize = new int[numOfCities];

	for (int i = 0; i < numOfCities; i++)
	{
		flightSize[i] = flights[i].size();
	}

}

/**
  * @brief gets index of city in list cities
  *
  * @details gets index of city by going through cities and comparing each 
  * 		 city to called city
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Goes through cities and comparing city to every city and returning 
  *		 the index once the city is found, returns -1 if no city is found
  *
  * @param city
  *
  * @exception None
  *
  * @note: None
  */
int Map2::getCityNum(string city)
{

	for (int i = 0; i < numOfCities; i++)
	{
		if (city.compare(cities[i]) == 0)
		{
			return i;
		}
	}

	return -1;

}

/**
  * @brief returns flight number for flight from one city to the other
  *
  * @details returns flight number by comparing fromCity and toCity with
  *			 source[i] and destination[i]
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 returns flight number by comparing fromCity and toCity with source[i]
  *		 and destination[i]. i gets incremented while both fromCity !=
  *		 source[i] and toCity != source[i]
  *
  * @param fromCity
  *
  *	@param toCity
  *
  * @exception None
  *
  * @note: None
  */
int Map2::getFlight(string fromCity, string toCity)
{

	int i = 0;
	while ((fromCity.compare(source[i]) != 0) || (toCity.compare(destination[i]) != 0))
	{
		i++;
	}

	//cout << fromCity << ", " << toCity << endl; //debugging

	return flightNumber[i];

}

/**
  * @brief Creates vector of flight numbers
  *
  * @details Creates vector of flight numbers depending on if they were used in
  *			 cityStack or not
  *
  * @pre flightsUsed
  *		 empty vector
  *
  * @post flightsUsed
  *		  vector now filled with flight numbers of flights that were used in
  *		  cityStack
  *
  * @par Algorithm
  *		 Pops top from path and restores it in cityStack, getting the flight
  *		 number for every city that gets popped after the first one. Decides
  *		 which to cities to send to getFlight function by using modulus
  *		 division. city2 gets temp if i is an even number and city1 gets temp
  *		 if i is an odd number.
  *
  * @param path (passed by reference)
  *		   note that path is the reverse of cityStack
  *
  * @exception None
  *
  * @note: None
  */
void Map2::getFlights(Stack &path)
{

	int i = 0;
	string city1, city2;
	path.pop(city1);
	cityStack.push(city1);
	while (!path.empty())
	{
		string temp;
		path.pop(temp);
		if (i % 2 == 0)
		{
			city2 = temp;
			flightsUsed.push_back(getFlight(city1, city2));
		}
		else
		{
			city1 = temp;
			flightsUsed.push_back(getFlight(city2, city1));
		}
		cityStack.push(temp);
		//cout << city1 << ", " << city2 << endl; //debugging
		i++;	
	}

}

/**
  * @brief Sums all of the prices of flights used in cityStack
  *
  * @details Sums all of the prices of flights used in cityStack by using the
  *			 flightsUsed vector that was created previously
  *
  * @pre totalPrice intializes at 0
  *
  * @post totalPrice gets the sum of all prices of flights used in cityStack
  *
  * @par Algorithm
  *		 For the amount of flights in the flightsUsed vector, compares the
  *		 current flight in flightsUsed with every other flight while
  *		 incrementing j until a match is found. When a match is found j is used
  *		 as the index of price array and price[j] is added to totalPrice
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
int Map2::getTotalPrice()
{

	int totalPrice = 0;
	for (int i = 0; i < flightsUsed.size(); i++)
	{
		int j = 0;
		while (flightNumber[j] != flightsUsed[i])
		{
			j++;
		}
		totalPrice = totalPrice + price[j];
	}

	return totalPrice;

}

/**
  * @brief finds path from one city to the other if there is one
  *
  * @details finds path and sets stack of cities visited during path from
  *			 originCity to destinationCity, returns 1 if path is found and 0 if 
  * 		 not
  *
  * @pre cityStack
  *      Stack should be empty and is cleared if it is not.
  *
  * @post cityStack
  *		  CityStack gets cleared and then cities are pushed onto cityStack if 
  *		  there is a possible path from the top city of the stack and items are
  *		  popped from cityStack if there is no possible path from the top of 
  *		  the stack.
  *
  * @par Algorithm
  *		 Runs so long as cityStack is not empty or the top of the stack does 
  * 	 not equal destinationCity. If the stack is empty, there are no 
  *		 possible flights and function returns false. 
  *
  *	@par Algorithm
  *		 Runs so long as the next city is not a city that does not have a path.
  *		 Keeps calling getNextCity and next city gets the value it returns.
  *	     
  *
  * @par Algorithm
  *		 Runs so long as the next city is not a city that has already been 
  *		 marked as visited. Keeps calling getNextCity and next city gets the 
  *		 value it returns. If the next city is whitespace " " then there are 
  * 	 no more possible routes for the top city and it is popped from the 
  * 	 stack.
  *
  *  @par Algorithm
  *		  Logs to "HPAir.log1.txt" different debugging statements and 
  * 	  statements that let user know where the function is when something
  *	      happens. Outputs the contents of cityStack whenever a change is made
  *		  or is about to be made.
  *
  * @param originCity
  * 	   gets value of reqSource[i], i depends on which request program is
  * 	   currently running
  *
  * @param destinationCity
  *		   gets value of reqDestination[i], i depends on which request program
  *		   is currently running
  *
  * @exception None
  *
  * @note: None
  */
bool Map2::isPath(string originCity, string destinationCity) //read log for full documentation of algorithms used in this function
{

	ofstream log;

	log.open("HPAir.log2.txt", ios_base::app);
	log << "--------------------------------------------------------------------------------" << endl << endl;

	log << "Clearing cityStack if not empty, clearing marks on all cities" << endl;
	if (!cityStack.empty())
	{
		cityStack.clear();
	}

	unvisitAll();

	log << "Calling getCityNum for originCity and destinationCity" << endl;
	int originNumber = getCityNum(originCity);
	int destinationNumber = getCityNum(destinationCity);
	log << "destinationNumber = " << destinationNumber << ", originNumber = " << originNumber << endl;
	if (originNumber == -1 || destinationNumber == -1)
	{
		log << "returning false" << endl;
		return false;
	}

	log << "Pushing originCity on to empty stack and marking as visited" << endl;
	cityStack.push(originCity);
	markVisited(originCity);

	string topCity = cityStack.peek();
	log << "topCity = " << topCity << endl;
	int topCityNum = originNumber;
	log << "topCityNum gets originNumber" << endl << endl;
	
	log << "begin while loop... will loop until stack is empty or destination is found" << endl;
	while (!cityStack.empty() && !noPath[topCityNum] && topCity != destinationCity)
	{
		log << "Stack at beginning of loop: " << endl << cityStack << endl;
		string nextCity = getNextCity(topCityNum, topCity);
		log << "nextCity = " << nextCity << endl;
		int nextCityNum = getCityNum(nextCity);
		log << "nextCityNum = " << nextCityNum << endl;
		log << "begin while loop... will loop until nextCity is a city that potentially has a path" << endl;
		while(noPath[nextCityNum])
		{
			log << "noPath = " << noPath[nextCityNum] << endl;
			string badCity = nextCity;
			nextCity = getNextCity(topCityNum, badCity);
			nextCityNum = getCityNum(nextCity);
			log << "badCity = " << badCity << ", new nextCity = " << nextCity << endl;
			log << "new nextCityNum = " << nextCityNum << endl;
			if (!noPath[nextCityNum])
			{
				log << "noPath = " << noPath[nextCityNum] << endl;
			}
		}
		log << "end while loop" << endl;
		log << "begin while loop... will loop until nextCity is a city that has not already been visited" << endl;
		while (visited[nextCityNum])
		{
			log << "visited = " << visited[nextCityNum] << endl;
			string visitedCity = nextCity;
			nextCity = getNextCity(topCityNum, visitedCity);
			nextCityNum = getCityNum(nextCity);
			log << "visitedCity = " << visitedCity << ", new nextCity = " << nextCity << endl;
			log << "new nextCityNum = " << nextCityNum << endl;
			if (!visited[nextCityNum])
			{
				log << "visited = " << visited[nextCityNum] << endl;
			}
		}
		log << "end while loop" << endl;
		log << "checking to see if at end of city's possible flights list" << endl;
		if (nextCity == " ")
		{
			log << "No more possible flights for top city, popping city from stack" << endl;
			noPath[topCityNum] = 1;
			log << topCity << " has no path." << endl;
			string popped;
			cityStack.pop(popped);
		} else {
			log << "Top city has more possible flights, pushing nextCity onto stack and marking as visited" << endl;
			cityStack.push(nextCity);
			topCityNum = getCityNum(nextCity);
			markVisited(nextCity);
		}
		log << "checking if stack is empty" << endl;
		if (!cityStack.empty())
		{
			topCity = cityStack.peek();
			topCityNum = getCityNum(topCity);
			log << "topCity and topCityNum have new values: " << topCity << ", " << topCityNum << endl;
		}
	}
	log << "end while loop" << endl;
	if (cityStack.empty())
	{
		log << "Stack is empty, no possible flights, returning false" << endl;
	}
	else
	{
		log << "Destination city was found, final path: " << endl << cityStack << endl;
	}

	log.close();
	
	return !cityStack.empty();

}

/**
  * @brief Outputs class Map2
  *
  * @details Outputs flight map into "HPair.out2.txt"
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Decides if cities exist, and outputs which ones do and which ones 
  *		 don't if either of them does not exist. Then calls isPath which will
  *		 return false if there is no path. If isPath returns false, output
  *		 says so, otherwise stores reverse of stack into both outStack1 and
  *		 outStack2. outStack1 gets called to other functions and gets changed
  *		 while outStack2 remains the same.
  *
  * @par Algorithm
  *		 Calls getFlights function to get all of the flight numbers and stores
  *		 them in to a vector. Calls getTotalPrice to get the total of the price
  *		 for each flight taken.
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void Map2::outputPath()
{

	ofstream fout, logOut;

	fout.open("HPAir.out2.txt");

	for (int i = 0; i < numOfRequests; i++)
	{
		fout << "--------------------------------------------------------------------------------" << endl << endl;
		fout << "Request is to fly from " << reqSource[i] << " to " << reqDestination[i] << "." << endl << endl;
		bool sourceExists = false, destinationExists = false;
		for (int j = 0; j < numOfCities; j++)
		{
			if (reqSource[i].compare(cities[j]) == 0)
			{
				sourceExists = true;
			}
			if (reqDestination[i].compare(cities[j]) == 0)
			{
				destinationExists = true;
			} 
		}
		if (!sourceExists || !destinationExists)
		{
			if (!sourceExists && !destinationExists)
			{
				fout << "Sorry. HPAir does not serve both " << reqSource[i] << " and " << reqDestination[i] << "." << endl << endl;
			}
			else if (!sourceExists)
			{
				fout << "Sorry. HPAir does not serve " << reqSource[i] << "." << endl << endl;
			}
			else if (!destinationExists)
			{
				fout << "Sorry. HPAir does not serve " << reqDestination[i] << "." << endl << endl;
			}
		}
		else
		{
			bool pathExists = isPath(reqSource[i], reqDestination[i]);

			if (!pathExists)
			{
				fout << "Sorry. HPAir does not fly from " << reqSource[i] << " to " << reqDestination[i] << "." << endl << endl;
			} 
			else
			{
				fout << "HPAir flies from " << reqSource[i] << " to " << reqDestination[i] << " by taking the following path:" << endl;
				//fout << cityStack << endl << endl; //debugging
				Stack outStack1, outStack2;
				while (!cityStack.empty())
				{
					string popped;
					cityStack.pop(popped);
					outStack1.push(popped);
					outStack2.push(popped);
				}
				//cout << outStack << endl; // debugging
				getFlights(outStack1);
				string tempCity;
				for (int j = 0; j < cityStack.getLength() - 1; j++)
				{
					//cout << j << endl; //debugging
					string city1, city2;
					if (j == 0)
					{
						outStack2.pop(tempCity);
					}
					city1 = tempCity;
					outStack2.pop(city2);
					tempCity = city2;
					fout << city1 << " -> " << city2;
					fout << " (flight#: " << flightsUsed[j] << ") " << endl;
				}
				fout << endl;
				fout << "Complete Path: " << cityStack << endl;
				fout << "Total Cost: $" << getTotalPrice() << ".00" << endl << endl;
				flightsUsed.clear();
				outStack2.clear();
				//if (flightsUsed.empty()) cout << "yes" << endl; //debugging
			}
		}
		if (i == numOfRequests - 1)
		{
			fout << "--------------------------------------------------------------------------------" << endl;
		}
	}
	fout.close();
}

/**
  * @brief Gets the next city in the adjacency list
  *
  * @details using cityNum as a starting index, gets the next city connected to fromCity
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Begins at index cityNum in the adjacency list, and then searches 
  *		 through that city's connected flights until one of them matches 
  * 	 fromCity. Then it returns the next city connected to the one matching
  *		 fromCity. If nothing matches or if there is no other city connected to
  * 	 fromCity then returns whitespace " "
  *
  * @param cityNum
  *		   Used as index to get certain city's adjacency list
  *
  * @param fromCity
  *		   Function returns this city's next city in the adjacency list
  *
  * @exception None
  *
  * @note: None
  */
string Map2::getNextCity(int cityNum, string fromCity)
{

	for (int i = 0; i < flightSize[cityNum] - 1; i++)
	{
		if (fromCity.compare(flights[cityNum][i]) == 0)
		{
			//cout << flights[cityNum][i + 1] << endl; //debugging
			return flights[cityNum][i + 1];
		}
	}

	return " ";

}

/**
  * @brief Marks visted[index of visited city] as visited
  *
  * @details Compares visitedCity with all other cities until matching one is
  * 		 found, gets that city's index number and uses the same index to
  *			 set the visited boolean to true.
  *
  * @pre visited[i]
  *
  * @post visited[i]
  *		  marks value as true
  *
  * @par Algorithm
  *		 Compares visitedCity with all other cities until matching one is 
  *		 found. i gets the index of that city. i is then used as the index for
  *		 visited. Sets visited[i] to true
  *
  * @param visitedCity
  * 	   used to find index of boolean visited
  *
  * @exception None
  *
  * @note: None
  */
void Map2::markVisited(string visitedCity)
{

	int cityNum;
	for (int i = 0; i < numOfCities; i++)
	{
		if (visitedCity.compare(cities[i]) == 0)
		{
			cityNum = i;
		}
	}

	visited[cityNum] = true;

}

/**
  * @brief sets all visited and noPath to false
  *
  * @details goes through array of booleans visited and noPath and sets all to
  *			 false
  *
  * @pre visited, noPath
  *		 some values might be true
  *
  * @post visited, noPath
  *		  all values now have false
  *
  * @par Algorithm
  *		 loops through all value of visited and noPath in arrays of booleans
  *		 and sets all to false
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
void Map2::unvisitAll()
{

	for(int i = 0; i < numOfCities; i++)
	{
		visited[i] = false;
		noPath[i] = false;
	}

}

#endif

