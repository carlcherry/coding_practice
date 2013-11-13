/*
 * heap.cpp
 *
 *  Created on: 2013-01-26
 *      Author: carl
 */
#include "heap.h"
#include "ccutilities.h"
#include "memory.h"
#include <iostream>

namespace cc {

void testHeap()
{
    cc::heap _heap;

    _heap.reserve(20);
    _heap.insert(100);
    _heap.insert(33);
    _heap.insert(14);
    _heap.insert(22);
    _heap.insert(43);
    _heap.insert(8);
    _heap.insert(74);
    _heap.insert(6);
    _heap.insert(2);
    _heap.insert(80);
    _heap.insert(19);
    _heap.insert(11);
    _heap.insert(101);
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
    std::cout << "min heap is " << _heap.delete_max() << std::endl;
}

heap::heap()
: length(0)
, heaparray(0)
, heapSize(0)
{

}

heap::~heap()
{
    delete_heap();
}

void heap::delete_heap()
{
    try
    {
        if (heaparray) delete [] heaparray;
    }
    catch(...) {}
}

void heap::reserve(int maxSize)
{
    length = maxSize;
    delete_heap();
    heaparray = new int[length];
    memset(heaparray, 0x00, length);
}

void heap::insert(int value)
{
    // Verify that the heapsize is less than the array length
    if (heapSize == length)
        throw("heap is full");

    heapSize++;
    int i = heapSize;
    while (heaparray[i/2] > value)
    {
        heaparray[i] = heaparray[i/2];
        i = i / 2;
    }
    heaparray[i] = value;
}

int heap::delete_max()
{
    if (heapSize == 0)
        throw("heap is empty");

    // Capture the value at the root and decrement the heap size
    int result = heaparray[1];
    int valueToMove = heaparray[heapSize];
    heapSize--;

    // Now push the hole down until we find the place to insert valuetoMove
    int i = 1;
    bool done = false;
    while (i * 2 <= heapSize && !done)
    {
        int child = i * 2;
        if (child != heapSize)
        {
            // Figure out if the left or right child is the lower value
            if (heaparray[child + 1] < heaparray[child])
                child++;
        }

        if (valueToMove > heaparray[child])
        {
            // percolate and keep looking
            heaparray[i] = heaparray[child];
            i = child;
        }
        else
        {
            done = true;
        }
    }

    heaparray[i] = valueToMove;

    // return the result
    return result;
}

} // end namespace cc



