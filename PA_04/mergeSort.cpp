// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file mergeSort.cpp
  *
  * @brief Implementation file for MergeSort class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the MergeSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of MergeSort class
  *
  * @note Requires mergeSort.h
  *
  * @note None
  *
  */

#include "mergeSort.h"


/**
  * @brief Constructor for class MergeSort
  *
  * @details Able to construct a MergeSort object
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
MergeSort::MergeSort()
{

	numberOfComparisons = 0;
	numberOfSwaps = 0;

}


/**
  * @brief Destructor for class MergeSort
  *
  * @details Able to destruct a MergeSort object
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
MergeSort::~MergeSort()
{



}

/**
  * @brief Sorts data from least to greatest
  *
  * @details Sorts data by dividing the data over and over again until it is
  *			 completely separated, and then merges the data in the correct order
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
  *		 Merge Sort is a recursive function that divides the data into two and
  *		 then recursively calls itself with the divided data. It then merges
  *		 the data back together in the correct order using the merge algorithm.
  *
  * @param data
  *		   This is the data the function will sort
  *
  * @param first
  *		   This is the index of the first value of the data (begins at 0)
  *
  * @param last
  *		   This is the index of the last value of the data (begins at the size
  *		   - 1)
  *
  * @exception None
  *
  * @note: None
  */
void MergeSort::sort(int* data, int first, int last)
{

	if (first < last)
	{
		numberOfSwaps++;
		int mid = first + (last - first) / 2;
		sort(data, first, mid);
		sort(data, mid + 1, last);
		merge(data, first, mid, last);
	}

	numberOfComparisons++;

}

/**
  * @brief Merges data in the correct order
  *
  * @details Merges data from two separate arrays into a temp array and then 
  *			 copies the temp array into the final array
  *
  * @pre None
  *
  * @post None
  *
  * @post numberOfComparisons
  *		  gets incremented every time function performs an action that moves 
  *		  the data around
  *
  * @par Algorithm
  *		 Merge simply takes data and splits it into two and then begins to
  *		 merge it back together into a temp array. When it merges it compares
  *		 the two arrays' first values and swaps them if necessary. It then
  *		 places any remaining values in the temp array and then copies the temp
  *		 array back into data with the resorted values.
  *
  * @param data
  *		   This is the data the function will merge
  *
  * @param first
  *		   This is the index of the first value of the data
  *
  *	@param mid
  *		   This is the midpoint of the data
  *
  * @param last
  *		   This is the index of the last value of the data
  *
  * @exception None
  *
  * @note: None
  */
void MergeSort::merge(int* data, int first, int mid, int last)
{

	int tempData[last + 1];

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (data[first1] <= data[first2])
		{
			tempData[index] = data[first1];
			first1++;
		}
		else
		{
			tempData[index] = data[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		tempData[index] = data[first1];
		first1++;
		index++;
	}
	while (first2 <= last2)
	{
		tempData[index] = data[first2];
		first2++;
		index++;
	}

	for (int i = first; i <= last; i++)
	{
		data[i] = tempData[i];
	}

}

int MergeSort::getComparisonNum()
{
	return numberOfComparisons;
}

int MergeSort::getSwapNum()
{
	return numberOfSwaps;
}

void MergeSort::reset()
{
	numberOfComparisons = 0;
	numberOfSwaps = 0;
}













