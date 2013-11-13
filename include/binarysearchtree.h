/*
 * binarysearchtree.h
 *
 *  Created on: 2013-01-22
 *      Author: carl
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

namespace cc
{
void testTree();

class bst {
    class node {
        friend class bst;

        int _data;
        node *left;
        node *right;
        node(int data) : _data(data), left(0), right(0) {}
    };
    node *_root;

public:
    bst() : _root(0) {}
    bool find(const int data, int& outData);
    void insert(const int data);
    void insertR(const int data);
    void print_inorder();

private:
    void insertR(const int data, node*& tree);
    node* findNode(const int data, node* tree);
    void print_inorder(node* tree);
};

} // end namespace cc
#endif /* BINARYSEARCHTREE_H_ */
