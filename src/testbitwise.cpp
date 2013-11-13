/*
 * testbitwise.cpp
 *
 *  Created on: 2013-01-23
 *      Author: carl
 */
#include "testbitwise.h"
#include <iostream>
#include <cmath>

namespace cc {

void testbitwise()
{
	std::cout << "The number of bits in -1 is " << countbits(-1) << std::endl;
	std::cout << "The number of bits in 0 is " << countbits(0) << std::endl;
    std::cout << "The number of bits in 10 is " << countbits(10) << std::endl;

    std::cout << "Print truth table with input 4" << std::endl;
    printTruthTable(4);
}

int countbits(int number)
{
	int totalBitsSet = 0;
    int totalBits = sizeof(number) * 8;
    for (int i = 0; i < totalBits; i++)
    {
    	if (number & 0x01) totalBitsSet++;
    	number = number >> 1;
    }
    return totalBitsSet;
}

void printTrueFalse(int number, int numBits)
{
    for (int i = 0; i < numBits; i++)
    {
    	std::cout << ((number & 0x01) ? "T " : "F ");
    	number = number >> 1;
    }
    std::cout << std::endl;
}

void printTruthTable(int number)
{
   // Print out a truth table of all possible permutations
   int total = std::pow((float)number, 2);
   for (int i = 0; i < total; i++)
   {
       printTrueFalse(i, number);
   }
}

} // end namespace cc
