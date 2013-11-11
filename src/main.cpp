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

    std::cout << "Result of ltoa with 235 is " << string::converter::ltoa(235) << std::endl;
    std::cout << "Result of ltoa with 0 is " << string::converter::ltoa(0) << std::endl;
    std::cout << "Result of ltoa with 1 is " << string::converter::ltoa(1) << std::endl;
    std::cout << "Result of ltoa with -1 is " << string::converter::ltoa(-1) << std::endl;
    std::cout << "Result of ltoa with -1000 is " << string::converter::ltoa(-1000) << std::endl;
    std::cout << "Result of ltoa with -2 is " << string::converter::ltoa(-2) << std::endl;
    std::cout << "Result of ltoa with -2000000 is " << string::converter::ltoa(-2000000) << std::endl;
    std::cout << "Result of ltoa with 2,147,483,647 is " << string::converter::ltoa(2147483647) << std::endl;
    std::cout << "Result  of ltoa with −2,147,483,648 is " << string::converter::ltoa(-2147483648) << std::endl;
    return 0;
}
