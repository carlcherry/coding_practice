/*
 * main.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: carl
 */

#include <iostream>
#include "converter.h"
#include "ccutilities.h"
#include "puzzles.h"

int main(int argc, char **argv)
{
    const std::clock_t begin_time = std::clock();

    string::converter::test();
    cc::test_base64();

    //puzzles::findKthElementTest(false);

    std::cout << "Total time for all tests: " << float( std::clock () - begin_time ) /  CLOCKS_PER_SEC << std::endl;
    return 0;
}
