/*
 * converter.h
 *
 *  Created on: Nov 9, 2013
 *      Author: carl
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>

namespace string {

class converter {
public:
    converter();
    virtual ~converter();

    static long atol(const char* input);

    static std::string ltoa(int32_t input);
};

} /* namespace string */
#endif /* CONVERTER_H_ */
