/*
 * insertionsort.h
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#ifndef __CC_SELECTION_SORT__
#define __CC_SELECTION_SORT__

namespace cc
{
    void testSelectionSort();
    void selectionsort(int *arrayToSort, int length);
    void selectionsort2(int *input, int length);
    int findsecondlargestelement(int *arrayToSort, int length);
}

#endif /* __CC_SELECTION_SORT__ */
