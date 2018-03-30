#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FlightMap.v1.h"
#include "FlightMap.v2.h"
//#include "stack.h"

using namespace std;

int main() 
{

	Map1 firstMap;
	Map2 secondMap;
	char* cityFile = new char[20];
	char* flightFile = new char[20];
	char* requestFile = new char[20];
	bool goodInput = false;

	cout << "Please enter the name of the city file: ";
	while(!goodInput)
	{
		cin >> cityFile;
		ifstream fin;
		fin.open(cityFile);
		if (fin.is_open())
		{
			goodInput = true;
		} else
		{
			fin.close();
			cout << "Error: File does not exist, please enter a correct filename: ";
		}
	}
	goodInput = false;
	cout << "Please enter the name of the flight file: ";
	while(!goodInput)
	{
		cin >> flightFile;
		ifstream fin;
		fin.open(flightFile);
		if (fin.is_open())
		{
			goodInput = true;
		} else
		{
			fin.close();
			cout << "Error: File does not exist, please enter a correct filename: ";
		}
	}
	goodInput = false;
	cout << "Please enter the name of the request file: ";
	while(!goodInput)
	{
		cin >> requestFile;
		ifstream fin;
		fin.open(requestFile);
		if (fin.is_open())
		{
			goodInput = true;
		} else
		{
			fin.close();
			cout << "Error: File does not exist, please enter a correct filename: ";
		}
	}
	goodInput = false;

	firstMap.getInput(cityFile, flightFile, requestFile);

	firstMap.getAdjacencyVector();

	firstMap.outputPath();

	secondMap.getInput(cityFile, flightFile, requestFile);

	secondMap.getAdjacencyVector();

	secondMap.outputPath();

	return 0;
}
















