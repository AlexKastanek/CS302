// Main Driver for kthSmall ///////////////////////////////////////////////////
/**
  * @file main.cpp
  *
  * @brief File containing source code for kthSmall function
  *
  * @author Alex Kastanek
  *
  * @details Contains kSmall function, swap function, and logToFile function
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of kSmall
  *
  * @note File's pseudocode created by Shehryar Khattak for CS302 Spring 2016 
  *		  class.
  *
  * @note Program must be run with a command line argument to determine 
  *		  filename
  *
  */

//Â  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <cstddef>
#include <fstream>

using namespace std;

int kSmall(int k, int first, int last, int* data);

void swap(int a, int b, int* data);

void logToFile(int k, int pivot, int pivotPos, int firstPos, int lastPos, int* data);

int main(int argc, char *argv[])
{

	//getting filename from command line argument
	ifstream fin;
	if (argc != 2) //checking for correct number of command line arguments
	{
		cout << "Please enter filename as command line argument" << endl;
		return 0;
	} else
	{
		fin.open(argv[1]);
		if (!fin.is_open()) //checking if file opens correctly
		{
			cout << "Could not open file" << endl;
			return 0;
		}
	}

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val=0;		//Populate using your algorithm implementation
	int pivot;		        //Pivot position in array

	//User Input DO NOT MODIFY
	cout<<"Please enter required kth smallest value:";
	cin>>kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.

	int* anArray = new int[500];

	//getting input from file and storing in anArray
	for (int i = 0; i < 500; i++) 
	{
		fin >> anArray[i];
	}

	fin.close();

	//debugging
	/*for (int i = 0; i < 1000; i++)
	{
		cout << anArray[i] << " ";
	}
	cout << endl;*/

	//getting arrayLength to determine position of last value
	int i = 0;
	int arrayLength = 0;
	while (anArray[i] != 0)
	{
		arrayLength++;
		i++;
	}

	//debugging
	//cout << "pivot value: " << anArray[0] << endl;
	//debugging
	//cout << "length: " << arrayLength << endl;

	//first position always starts at 0, and loast position gets arrayLength-1
	int firstPos = 0;
	int lastPos = arrayLength - 1;

	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated

	kSmall_val = kSmall(kSmall_pos, firstPos, lastPos, anArray);

	//debugging
	/*i = 0;
	arrayLength = 0;
	while (anArray[i] != 0)
	{
		arrayLength++;
		i++;
	}
	cout << "new length: " << arrayLength << endl;*/

	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page

	//for log file output, see logToFile function

	//Output DO NOT MODIFY
	cout<<"kth smallest value = "<<kSmall_val<<endl;

	anArray = NULL;
	delete anArray;

	return 0;
}

/**
  * @brief Function finds the kth smallest value in a set of numbers
  *
  * @details Function finds the kth smallest value in a set of numbers by
  *			 recursively dividing the set into 2 using a pivot and only
  *			 evaluating one half of the set depending on what the relationship
  *			 between k and pivot is
  *
  * @pre int pivot is intialized to the first value in the set
  *
  * @pre int pivotIndex is intialized to address of pivot
  * 
  * @pre int lowCount is initialized to address of value after first value in 
  *		 the set
  *
  * @pre int highCount is initialized to address of last value in the set
  *
  * @post pivot and its index change depending on what values in the set are
  * 	  less than it or greater than it
  * 
  * @post lowCount is incremented and highCount is decremented until their
  *		  positions are the same
  * 
  * @par Algorithm
  *		 compares the values at lowCount and pivot, swaps and decrements
  *		 highCount if lowCount is greater than or equal to pivot, increments
  *		 lowCount if not OR swaps and increments lowCount if highCount is less
  *		 than pivot, decremets highCount if not
  *
  * @par Algorithm
  *		 swap pivot's position with the next value until all values to the left
  *		 of pivot are less than it and all value to the right of pivot are
  *		 greater than it
  *
  * @par Algorithm
  *		 compares k to pivotIndex - first + 1 and returns pivot if they are
  *		 equal, returns a call to the function with the same parameters if k
  *		 is k is less than the expression, or returns a call to the function
  *		 with k being subtracted by the expression if k is greater than the
  *		 expression
  *
  * @param[in] k
  *            holds the magnitude of the value function looks for, function
  *			   could search for 4th smallest value or 8th smallest depending
  *			   user input
  *
  * @param[in] first
  *			   holds position of first value in the array
  *
  * @param[in] last
  *			   holds position of last value in the array
  *
  * @param[in] data
  *			   array of integers that holds the set of values the function 
  *			   searches through
  *
  * @param[out] pivot
  *				pivot is the only output of this function as it will contain
  *				the kth smallest value
  *
  *	@exception None
  *
  * @return pivot
  *
  * @note: None
  */

int kSmall(int k, int first, int last, int* data) 
{

	int pivotIndex = first; //position of pivot, always starts as value of first
	int pivot = data[pivotIndex];
	int lowCount = first + 1; //will increment through the array starting at position after first
	int highCount = last; //will decrement through the array starting at the last position

	//if k is equal to the length the array, returns the max value in the array
	if (k == last + 1) 
	{
		int maxVal = data[first];
		for (int i = 0; i < last; i++)
		{
			if (data[i] > maxVal)
			{
				maxVal = data[i];
			}
		}
		ofstream fout;
		fout.open("log.txt", ios_base::app);
		fout << "Partition around pivot (" << pivot << " in position " << pivotIndex << "): ";
	for (int i = first; i < last; i++)
	{
		fout << data[i] << " ";
	}
	fout << endl;
		fout << maxVal << " is the largest value in this data." << endl;
		fout << "--------------------------------------------------------------------------------" << endl;
		return maxVal; 
	}

	//algorithm that partitions the data around pivot
	while (lowCount < highCount)
	{
		if (data[lowCount] < pivot) 
		{
			lowCount++;
		} else if (data[highCount] >= pivot)
		{
			highCount--;
		} else if (data[highCount] < pivot)
		{
			swap(lowCount, highCount, data);
			lowCount++;
		} else
		{
			swap(lowCount, highCount, data);
			highCount--;
		}
	}
	
	//algorithm that moves pivot to be surrounded by partitioned values
	while (pivot > data[pivotIndex + 1]) 
		{
			swap(pivotIndex, pivotIndex + 1, data);
			pivotIndex++;
		}

	logToFile(k, pivot, pivotIndex, first, last, data);

	//algorithm that cuts off part of the array depending on k
	if (k < pivotIndex - first + 1)
	{
		return kSmall(k, first, pivotIndex - 1, data);
	} else if (k == pivotIndex - first + 1)
	{
		return pivot;
	} else
	{
		k = k - (pivotIndex - first + 1);
		return kSmall(k, pivotIndex + 1, last, data);
	}

}

/**
  * @brief Function swaps two values
  *
  * @details Function swaps two values by storing one in a temp location
  *
  * @pre int temp is intialized to b
  *
  * @post temp gets stored in a
  * 
  * @par None
  *
  * @param[in] a
  *           gets b, which was stored in temp
  *
  * @param[in] b
  *			   gets a
  *
  * @param[in] data
  *			   contains a and b
  *
  * @param[out] data
  *				a and b get swapped in this array
  *
  *	@exception None
  *
  * @return None
  *
  * @note: None
  */

void swap(int a, int b, int* data)
{

	int temp = data[b];
	data[b] = data[a];
	data[a] = temp;

}

/**
  * @brief Function logs the recursive steps of kSmall
  *
  * @details Function logs the partitions in kSmall as well as changes to k and
  *			 pivot
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param[in] k
  *            k in kSmall
  *
  * @param[in] pivot
  *			   pivot in kSmall
  *
  * @param[in] pivotPos
  *			   holds position of pivot
  *
  * @param[in] firstPos
  *			   holds position of first value in section of array
  *
  *	@param[in] lastPos
  *			   holds position of last value in section of array
  *
  *	@param[in] data
  *			   array that holds all integers in the set
  *
  * @param[out] None
  *
  *	@exception None
  *
  * @return None
  *
  * @note: None
  */

void logToFile(int k, int pivot, int pivotPos, int firstPos, int lastPos, int* data)
{

	ofstream fout;
	fout.open("log.txt", ios_base::app);
	fout << "Partition around pivot (" << pivot << " in position " << pivotPos << "): ";
	for (int i = firstPos; i < lastPos; i++)
	{
		fout << data[i] << " ";
	}
	fout << endl;
	fout << "k = " << k << endl;
	fout << "pivotIndex - first + 1 = " << pivotPos << " - " << firstPos << " + 1 = " << (pivotPos - firstPos + 1) << endl;
	if (k - (pivotPos - firstPos + 1) == 0)
	{
		fout << pivot << " is the kth smallest value in this data." << endl;
		fout << "--------------------------------------------------------------------------------" << endl;
	}

}









