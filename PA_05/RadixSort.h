// Class Header File Information //////////////////////////////////////////////
/**
  * @file radixSort.h
  *
  * @brief Definition file for radixSort class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the radixSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of radixSort class
  *
  * @note None
  *
  */

#include <iostream>

using namespace std;

class RadixSort
{

	public:
			RadixSort();
			~RadixSort();

			void sort(int* data, int size, int digits);

			int getComparisonNum();
			int getSwapNum();

	private:
			int numberOfComparisons;
			int numberOfSwaps;

};
