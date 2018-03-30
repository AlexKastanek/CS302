// Class Header File Information //////////////////////////////////////////////
/**
  * @file mergeSort.h
  *
  * @brief Definition file for MergeSort class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the MergeSort class
  *
  * @version 1.00
  *  		 C.S. Student (1 November 2016)
  *			 Initial development and testing of MergeSort class
  *
  * @note None
  *
  */

#include <iostream>

using namespace std;

class MergeSort
{

	public:
			MergeSort();
			~MergeSort();

			void sort(int* data, int first, int last);
			void merge(int* data, int first, int mid, int last);
			void swap(int* data, int &a, int &b);

			int getComparisonNum();
			int getSwapNum();
			void reset();

	private:
			int numberOfComparisons;
			int numberOfSwaps;

};
