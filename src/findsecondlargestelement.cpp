/*
 * findsecondlargestelement.cpp
 *
 *  Created on: 2013-01-25
 *      Author: carl
 */
#include "puzzles.h"
#include "ccutilities.h"
#include <iostream>
#include <time.h>

long maxSize = 1000000000;

void test1()
{
	time_t now = time(0);
	std::cout << "Find second largest element (1-pass) b=" << now << std::endl;
	// Since we are only looking for the second largest element we can just
	// go through the list once 0(n) just keep track of the largest and second largest
	long largest = 0;
	long secondLargest = 0;
	// First pass - find largest
	for (long i = 0; i < maxSize; ++i)
	{
		if (i > largest)
		{
			secondLargest = largest;
			largest = i;
		}
		else if (i > secondLargest)
		{
			secondLargest = i;
		}
	}
	now = time(0);
	std::cout << "Find second largest element (1-pass) a=" << now << std::endl;
	std::cout << "Largest = " << largest << ", second largest = " << secondLargest << std::endl;
}

void test2()
{
	time_t now = time(0);
	std::cout << "Find second largest element (2-pass) b=" << now << std::endl;
	// This test uses a simple two pass method
	long largest = 0;
	long secondLargest = 0;
	// First pass - find largest
	for (long i = 0; i < maxSize; ++i)
	{
		if (i > largest) largest = i;
	}
	// Second pass, find second largest
	for (long i = 0; i < maxSize; ++i)
	{
		if (i > secondLargest && i < largest) secondLargest = i;
	}
	now = time(0);
	std::cout << "Find second largest element (2-pass) a=" << now << std::endl;
	std::cout << "Largest = " << largest << ", second largest = " << secondLargest << std::endl;
}

namespace puzzles {

void findSecondLargestElement()
{
	test2();
	test1();
}

} // end namespace cc




