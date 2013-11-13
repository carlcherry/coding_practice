#include "testsearch.h"
#include "ccutilities.h"
#include <iostream>

namespace cc
{

void testBinarySearch()
{
    int arr[] =  { 1, 4, 9, 16, 25, 36, 49, 64, 81, 100 };
    int length = sizeof(arr)/sizeof(int);
    cc::printArray("int array for binary search", arr, 0, length - 1);
    std::cout << "Value 9 was " << (cc::binarysearch(arr, length, 9) ? "found" : "not found") << std::endl;
    std::cout << "Value 20 was " << (cc::binarysearch(arr, length, 20) ? "found" : "not found") << std::endl;
    std::cout << "Recursive binary index of value 16 is " << cc::binarysearchrecursive(arr, 0, length - 1, 16) << std::endl;
    std::cout << "Recursive binary index of value 17 is " << cc::binarysearchrecursive(arr, 0, length - 1, 17) << std::endl;
}

// Binary Search (assumes list is sorted)
// 1. Find the mid-point of our array
// 2. If the mid-point value is what we are searching for then we are done
// 3. Otherwise the value is either in the left half or right half of the
//    array so repeat steps 1 and 2 on the correct half of the array
// 4. Once left == right we have are now down to our last hope of
//    finding the value, if not found by now it is not here
// BEST - O(logn)
// WORST - O(logn)
// AVERAGE - O(logn)
//
bool binarysearch(int *arrayOfInts, int length, int intToFind)
{
    if (length == 0)
        return false;

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arrayOfInts[mid] == intToFind)
            return true;
        else if (arrayOfInts[mid] < intToFind)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int binarysearchrecursive(int *arrayOfInts, int left, int right, int intToFind)
{
    if (left > right)
        return -1; // couldn't find the element

    int mid = (left + right) / 2;

    if (arrayOfInts[mid] == intToFind)
        return mid; // found our value, return the index
    else if (intToFind < arrayOfInts[mid])
        return binarysearchrecursive(arrayOfInts, left, mid - 1, intToFind);
    else
        return binarysearchrecursive(arrayOfInts, mid + 1, right, intToFind);
}

} // end namespace cc

