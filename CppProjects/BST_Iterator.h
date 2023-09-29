

// Binary Search Tree (TreeSet)
// Code from Liang, C++ Data Structures
//
// changed significantly by W.P. Iverson
// Bellevue College, WA
// Spring 2023


//only the template and class were given here (eg "template <typename T> class Iterator : public std::iterator<std::forward_iterator_tag, T>")
//Credit: Professor William Iverson at Bellevue College, WA
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Tree.h"
using namespace std;



template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    Iterator(TreeNode<T>* node)
    {
        if (node == NULL)
            current = nullptr;
        else
        {
            root = node; //root holds root of tree
            current = node; //current will hold the current value. To start this is the smallest value.
            while (current->left != nullptr) {
                current = current->left;
            }
            current->visited = true; //visited was a variable I added to TreeNode to make it easier to track which nodes I have visited
            lastInOrderNode = current; //lastAddedNode is just initially set to current; 
        }
    }

    // prefix forward increment
    Iterator& operator++()
    {
        if (lastInOrderNode->element > current->element) {
            current = lastInOrderNode;
        }
        else {
            lastInOrderNode = current;
        }


        TreeNode<T>* temp;
        temp = (current->element > root->element) ? current : root;
        TreeNode<T>* previous = current;
        getSmallestUnvisited(root, temp);

        if (current == previous) {
            current = getNext(root);
        }
        if (current == nullptr) {
            *this = nullptr;
        }
        else {
            current->visited = true;
        }

        return *this;
    }

    // dereference
    T& operator*()
    {
        return current->element;
    }

    // comparison operators
    bool operator == (const Iterator<T>& Iterator) const
    {
        return current == Iterator.current;
    }

    bool operator != (const Iterator<T>& Iterator) const
    {
        return current != Iterator.current;
    }


private:
    TreeNode<T>* current;  // starts at bottom left of tree;
    TreeNode<T>* root; // holds root value of tree;
    TreeNode<T>* temp;
    // this holds location of previous node that was in order. 
    //For instance, if the iterator is at Maine, and Alabama is added,
    //then we need to hold the location of maine, while current moves to Alabama.
    TreeNode<T>* lastInOrderNode;


    bool getSmallestUnvisited(TreeNode<T>* root, TreeNode<T>* result) {


        if (root != nullptr) {
            if (!root->visited && root->element < result->element) {
                getSmallestUnvisited(root->left, root);
                getSmallestUnvisited(root->right, root);
            }
            else {
                getSmallestUnvisited(root->left, result);
                getSmallestUnvisited(root->right, result);
            }
        }
        if (!result->visited) {
            current = result;
            return true;
        }
        else {
            return false;
        }
    }


    TreeNode<T>* getNext(TreeNode<T>* root) {
        if (root->right == nullptr && root->left == nullptr) {
            if (root == current) {
                return nullptr;
            }
            else {
                return root;
            }
        }
        else if (root->right == nullptr) {//if root right is null then left is not null;
            if (root->left->element > current->element) {
                return getNext(root->left);
            }
            else {
                return root;
            }
        }
        else if (root->left == nullptr) { //if root left is null, root right is not null;
            if (root->element > current->element) {
                return root;
            }
            else {
                return getNext(root->right);
            }
        }
        else {
            if (root->left->element > current->element && root->right->element > current->element) {
                return getNext(root->left);
            }
            else if (root->left->element < current->element) {
                //if left smaller, check root.
                //if root smaller, go right.
                if (root->element > current->element) {
                    return root;
                }
                else {
                    return getNext(root->right);
                }
            }
            else if (root->left->element == current->element) {
                return root;
            }
            else {
                return getNext(root->right);
            }
        }
    }
};



