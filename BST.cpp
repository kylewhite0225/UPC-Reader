#include "bst.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include "UPC.h"
using namespace std;

template <class T>
BST<T>::BST()
{
    root = NULL;
}

template <class T>
bool BST<T>::find(T item)
{
    return find2(root, item);
}

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

template <class T>
T BST<T>::search(T item) {
    return search2(root, item);
}

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

template <class T>
void BST<T>::insert(T item)
{
    insert2(root, item);
}

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

// template <class T>
// void BST<T>::printInOrder()
// {
//     printInOrder2(root);
// }

// template <class T>
// void printInOrder2(Node<T> *root)
// {
//     if (root != NULL)
//     {
//         printInOrder2(root->left);
//         cout << root->data << " ";
//         printInOrder2(root->right);
//     }
// }

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

template <class T>
T &findMax2(Node<T> *root)
{
    if (root->right == NULL)
        return root->data;
    return findMax2(root->right);
}

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

template <class T>
T &findMin2(Node<T> *root)
{
    if (root->left == NULL)
        return root->data;
    return findMin2(root->left);
}

template <class T>
bool BST<T>::erase(T item)
{
    return erase2(item, root);
}

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

template <class T>
bool BST<T>::remove(T item)
{
    return remove2(item, root);
}

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

// template <class T>
// void bst_print_dot_null(Node<T> *&node, int nullcount, FILE *stream)
// {
//     fprintf(stream, "    null%d [shape=point];\n", nullcount);
//     fprintf(stream, "    %s -> null%d;\n", addressToString(node).c_str(), nullcount);
// }

// template <class T>
// void bst_print_dot_aux(Node<T> *&node, FILE *stream)
// {
//     static int nullcount = 0;

//     if (node->left)
//     {
//         fprintf(stream, "    %s -> %s;\n", addressToString(node).c_str(), addressToString(node->left).c_str());
//         bst_print_dot_aux(node->left, stream);
//     }
//     else
//         bst_print_dot_null(node, nullcount++, stream);

//     if (node->right)
//     {
//         fprintf(stream, "    %s -> %s;\n", addressToString(node).c_str(), addressToString(node->right).c_str());
//         bst_print_dot_aux(node->right, stream);
//     }
//     else
//         bst_print_dot_null(node, nullcount++, stream);
// }

// template <class T>
// string addressToString(Node<T> *&root)
// {
//     stringstream ss;
//     ss << root;
//     string name = ss.str();
//     return "a" + name + "_" + to_string(root->data);
// }

// template <class T>
// string createLabels(Node<T> *&tree)
// {
//     if (tree == NULL)
//         return "";

//     string address = addressToString(tree);

//     string label = address + " [label=\"" + to_string(tree->data) + "\"]\n";

//     return createLabels(tree->left) + label + createLabels(tree->right);
// }

// template <class T>
// void bst_print_dot(Node<T> *tree, FILE *stream)
// {
//     fprintf(stream, "digraph BST {\n");
//     //fprintf(stream, createLabels(tree).c_str());
//     fprintf(stream, "    node [fontname=\"Arial\"];\n");

//     if (!tree)
//         fprintf(stream, "\n");
//     else if (!tree->right && !tree->left)
//         fprintf(stream, "    %s;\n", addressToString(tree).c_str());
//     else
//         bst_print_dot_aux(tree, stream);

//     fprintf(stream, "}\n");
// }

// template <class T>
// void BST<T>::exportDot(string filename)
// {
//     FILE *file = fopen(filename.c_str(), "w");
//     bst_print_dot(root, file);
// }

template <class T>
int BST<T>::size()
{
    return size2(root);
}

template <class T>
int size2(Node<T> *root)
{
    if (root == NULL)
        return 0;

    return 1 + size2(root->left) + size2(root->right);
}

template <class T>
int BST<T>::height()
{
    return height2(root);
}

template <class T>
int height2(Node<T> *root)
{
    if (root == NULL || root->isLeaf())
        return 0;

    return 1 + max(height2(root->left), height2(root->right));
}

template <class T>
void BST<T>::clear()
{
    clear2(root);
}

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

template <class T>
BST<T>::~BST()
{
    // cout << "destroy...";
    clear();
    // cout << "complete." << endl;
}

template <class T>
BST<T>::BST(const BST<T> &other)
{
    root = copySubtree(other.root);
}

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

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &other)
{
    root = copySubtree(other.root);
    return *this;
}

// template <class T>
// bool BST<T>::validate()
// {
//     return validate2(root);
// }

// template <class T>
// bool validate2(Node<T> *root)
// {
//     if (root == NULL)
//         return true;

//     bool isLeftBST = validate2(root->left);
//     bool isRightBST = validate2(root->right);

//     if (isLeftBST && isRightBST)
//     {
//         return (root->left == NULL || findMax2(root->left) < root->data) &&
//                (root->right == NULL || findMin2(root->right) >= root->data);
//     }

//     return false;
// }

template <class T>
T &BST<T>::findNext(T item)
{
    return findNext2(item, root);
}

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

template class BST<UPC>;