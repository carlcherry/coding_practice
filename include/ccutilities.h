/*
 * ccutilities.h
 *
 *  Created on: 2013-01-05
 *      Author: carl
 */

#ifndef CCUTILITIES_H_
#define CCUTILITIES_H_

#include <string>

namespace cc
{
    void printArray(std::string message, int *inputArray, int start, int end);
    std::string base64_encode(const unsigned char* input, int length);

    void test_base64();

} // end namespace cc
#endif /* CCUTILITIES_H_ */
