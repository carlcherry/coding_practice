/*
 * list.h
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#ifndef __CC_LIST_H_
#define __CC_LIST_H_

namespace cc
{

void testList();

class list
{
    class listnode
    {
        friend class list;
        int _data;
        listnode *prev;
        listnode *next;
        listnode(int data, listnode* p, listnode* n);
    };
    listnode *_head;
    listnode *_tail;
public:
    list();
    ~list();

    bool empty() const;

    void push_back(int data);
    void push_front(int data);
    int pop_back();
    int pop_front();
};
} // end namespace cc
#endif /* __CC_LIST_H_ */
