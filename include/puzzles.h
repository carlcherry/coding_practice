/*
 * puzzles.h
 *
 *  Created on: 2013-01-24
 *      Author: carl
 */

#ifndef PUZZLES_H_
#define PUZZLES_H_

namespace puzzles {

bool findDuplicateNumbers(int* input1, int length1, int * input2, int lengh2);

// Test that use sorting algorithms
void findKthElementTest(bool useSTL);
void findKthElementTest(int k);
void findKthElement(int length, int k, bool useSTL);

// General puzzles
void findSecondLargestElement();


} // end namespce cc
#endif /* PUZZLES_H_ */
