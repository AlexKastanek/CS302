// Class Header File Information //////////////////////////////////////////////
/**
  * @file bubbleSort.h
  *
  * @brief Definition file for BubbleSort class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the BubbleSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of BubbleSort class
  *
  * @note None
  *
  */

#include <iostream>

using namespace std;

class BubbleSort
{

	public:
			BubbleSort();
			~BubbleSort();

			void sort(int* data, int size);
			void swap(int* data, int &a, int &b);

			int getComparisonNum();
			int getSwapNum();

	private:
			bool sorted;
			int numberOfComparisons;
			int numberOfSwaps;

};
