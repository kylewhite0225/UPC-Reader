#include "node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class BST
{
    Node<T> *root;

public:
    BST();
    bool find(T item);
    T &findMax();
    T &findMin();
    void insert(T item);
    bool erase(T item);
    // void printInOrder();
    T search(T item);

    bool remove(T item); //erase using left subtree
    int size();
    int height();
    void clear();
    ~BST();
    BST(const BST<T> &other);
    BST<T> &operator=(const BST<T> &other);
    // bool validate();

    T &findNext(T item);
    T &operator[](int k); //kth value
};