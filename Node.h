#include <cstddef>

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