// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file radixSort.cpp
  *
  * @brief Implementation file for RadixSort class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the RadixSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of RadixSort class
  *
  * @note Requires radixSort.h
  *
  * @note None
  *
  */

#include "radixSort.h"
#include <vector>


/**
  * @brief Constructor for class RadixSort
  *
  * @details Able to construct a RadixSort object
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
RadixSort::RadixSort()
{

	numberOfComparisons = 0;
	numberOfSwaps = 0;

}

/**
  * @brief Destructor for class RadixSort
  *
  * @details Able to destruct a RadixSort object
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
RadixSort::~RadixSort()
{



}

/**
  * @brief Sorts data from least to greatest
  *
  * @details Sorts data by grouping it together by the data's speicific digits
  *
  * @pre numberOfComparisons
  *		 begins at 1
  *
  * @pre numberOfSwaps
  *		 begins at 1
  *
  * @post numberOfComparisons
  * 	  gets incremented every time function compares values
  *
  * @post numberOfComparisons
  *		  gets incremented every time function performs an action that moves 
  *		  the data around
  *
  * @par Algorithm
  *		 Radix sort is a complex algorithm that groups the data together first
  *		 by the least significant digit and keeps going all the way until it
  *		 reaches the most significant digit. When it groups them together, it
  *		 puts them in groups of 0s - 9s, all depending on what the digit is in
  *		 that specific place. It then replaces them back into the array and
  *		 moves on to the next least significant bit. By the time it is done
  *		 with the most significant bit, all of the items are sorted.
  *
  * @param data
  *		   This is the data the function will sort
  *
  * @param size
  *		   The size of data
  *
  * @param digits
  *		   The max amount of digits there can be in a single item
  *
  * @exception None
  *
  * @note: None
  */
void RadixSort::sort(int* data, int size, int digits)
{

	numberOfSwaps = 1;
	numberOfComparisons = 1;

	for (int i = digits; i >= 1; i--)
	{
		//cout << "i: " << i << endl;
		vector<vector<int> > groups;
		int groupCount[10];
		for (int j = 0; j < 10; j++)
		{
			groups.push_back(vector<int>());
			groupCount[j] = 0;
		}

		int multiplier = 10;
		for (int j = i; j < digits; j++)
		{
			//cout << "good" << endl;
			multiplier = multiplier * 10;
		}
		for (int j = 0; j < size; j++)
		{	
			int divider = (data[j] / multiplier) * multiplier;
			//if (i == 2) cout << data[j] << " / " << multiplier << " * " << multiplier << " = " << divider << endl;
			int k = 0;
			if (divider == 0)
			{
				k = data[j] / (multiplier / 10);
			}
			else
			{
				k = (data[j] % divider) / (multiplier / 10);
			}
			//if (i == 2) cout << data[j] << " % " << divider << " = " << k << endl;
			groups[k].push_back(data[j]);
			//if (i == 1) cout << groups[k][groupCount[k]] << endl;
			groupCount[k]++;
			numberOfSwaps++;
		}

		int dataIndex = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < groupCount[j]; k++)
			{
				data[dataIndex] = groups[j][k];
				dataIndex++;
			}
		}
		numberOfComparisons++;
		groups.clear();
	}

}

int RadixSort::getComparisonNum()
{
	return numberOfComparisons;
}

int RadixSort::getSwapNum()
{
	return numberOfSwaps;
}









