/*
 * quicksort.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#include <iostream>
#include "quicksort.h"
#include "ccutilities.h"

namespace cc
{

/* Quicksort
 * 1. Pick a pivot value
 * 2. Work from both left and right and swap values to the correct side
 *    by comparing to pivot
 * 3. Repeat steps 1 and 2 with left and right halves of array
 * BEST - O(nlogn)
 * WORST - O(n-sqared)
 * AVERAGE - O(nlogn)
 * SPACE - O(nlogn) stack space
 */
void testQuickSort()
{
	int arr[] =  { 4, 0, 6, 6, 2, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 11 };
	int length = sizeof(arr)/sizeof(int);
	cc::printArray("int array BEFORE quick sort", arr, 0, length - 1);
	cc::quicksort(arr, 0, length - 1);
	cc::printArray("int array AFTER quick sort", arr, 0, length - 1);
}

int partition(int *arrayToSort, int low, int high)
{
   // This algorithm works from both ends and is very tricky - any change
   // will most likely break the sorting.  So in the future when you
   // decide to pick a better pivot the best way to do that would be to
   // 1. Figure out the best pivot value whatever way you want
   // 2. Move that value to the current "low" position so this block still works
   int pivotIndex = low;
   int pivot = arrayToSort[pivotIndex];
   int i = low;
   int j = high + 1;
   while (true)
   {
       // find item on low side to swap
       while (arrayToSort[++i] < pivot)
           if (i == high) break;

       // find item on high side to swap
       while (pivot < arrayToSort[--j])
           if (j == low) break;

       // check if pointers cross
       if (i >= j) break;

       std::swap(arrayToSort[i], arrayToSort[j]);
   }

   // Move the pivot value to the correct position
   std::swap(arrayToSort[pivotIndex], arrayToSort[j]);
   return j;
}

int partition2(int *arrayToSort, int low, int high)
{
	int pivotValue = arrayToSort[high];

    int storeIndex = low;
    for (int i = low; i < high - 1; i++)
    {
        if (arrayToSort[i] < pivotValue)
        {
        	std::swap(arrayToSort[i], arrayToSort[storeIndex++]);
        }
    }
    std::swap(arrayToSort[storeIndex], arrayToSort[high]);
    return storeIndex;
}

void quicksort(int *arrayToSort, int low, int high)
{
   if (low < high)
   {
      // Pick a pivot
      int p = partition(arrayToSort, low, high);
      quicksort(arrayToSort, low, p - 1);
      quicksort(arrayToSort, p + 1, high);
   }
}

} // end namesapce cc





