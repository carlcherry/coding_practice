/*
 * testsearch.h
 *
 *  Created on: 2013-01-06
 *      Author: carl
 */

#ifndef __CC_TESTSEARCH_H_
#define __CC_TESTSEARCH_H_

namespace cc
{
    void testBinarySearch();
    bool binarysearch(int *arrayOfInts, int length, int intToFind);
    int binarysearchrecursive(int *arrayOfInts, int left, int right, int intToFind);

} // end of namespace cc
#endif /* __CC_TESTSEARCH_H_ */
