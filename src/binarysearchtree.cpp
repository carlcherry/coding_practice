/*
 * binarysearchtree.cpp
 *
 *  Created on: 2013-01-22
 *      Author: carl
 * here is a comment for Andrew
 */

// Here is a comment for Andrew

#include "binarysearchtree.h"
#include <iostream>

namespace cc
{

bst::node* bst::findNode(const int data, node* tree)
{
    // Check for a null node
    if (!tree)
        return 0;

    /// See if this is our node
    if (data == tree->_data)
        return tree;
    else if (data < tree->_data)
        return findNode(data, tree->left);
    else
        return findNode(data, tree->right);
}

void bst::print_inorder()
{
    if (_root == 0)
    {
        std::cout << "BST tree is empty" << std::endl;
        return;
    }

    print_inorder(_root);
}

void bst::print_inorder(node* tree)
{
    if (tree == 0)
        return;
    print_inorder(tree->left);
    std::cout << "Node value: " << tree->_data << std::endl;
    print_inorder(tree->right);
}

void bst::insert(const int data)
{
    // Edge case - tree is empty
    if (_root == 0)
        _root = new node(data);

    // Normal case - start at root and find the place to insert the node
    node *currentNode = _root;
    bool found = false;
    while (!found && currentNode)
    {
        if (currentNode->_data == data)
            return; // Quit now - node is already in the tree

        // Check the left tree
        if (data < currentNode->_data)
        {
            if (currentNode->left)
            {
                currentNode = currentNode->left;
            }
            else
            {
                found = true;
                currentNode->left = new node(data);
            }
        }
        else
        {
            // We need to check the right tree
            if (currentNode->right)
            {
                currentNode = currentNode->right;
            }
            else
            {
                found = true;
                currentNode->right = new node(data);
            }
        }
    }
}

bool bst::find(const int data, int& outData)
{
    // Start at the root and look for the node
    node* foundNode = findNode(data, _root);
    if (foundNode)
    {
        std::cout << "Node found..." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Node NOT found..." << std::endl;
        return false;
    }
}

void bst::insertR(const int data)
{
    // Call the recursive private method to add the node
    insertR(data, _root);
}

void bst::insertR(const int data, node*& tree)
{
    // Base case - this is where we actually add the node and end
    if (tree == 0)
    {
        tree = new node(data);
    }
    else
    {
        if (data < tree->_data)
            insertR(data, tree->left);
        else if (data > tree->_data)
            insertR(data, tree->right);
        // Else do nothing as this item is already in the tree
    }
}

void testTree()
{
    // Now test out our BST implementation
    cc::bst intBST;
    intBST.insert(23);
    intBST.insert(2);
    intBST.insert(2);
    intBST.insert(2);
    intBST.insert(10);
    intBST.insert(84);
    intBST.insert(50);
    intBST.insert(6);
    intBST.insert(30);
    intBST.insert(40);
    intBST.insert(35);
    std::cout << "Contents of tree 1" << std::endl;
    intBST.print_inorder();
    cc::bst intBST2;
    intBST2.insertR(18);
    intBST2.insertR(18);
    intBST2.insertR(18);
    intBST2.insertR(88);
    intBST2.insertR(17);
    intBST2.insertR(87);
    intBST2.insertR(16);
    intBST2.insertR(86);
    intBST2.insertR(15);
    intBST2.insertR(85);
    intBST2.insertR(100);
    std::cout << "Contents of tree 2" << std::endl;
    intBST2.print_inorder();
}

} // end namespace cc
