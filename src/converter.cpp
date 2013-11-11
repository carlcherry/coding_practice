/*
 * converter.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: carl
 */

#include "converter.h"
#include <math.h>
#include <string.h>
#include <iostream>

namespace string {

// Tail-recursive way to convert base 10 string to a long value
long _convert_to_long(const char *input, long val)
{
    int index = strlen(input);
    if (index == 0) {
        return val;
    } else {
        char currentChar = *input;
        // Since 0 is 0x30 on the ASCII chart - subtract 0x30 from this character.
        return _convert_to_long(++input, val + (long) ((int) (currentChar - 0x30) * (pow(10, index - 1))));
    }
}

long convert_to_long(const char *pInput) {
    return _convert_to_long(pInput, 0);
}

converter::converter() {
}

converter::~converter() {
}

long converter::atol(const char* input) {
    bool negate = (input[0] == '-');
    long result = convert_to_long(negate ? ++input : input);
    return (negate ? -result : result);
}

std::string converter::ltoa(int32_t input)
{
	uint32_t tmpInput = (uint32_t)input;
    char buffer[12]; // -2147483648
    int index = 10;
    buffer[11] = 0x00; // terminate the string
    bool negate = (input < 0);
    if (negate) {
        // For negative numbers flip all the bits and add 1
        tmpInput = ~tmpInput + 1;
    }
    // Special cases
    if (input == 0)
        return std::string("0");

    while (index > 0 && tmpInput > 0)
    {
        char currentChar = (tmpInput % 10) + 0x30;
        buffer[index--] = currentChar;
        tmpInput = tmpInput / 10;
    }
    if (negate)
        buffer[index] = '-';
    else
        index++;
    return std::string(&(buffer[index]));
}

} /* namespace string */
