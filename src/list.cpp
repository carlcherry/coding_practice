/*
 * list.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#include "list.h"
#include <iostream>

namespace cc
{

void testList()
{
    cc::list intList;
    intList.push_back(1);
    intList.push_front(2);
    intList.push_back(4);

    while (!intList.empty())
        std::cout << intList.pop_front() << std::endl;
}


list::listnode::listnode(int data, listnode* p, listnode* n) : _data(data), prev(p), next(n)
{
    // Fix up the previous and next pointers of the noded passed in
    if (prev)
        prev->next = this;
    if (next)
        next->prev = this;
}

list::list() : _head(0), _tail(0)
{
}

list::~list()
{
    listnode *temp = _head;
    while (temp)
    {
        listnode *pDelete = temp;
        temp = temp->next;
        delete pDelete;
    }
}

bool list::empty() const
{
    return ( !_head || !_tail );
}

int list::pop_back()
{
    // First check to see if tail points to anything
    if( empty() )
        throw("list is empty");

    // Copy T, remove the tail node, return T
    int data = _tail->_data;
    listnode *pTemp = _tail;
    _tail = _tail->prev;

    // Fix up pointers
    if (_tail)
    {
        _tail->next = 0;
    }
    else
    {
        _head = 0;
    }

    delete pTemp;
    return data;
}

int list::pop_front()
{
    // First check to see if tail points to anything
    if( empty() )
        throw("list is empty");

    int data = _head->_data;
    listnode *pTemp = _head;

    // Fixt up the pointers
    _head = _head->next;
    if (_head)
    {
        _head->prev = 0;
    }
    else
    {
        _tail = 0;
    }

    delete pTemp;
    return data;
}


void list::push_back(int data)
{
    // Create a new tail node - which automatically gets attached behind the previous tail.
    _tail = new listnode(data, _tail, 0);
    if (empty())
        _head = _tail;
}

void list::push_front(int data)
{
    // Create a new tail node - which automatically gets attached behind the previous tail.
    _head = new listnode(data, 0, _head);
    if (empty())
        _tail = _head;
}

} // end namespace cc




