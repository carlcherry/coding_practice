/*
 * heap.h
 *
 *  Created on: 2013-01-20
 *      Author: carl
 */

#ifndef __CC_HEAP_H_
#define __CC_HEAP_H_

namespace cc
{

void testHeap();

class heap
{
public:
    heap();
    virtual ~heap();
    void reserve(int maxSize);
    void insert(int i);
    int delete_max();

private:
    void delete_heap();
    int length;
    int *heaparray;
    int heapSize;
};

} // end namespace cc
#endif /* __CC_HEAP_H_ */
