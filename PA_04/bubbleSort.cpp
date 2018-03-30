// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file bubbleSort.cpp
  *
  * @brief Implementation file for BubbleSort class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the BubbleSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of BubbleSort class
  *
  * @note Requires bubbleSort.h
  *
  * @note None
  *
  */

#include "bubbleSort.h"

/**
  * @brief Constructor for class BubbleSort
  *
  * @details Able to construct a BubbleSort object
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
BubbleSort::BubbleSort()
{

	sorted = false;
	numberOfComparisons = 0;
	numberOfSwaps = 0;

}

/**
  * @brief Destructor for class BubbleSort
  *
  * @details Able to destruct a BubbleSort object
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
BubbleSort::~BubbleSort()
{



}

/**
  * @brief Sorts data from least to greatest
  *
  * @details Sorts data by comparing adjacent values over and over again and
  * 		 swapping them when out of order
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
  *		 Bubble Sort goes through a list of items over and over and compares 
  *		 the adjacent items. If the items are out of order, it swaps the two.
  *
  * @param data
  *		   This is the data the function will sort
  *
  * @param size
  *		   The size of data
  *
  * @exception None
  *
  * @note: None
  */
void BubbleSort::sort(int* data, int size)
{

	sorted = false;
	numberOfComparisons = 1;
	numberOfSwaps = 1;
	while (!sorted && (numberOfComparisons < size))
	{
		sorted = true;
		for(int i = 0; i < size - numberOfComparisons; i++)
		{
			if (data[i] > data[i + 1])
			{
				swap(data, data[i], data[i + 1]);
				sorted = false;
				numberOfSwaps++;
			}
		}
		numberOfComparisons++;
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
void BubbleSort::swap(int* data, int &a, int &b)
{

	int temp = a;
	a = b;
	b = temp;

}

int BubbleSort::getComparisonNum()
{
	return numberOfComparisons;
}

int BubbleSort::getSwapNum()
{
	return numberOfSwaps;
}










