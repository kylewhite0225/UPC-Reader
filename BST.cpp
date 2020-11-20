#include "bst.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include "UPC.h"
using namespace std;

/*
Name: BST.cpp
Author: Kyle White
Date: 11/20/2020
Description: BST.cpp implements all of the method prototypes previously defined
in the header file.
*/

// Default constructor
template <class T>
BST<T>::BST()
{
    root = NULL;
}

// Wrapper method for the find2 method which returns true if the item is present
// in the binary search tree.
template <class T>
bool BST<T>::find(T item)
{
    return find2(root, item);
}

// Recursive find2 method returns true if the item is present in the binary search tree.
template <class T>
bool find2(Node<T> *root, T item)
{
    if (root == NULL)
        return false;

    if (root->data == item)
        return true;

    else if (root->data < item)
        return find2(root->right, item);
    else
        return find2(root->left, item);
}

// Wrapper method for the search2 method.
template <class T>
T BST<T>::search(T item) {
    return search2(root, item);
}

// Recursive search2 method which returns the item if found in the binary search tree.
template <class T>
T search2(Node<T> *root, T item) {
    if (root == NULL)
        return item;
    
    if (root->data == item)
        return root->data;

    else if (root->data < item)
        return search2(root->right, item);
    else
        return search2(root->left, item); 
}

// Wrapper method for the insert2 method which inserts an item into the binary search tree.
template <class T>
void BST<T>::insert(T item)
{
    insert2(root, item);
}

// Recursive insert2 method which inserts an item into the binary search tree.
template <class T>
void insert2(Node<T> *&root, T item)
{
    if (root == NULL)
    {
        root = new Node<T>(item);
    }
    else if (item < root->data)
        insert2(root->left, item);
    else
        insert2(root->right, item);
}

// Wrapper method for the printInOrder2 method which prints the tree.
template <class T>
void BST<T>::printInOrder()
{
    printInOrder2(root);
}

// printInOrder2 method which recursively prints the tree to the console.
template <class T>
void printInOrder2(Node<T> *root)
{
    if (root != NULL)
    {
        printInOrder2(root->left);
        cout << root->data << " ";
        printInOrder2(root->right);
    }
}

// Wrapper method for the findMax2 method which returns the maximum T item
// in the binary search tree.
template <class T>
T &BST<T>::findMax()
{
    if (root == NULL)
    {
        cout << "tree is empty, abort." << endl;
        exit(0);
    }
    return findMax2(root);
}

// findMax2 method recursively finds the maximum item in the tree.
template <class T>
T &findMax2(Node<T> *root)
{
    if (root->right == NULL)
        return root->data;
    return findMax2(root->right);
}

// Wrapper method for the findMin2 method which returns the minimum T item
// in the binary search tree.
template <class T>
T &BST<T>::findMin()
{
    if (root == NULL)
    {
        cout << "tree is empty, abort." << endl;
        exit(0);
    }
    return findMin2(root);
}

// findMin2 method recursively finds the minimum item in the tree.
template <class T>
T &findMin2(Node<T> *root)
{
    if (root->left == NULL)
        return root->data;
    return findMin2(root->left);
}

// Wrapper method for the erase2 class which removes an item from the tree and
// returns true if successful, using the right subtree method.
template <class T>
bool BST<T>::erase(T item)
{
    return erase2(item, root);
}

// erase2 method recursively deletes an item in the BST and returns true if successful.
template <class T>
bool erase2(T item, Node<T> *&rootInSubtree)
{
    if (rootInSubtree == NULL)
        return false;

    if (item == rootInSubtree->data)
    {
        if (rootInSubtree->isLeaf())
        {
            delete rootInSubtree;
            rootInSubtree = NULL;
        }
        else if (rootInSubtree->isFull())
        {
            rootInSubtree->data = findMin2(rootInSubtree->right);
            erase2(rootInSubtree->data, rootInSubtree->right);
        }
        else
        {
            Node<T> *toDelete = rootInSubtree;
            if (rootInSubtree->left == NULL)
                rootInSubtree = rootInSubtree->right;
            else
                rootInSubtree = rootInSubtree->left;

            delete toDelete;
        }
        return true;
    }
    else if (item < rootInSubtree->data)
    {
        return erase2(item, rootInSubtree->left);
    }
    else
    {
        return erase2(item, rootInSubtree->right);
    }
}

// Wrapper method for the remove2 method.
template <class T>
bool BST<T>::remove(T item)
{
    return remove2(item, root);
}

// remove2 method removes an item from the tree using the left subtree method.
template <class T>
bool remove2(T item, Node<T> *&rootInSubtree)
{
    if (rootInSubtree == NULL)
        return false;

    if (item == rootInSubtree->data)
    {
        if (rootInSubtree->isLeaf())
        {
            delete rootInSubtree;
            rootInSubtree = NULL;
        }
        else if (rootInSubtree->isFull())
        {
            rootInSubtree->data = findMax2(rootInSubtree->left);
            remove2(rootInSubtree->data, rootInSubtree->left);
        }
        else
        {
            Node<T> *toDelete = rootInSubtree;
            if (rootInSubtree->left == NULL)
                rootInSubtree = rootInSubtree->right;
            else
                rootInSubtree = rootInSubtree->left;

            delete toDelete;
        }
        return true;
    }
    else if (item < rootInSubtree->data)
    {
        return remove2(item, rootInSubtree->left);
    }
    else
    {
        return remove2(item, rootInSubtree->right);
    }
}

// Wrapper method for size2 which returns the size of the tree.
template <class T>
int BST<T>::size()
{
    return size2(root);
}

// Returns the size of the tree.
template <class T>
int size2(Node<T> *root)
{
    if (root == NULL)
        return 0;

    return 1 + size2(root->left) + size2(root->right);
}

// Wrapper method for the height2 method which returns the height of the tree.
template <class T>
int BST<T>::height()
{
    return height2(root);
}

// Returns the height of the tree.
template <class T>
int height2(Node<T> *root)
{
    if (root == NULL || root->isLeaf())
        return 0;

    return 1 + max(height2(root->left), height2(root->right));
}

// Wrapper method for the clear2 method which completely erases the tree.
template <class T>
void BST<T>::clear()
{
    clear2(root);
}

// Completely erases the tree.
template <class T>
void clear2(Node<T> *&root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        clear2(root->left);

    if (root->right != NULL)
        clear2(root->right);

    delete root;
    root = NULL;
}

// Destructor utilizes the clear() method.
template <class T>
BST<T>::~BST()
{
    // cout << "destroy...";
    clear();
    // cout << "complete." << endl;
}

// Copy constructor
template <class T>
BST<T>::BST(const BST<T> &other)
{
    root = copySubtree(other.root);
}

// copySubtree method which returns a deep copy of the parameter tree object.
template <class T>
Node<T> *copySubtree(Node<T> *root)
{
    if (root == NULL)
        return NULL;

    Node<T> *newRoot = new Node<T>(root->data);
    newRoot->left = copySubtree(root->left);
    newRoot->right = copySubtree(root->right);
    return newRoot;
}

// Assignment constructor
template <class T>
BST<T> &BST<T>::operator=(const BST<T> &other)
{
    root = copySubtree(other.root);
    return *this;
}

// Wrapper method for the validate2 method which returns true if the tree is a binary search tree
template <class T>
bool BST<T>::validate()
{
    return validate2(root);
}

// Returns true if the tree is a binary search tree
template <class T>
bool validate2(Node<T> *root)
{
    if (root == NULL)
        return true;

    bool isLeftBST = validate2(root->left);
    bool isRightBST = validate2(root->right);

    if (isLeftBST && isRightBST)
    {
        return (root->left == NULL || findMax2(root->left) < root->data) &&
               (root->right == NULL || findMin2(root->right) >= root->data);
    }

    return false;
}

// Wrapper method for the findNext2 method which returns the next item in the tree
template <class T>
T &BST<T>::findNext(T item)
{
    return findNext2(item, root);
}

// Returns the next item in the tree compared to the input item.
template <class T>
T &findNext2(T &item, Node<T> *root)
{
    if (root == NULL)
        return item;

    if (item == root->data)
    {
        return (root->right == NULL) ? item : findMin2(root->right);
    }
    else if (item < root->data)
    {
        T temp = findNext2(item, root->left);
        return (temp == item) ? root->data : temp;
    }
    else
    {
        return findNext2(item, root->right);
    }
}

// Overloaded [] operator which returns the item at the kth index.
template <class T>
T &BST<T>::operator[](int k)
{
    if (k < 0 || k >= size())
    {
        cout << "out of range" << endl;
        exit(0);
    }

    return findKth(k, root);
}

// Recursive findKth method which returns the item at the kth index.
template <class T>
T &findKth(int k, Node<T> *root)
{
    int leftSize = size2(root->left);

    if (leftSize == k)
    {
        return root->data;
    }
    else if (leftSize > k)
    {
        return findKth(k, root->left);
    }
    else
    {
        return findKth(k - leftSize - 1, root->right);
    }
}

// Defines UPC as a valid filetype for use in the BST<T> class.
template class BST<UPC>;