#include "node.h"
#include <iostream>
#include <string>
using namespace std;

/*
Name: BST.h
Author: Kyle White
Date: 11/20/2020
Description: The BST.h header file defines all methods and data members of the 
BST template class. Some methods are not utilized in the implementation of the main
function in app.cpp. Items of type T must implement overloaded comparison operators.
*/

template <class T>
class BST
{
    Node<T> *root;

public:
    // Default constructor
    BST();
    // Find method returns true or false if item is present in the tree.
    bool find(T item);
    // Finds the maximum item in the tree
    T &findMax();
    // Finds the minimum item in the tree
    T &findMin();
    // Inserts T item into the tree.
    void insert(T item);
    // Erases T item from the tree using the right subtree method and returns true if complete.
    bool erase(T item);
    // Prints the tree in order.
    void printInOrder();
    // Searches for T item and returns the item if found.
    T search(T item);
    // Erases an item using the left subtree method.
    bool remove(T item);
    // Returns the size of the tree.
    int size();
    // Returns the height of the tree.
    int height();
    // Completely erases the tree
    void clear();
    // Destructor which uses the clear method.
    ~BST();
    // Copy constructor.
    BST(const BST<T> &other);
    // Assignment constructor
    BST<T> &operator=(const BST<T> &other);
    // Returns true if the tree is a valid binary search tree.
    bool validate();
    // Returns the next item in the tree after the input T item.
    T &findNext(T item);
    // Returns the item at the kth value of the tree.
    T &operator[](int k);
};