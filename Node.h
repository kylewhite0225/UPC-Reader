#include <cstddef>

/*
Name: Node.h
Author: Kyle White
Date: 11/20/2020
Description: Header file for the Node struct which defines public members
and methods. Each node stores T data and Node<T> pointers to left and right children.
*/

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data) : data(data), left(NULL), right(NULL) {}
    bool isLeaf() { return left == NULL && right == NULL; }
    bool isFull() { return left != NULL && right != NULL; }
};