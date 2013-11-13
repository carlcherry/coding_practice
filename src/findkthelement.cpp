/*
 * findkthelement.cpp
 *
 *  Created on: 2013-01-24
 *      Author: carl
 */
#include "puzzles.h"
#include "ccutilities.h"
#include "quicksort.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace puzzles {

int partition(int *input, int left, int right)
{
    // For simplicity sake just use input[0] as the pivot.  There are better choices for pivots
    int pivot = input[0];
    int i = left;
    int j = right + 1;

    while (true)
    {
        // Move both i and j until they find a value to swap
        while (input[++i] < pivot)
            if (i == right) break;
        while (pivot < input[--j])
            if (j == left) break;

        // Here is the check we use to break out of the loop
        if (i >= j) break;

        // Swap the value
        std::swap(input[i], input[j]);
    }

    // Now put the pivot value in the correct position
    std::swap(input[0], input[j]);

    return j;
}


int kth_element(int *input, int left, int right, int k)
{
    if (left <= right)
    {
        int p = partition(input, left, right);
        if (p == k)
            return (input[k]);
        else if (k < p)
            return kth_element(input, left, p - 1, k);
        else
            return kth_element(input, p + 1, right, k);
    }
    else
    {
    	// Left has crossed right - at least log it and see if this happens
    	std::cout << "Left <= right" << std::endl;
    }
}

void findKthElementUsingArray(int* input, int length, int k)
{
   int value = 0;
   int start = k - 5;
   int end = k + 5;
   if (start < 0) start = 0;
   if (end > (length - 1)) end = length - 1;
   std::cout << "kth_element before quicksort, k=" << k << ", value=" << input[k]<< std::endl;
   cc::printArray("kth_element using quicksort - BEFORE", input, start,end);
   value = kth_element(input, 0, length - 1, k);
   cc::printArray("kth_element using quicksort - AFTER", input, start, end);
   //cc::quicksort(input, 0, length - 1);
   //cc::printArray("kth_element after fully sorted", input, 0, length - 1);
   //std::nth_element(&input[0], &input[k], &input[length-1]);
   //value = input[k];
   std::cout << "kth_element found value: " << value << " index:" << k << std::endl;
}

void findKthElementUsingSTL(std::vector<int> input, int k)
{
   int value = 0;
   int start = k - 5;
   int end = k + 5;
   if (start < 0) start = 0;
   int length = input.size();
   if (end > (length - 1)) end = length - 1;
   cc::printArray("kth_element using quicksort - BEFORE", &input[0], start,end);
   std::nth_element(input.begin(), input.begin()+k, input.end());
   cc::printArray("kth_element using quicksort - AFTER", &input[0], start, end);
   value = input[k];
   std::cout << "kth_element found value: " << value << " index:" << k << std::endl;
}

void findKthElementTest(int k)
{
   int arr[] =  { 4, 0, 6, 6, 2, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 11 };
   findKthElementUsingArray(arr, 10, k);
}

void findKthElementTest(bool useSTL)
{
    findKthElement(10, 5, useSTL);
    findKthElement(1000000, 400000, useSTL);
    findKthElement(10000000, 4000000, useSTL);
}

void findKthElement(int length, int k, bool useSTL)
{
    if (useSTL)
    {
    	std::cout << "Find the kth element using vector and std::nth_element, size: " << length << std::endl;
        std::srand((unsigned int)time(0));
        std::vector<int> input;
        input.reserve(length);
        for (int i = 0; i < length; ++i)
        {
            input.push_back(std::rand() % length);
        }
        std::cout << "Start find process now..." << std::endl;
    	findKthElementUsingSTL(input, k);
    }
    else
    {
        // Create a large array and populate with random data
    	std::cout << "Find the kth element using an array and quicksort, size: " << length << std::endl;
        std::srand((unsigned int)time(0));
        int *input = new int[length];
        for (int i = 0; i < length; ++i)
        {
            input[i] = std::rand() % length;
        }
        std::cout << "Start find process now..." << std::endl;
        findKthElementUsingArray(input, length, length / 2);
        delete [] input;
    }
}

} // end namespace cc



