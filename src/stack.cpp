/*
 * stack.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */
#include "stack.h"
#include <iostream>

namespace cc
{

void testStack()
{
    int arr[] =  { 4, 0, 6, 6, 2, 5, 12, 20, 2, 18, 7, 5, 3, 1, 9, 8, 11 };
    int length = sizeof(arr)/sizeof(int);

    cc::stack myIntStack;
    for (int i = 0; i < length; ++i)
    {
        myIntStack.push(arr[i]);
    }

    while (!myIntStack.empty())
        std::cout << myIntStack.pop() << std::endl;
}


stack::node::node(int data, node *next)
: _data(data), _next(next)
{
}

int stack::pop()
{
    if (!_head)
        throw("stack is empty");

    int result = _head->_data;
    node * temp = _head;
    _head = _head->_next;
    delete temp;
    return result;
}

void stack::push(int data)
{
    _head = new node(data, _head);
}

bool stack::empty()
{
    return (_head == 0);
}

stack::stack()
: _head(0)
{
}

stack::~stack()
{
    // Don't let exceptions leave the descructor
    try
    {
        while (_head)
        {
            node * temp = _head;
            _head = _head->_next;
            delete temp;
        }
    }
    catch(...) {} // just eat the exceptions
}

} // end namespace cc


