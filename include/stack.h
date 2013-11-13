/*
 * stack.h
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#ifndef __CC_STACK_H_
#define __CC_STACK_H_

namespace cc
{
void testStack();

class stack
{
private:
   struct node
   {
      int _data;
      node * _next;
      node(int data, node *next);
   };
   node *_head;

public:
   stack();
   ~stack();
   int pop();
   void push(int data);
   bool empty();
};

} // end namespace cc
#endif /* __CC_STACK_H_ */
