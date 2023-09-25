#pragma once
#pragma once
// Original code from Daniel Liang (2003)
// now animated at yongdanielliang.github.io/animation/web/LinkedList.html
// 
// Extensively modified by W.P. Iverson
// Bellevue College, May 2023
// for CS212

#include <stdexcept>
#include <sstream>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node() // No-arg constructor
    {
        next = NULL;
    }

    Node(T element) // Constructor
    {
        this->element = element;
        next = NULL;
    }

    // just for console testing:
    void printNodes()
    {
        Node<T>* current = this;
        while (current->next != NULL)
        {
            cout << current->element << " ";
            current = current->next;
        }
        cout << current->element << endl;
    }

    // so we can keep nodes private
    void setNext(Node<T>* change)
    {
        next = change;
    }

    T getData()
    {
        return element;
    }

    Node<T>* getNext()
    {
        return next;
    }

private:
    T element;  // Element contained in the node
    Node<T>* next; // Pointer to the next node
};


