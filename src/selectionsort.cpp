/*
 * insertionsort.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */
#include "selectionsort.h"

#include <iostream>
#include <deque>
#include <algorithm>
#include "ccutilities.h"

namespace cc
{

void testSelectionSort()
{
	int arr[] =  { 4, 0, 6, 6, 2, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 11 };
	int length = sizeof(arr)/sizeof(int);
	cc::printArray("int array BEFORE selection sort", arr, 0, length - 1);
	std::cout << "The second largest int is " << cc::findsecondlargestelement(arr, length) << std::endl;
	cc::selectionsort2(arr, length);
	cc::printArray("int array AFTER selection sort", arr, 0, length - 1);
}

/*
 * Select sort
 * 1. Start at position 0 and iterate until then end
 * 2. On each iteration of 'i' fine the lowest value remaining
 *    in the unsorted section and move it to 'i'
 * NOTE: it is a possible sort to use to find the k-th number in a series
 * BEST n-squared
 * AVERAGE n-squared
 * WORST n-sqared
 */
void selectionsort(int *arrayToSort, int length)
{
   for (int i = 0; i < length; ++i)
   {
      int j = 0;
      int low = i;
      for (j = i + 1; j < length; ++j)
      {
         if (arrayToSort[j] < arrayToSort[low])
         {
            low = j;
         }
      }
      if (low < length)
      {
         std::swap(arrayToSort[i], arrayToSort[low]);
      }
   }
}

void selectionsort2(int *input, int length)
{
    for ( int i = 0; i < length; i++)
    {
        // Assume the the value at i is the lowest value
        int lowIndex = i;

        // now compare the rest of the list to this value
        int j = i + 1;
        for ( j = i + 1; j < length; j++)
        {
           if (input[j] < input[lowIndex]) lowIndex = j;
        }

        // We are now done the innner loop - if lowIndex is a valid number then swap
        if (lowIndex < length) std::swap(input[i], input[lowIndex]);
    }
}

int findsecondlargestelement(int *arrayToSort, int length)
{
   for (int i = 0; i < 2; ++i)
   {
      int j = 0;
      int low = i;
      for (j = i + 1; j < length; ++j)
      {
         if (arrayToSort[j] > arrayToSort[low])
         {
            low = j;
         }
      }
      if (low < length)
      {
         std::swap(arrayToSort[i], arrayToSort[low]);
      }
   }
   return arrayToSort[1];
}

} // end namespace cc
