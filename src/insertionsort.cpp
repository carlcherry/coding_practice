/*
 * insertionsort.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */
#include "insertionsort.h"

#include <iostream>
#include <deque>
#include <algorithm>
#include "ccutilities.h"

namespace cc
{
// Insertion sort algorith
/*
 * Insertion sort iterates, consuming one input element each repetition,
 * and growing a sorted output list. On a repetition, insertion sort removes
 * one element from the input data, finds the location it belongs within the sorted list,
 * and inserts it there. It repeats until no input elements remain.
 * BEST base O(n) - when list is sorted
 * WORST base O(n-squared) when list is in reverse order
 * AVERAGE case is also O(n-squared)
 * usually sorted in place
 * very efficient for very small arrays (approx. 10 or less)
 */

void test_insertion_sort()
{
    int arr[] =  { 4, 0, 6, 6, 11, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 2 };
    int length = sizeof(arr)/sizeof(int);
    cc::printArray("int array BEFORE insertion sort", arr, 0, length - 1);
    cc::insertionsort(arr, length);
    cc::printArray("int array AFTER insertion sort", arr, 0, length - 1);
}

void insertionsort(int *arrayToSort, int length)
{
    // We can just start at element 1 since we need at least 2 elements to being sorting
    for(int i = 1; i < length; i++)
    {
        // Grab the value at element 'i'
        int valueToInsert = arrayToSort[i];
        int indexToInsert = i;
        // Now move any elements that are greater than valueToInsert to the right
        // until we find the correct place to insert valueToInsert
        while(indexToInsert > 0 && valueToInsert < arrayToSort[indexToInsert - 1])
        {
            arrayToSort[indexToInsert] = arrayToSort[indexToInsert - 1];
            indexToInsert--;
        }
        // OK - we have stopped the loop so we now know where to put valueToInsert
        arrayToSort[indexToInsert] = valueToInsert;
    }
}

} // end namespace cc



