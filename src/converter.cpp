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

} /* namespace string */
