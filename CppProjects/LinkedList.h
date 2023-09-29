//Everything was coded by me except the given class (eg. "template<typename T> class LinkedList {}" was given). 
//Some method declarations may have been a given such as "add", or "to_string" but the actual body of the methods were written by me. 
//Credit: Professor William Iverson at Bellevue College, WA. 

#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
public:
    LinkedList();

    LinkedList(const LinkedList<T>& rhs);
    ~LinkedList();
    void operator=(const LinkedList<T>& rhs);


    void addLast(T element);
    void add(T element);
    void printList() const;
    string to_string() const;
    int getSize() const;
    void clear();
    bool addAll(LinkedList<T>& otherList);
    bool removeAll(LinkedList<T>& otherList);
    bool retainAll(LinkedList<T>& otherList);


    T operator[](int index) {
        Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->getData();
    }

    friend LinkedList<T>& operator+(LinkedList<T>& lhs, LinkedList<T>& rhs) {
        LinkedList<T>* temp = new LinkedList<T>;
        temp->addAll(lhs);
        temp->addAll(rhs);
        return *temp;
    }

    friend LinkedList<T>& operator-(LinkedList<T>& lhs, LinkedList<T>& rhs) {
        LinkedList<T>* temp = new LinkedList<T>;
        temp->addAll(lhs);
        temp->removeAll(rhs);
        return *temp;
    }

    friend LinkedList<T>& operator^(LinkedList<T>& lhs, LinkedList<T>& rhs) {
        LinkedList<T>* temp = new LinkedList<T>;
        temp->addAll(lhs);
        temp->retainAll(rhs);
        return *temp;
    }

    void remove(T element);
    int lastIndexOf(T element);
    bool contains(T element) {
        Node<T>* pointer = head;
        T data;
        while (pointer != nullptr) {
            data = pointer->getData();
            if (data == element) {
                return true;
            }
            pointer = pointer->getNext();
        }
        return false;
    };

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
    size = rhs.size;

    if (rhs.head == nullptr) {
        head = tail = nullptr;
        return;
    }

    Node<T>* temp = rhs.head;
    Node<T>* newNode = nullptr;
    while (temp != nullptr) {
        newNode = new Node<T>(temp->getData());
        newNode->setNext(nullptr);
        if (head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->setNext(newNode);
            this->tail = newNode;
        }
        temp = temp->getNext();
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
    Node<T>* temp;

    for (int i = 0; i < size; i++) {
        temp = curr->getNext();
        delete curr;
        curr = temp;
    }
}


template<typename T>
void LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    clear();
    addAll(rhs);
    cout << "copy assignment operator worked";
}

template<typename T>
void LinkedList<T>::printList() const
{
    head->printNodes();
}

template<typename T>
string LinkedList<T>::to_string() const
{
    if (head == NULL) return "[]";
    stringstream result;
    result << "[" << head->getData();
    Node<T>* current = head->getNext();
    while (current != NULL)
    {
        result << ", " << current->getData();
        current = current->getNext();
    }
    result << "]";
    return result.str();
}


// Use tail to avoid traversal of whole list
template<typename T>
void LinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else
    {
        Node<T>* temp = new Node<T>(element);
        tail->setNext(temp);
        tail = temp;
    }
    size++;
}

// Standard List adds data at end of list
template<typename T>
void LinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
int LinkedList<T>::getSize() const {
    return this->size;
}

template<typename T>
void LinkedList<T>::remove(T element) {
    Node<T>* temp;
    if (head->getData() == element) {
        temp = head->getNext();
        delete head;
        head = temp;
        size--;
    }
    else {
        Node<T>* current = head;
        Node<T>* ahead = current->getNext();
        while (ahead->getData() != element) {
            current = current->getNext();
            ahead = current->getNext();
            if (ahead == nullptr) {
                return;
            }
        }
        temp = ahead->getNext();
        delete ahead;
        current->setNext(temp);
        if (temp == nullptr) {
            tail = current;
        }
        size--;
    }
}

template<typename T>
bool LinkedList<T>::addAll(LinkedList<T>& otherList) {
    Node<T>* temp = otherList.head;
    T data;
    while (temp != nullptr) {
        data = temp->getData();
        add(data);
        temp = temp->getNext();
    }
    return true;
}

template<typename T>
bool LinkedList<T>::removeAll(LinkedList<T>& otherList) {
    Node<T>* currentNode = head;
    Node<T>* temp;
    T currData;
    while (currentNode != nullptr) {
        currData = currentNode->getData();
        currentNode = currentNode->getNext();
        if (otherList.contains(currData)) {
            this->remove(currData);
        }
    }
    return true;
}

template<typename T>
bool LinkedList<T>::retainAll(LinkedList<T>& otherList) {
    Node<T>* currentNode = head;
    Node<T>* temp;
    T currData;
    while (currentNode != nullptr) {
        currData = currentNode->getData();
        currentNode = currentNode->getNext();
        if (!otherList.contains(currData)) {
            this->remove(currData);
        }
    }
    return true;
}

template<typename T>
void LinkedList<T>::clear() {
    Node<T>* temp;
    Node<T>* current = head;
    while (current != nullptr) {
        temp = current;
        current = current->getNext();
        delete temp;
    }
    head = tail = nullptr;
    size = 0;

}




template<typename T>
int LinkedList<T>::lastIndexOf(T element) {
    int index = -1;
    int counter = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->getData() == element) {
            index = counter;
        }
        counter++;
        current = current->getNext();
    }
    return index;
}
