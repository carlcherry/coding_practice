/*
 * mergesort.cpp
 *  Created on: 2013-01-22
 *      Author: carl
 */
#include "mergesort.h"
#include "ccutilities.h"
#include <deque>

namespace cc
{
void testMergeSort()
{
    int arr[] =  { 4, 0, 6, 6, 2, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 11 };
    int length = sizeof(arr)/sizeof(int);
    cc::printArray("int array BEFORE merge sort", arr, 0, length - 1);
    cc::merge_sort(arr, 0, length - 1);
    cc::printArray("int array AFTER merge sort", arr, 0, length - 1);
}
/* Merge
 * 1. Create 2 queues, one for each half of the array
 * 2. Add items back to array in sorted order until one of the queues is empty
 * 3. Anything left over in the non-empty queue is added to t
 */
void merge(int *arrayToSort, int low, int middle, int high)
{
    // Algorithm

    int i;
    std::deque<int> _qLeft;
    std::deque<int> _qRight;

    // Copy the left and right halves into 2 queues
    for (i = low; i <= middle; i++)
        _qLeft.push_back(arrayToSort[i]);
    for (i = middle + 1; i <= high; i++)
        _qRight.push_back(arrayToSort[i]);

    // Now merge these two queues together UNTIL one of them is empty
    i = low;
    while (!(_qLeft.empty() || _qRight.empty())) {
        if (_qLeft.front() <= _qRight.front()) {
            arrayToSort[i++] = _qLeft.front();
            _qLeft.pop_front();
        }
        else {
            arrayToSort[i++] = _qRight.front();
            _qRight.pop_front();
        }
    }

    // Either of qLeft or qRight still might have items left - we need to add them to the list as well
    while (!_qLeft.empty()) {
        arrayToSort[i++] = _qLeft.front();
        _qLeft.pop_front();
    }
    while (!_qRight.empty()) {
        arrayToSort[i++] = _qRight.front();
        _qRight.pop_front();
    }
}

/* Merge sort
 * Through recursion break down array into smaller arrays until the array size is 2
 * (i.e. low < high, % at least 2 elements)
 * Then call merge to merge the 2 halves of the array in sorted order
 * BEST - O(nlogn)
 * WORST - O(nlogn)
 * AVERAGE - O(nlogn)
 * SPACE - depends, worst case is O(n)
 */
void merge_sort(int *arrayToSort, int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high)/2;
        merge_sort(arrayToSort, low, middle);
        merge_sort(arrayToSort, middle + 1, high);
        merge(arrayToSort, low, middle, high);
    }
}

} // end namespace cc



