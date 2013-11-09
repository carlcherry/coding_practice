/*
 * main.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: carl
 */

#include <iostream>
#include "converter.h"

int main(int argc, char **argv)
{
    std::cout << "Result of atol with -235 is " << string::converter::atol("-235") << std::endl;
    std::cout << "Result of atol with 10429 is " << string::converter::atol("10429") << std::endl;
    std::cout << "Result of atol with 0 is " << string::converter::atol("0") << std::endl;
    std::cout << "Result of atol with -1 is " << string::converter::atol("-1") << std::endl;
    std::cout << "Result of atol with 1 is " << string::converter::atol("1") << std::endl;

    return 0;
}
