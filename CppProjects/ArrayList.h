#pragma once

//CS212: Create an ArrayList
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
//#include <cstring>

using namespace std;

template<typename E>
class ArrayList
{
public:
	ArrayList();
	ArrayList(int);
	void add(E);
	void add(int, E);
	void addAll(ArrayList<E>);
	int size() const;
	void clear();
	bool contains(E) const;
	E get(int) const;
	int indexOf(E) const;
	bool isEmpty() const;
	void remove(int);

	E set(int, E);
	string to_string() const;
	//string to_string() const;
private:
	int internalIndex = 0;
	int arraySize = 0;
	int arraySize2 = 1;

	E* list; // array starts at size 10
	void resize(int increase); // can resize
	// add helpers, int size, etc...
};


using namespace std;

template<typename E>
ArrayList<E>::ArrayList() {
	list = new E[arraySize];
}

template<typename E>
ArrayList<E>::ArrayList(int size) {
	arraySize = size;
	list = new E[arraySize];
}



template<typename E>
void ArrayList<E>::add(E value) {
	while (internalIndex >= arraySize) {
		resize(1);
	}
	list[internalIndex] = value;
	internalIndex++;
}

template<typename E>
void ArrayList<E>::add(int index, E value) {
	resize(1);
	for (int i = arraySize - 1; i > index; i--) {
		list[i] = list[i - 1];
	}
	list[index] = value;
}

template<typename E>
void ArrayList<E>::remove(int index) {
	E lastNum = list[arraySize - 1];
	cout << arraySize << endl;
	resize(-1);
	cout << arraySize << endl;
	for (int i = index; i < arraySize - 1; i++) {
		cout << i << ", ";
		list[i] = list[i + 1];
	}
	cout << endl;
	list[arraySize - 1] = lastNum;
}


template<typename E>
void ArrayList<E>::addAll(ArrayList<E> otherArray) {
	int otherSize = otherArray.size();
	int oldArraySize = arraySize;
	resize(otherSize);
	for (int i = oldArraySize; i < oldArraySize + otherSize; i++) {
		list[i] = otherArray.get(i - oldArraySize);
	}
}




template<typename E>
void ArrayList<E>::clear() {
	arraySize = 0;
	delete[] list;
	list = new E[0];
}

template<typename E>
bool ArrayList<E>::contains(E val) const {
	for (int i = 0; i < arraySize; i++) {
		if (list[i] == val) {
			return true;
		}
	}
}
template<typename E>
bool ArrayList<E>::isEmpty() const {
	return (arraySize == 0);
}

template<typename E>
int ArrayList<E>::indexOf(E val) const {
	for (int i = 0; i < arraySize; i++) {
		if (list[i] == val) {
			return i;
		}
	}
	return -1;
}


template<typename E>
int ArrayList<E>::size() const {
	return arraySize;
}

template<typename E>
E ArrayList<E>::get(int index) const {
	return list[index];
}

template<typename E >
E ArrayList<E>::set(int index, E value) {
	E temp;
	temp = list[index];
	list[index] = value;
	return temp;
}

template<typename E >
string ArrayList<E>::to_string() const {
	ostringstream str;
	str << '[';
	for (int i = 0; i < arraySize; i++) {
		str << list[i];
		if (i < arraySize - 1) {
			str << ", ";
		}
	}
	str << ']';
	return str.str();
}

/*
template<typename E>
void ArrayList<E>::resize(int increase) {
	int oldSize = arraySize;
	arraySize += increase;
	E* newList = new E[arraySize];
	memcpy(newList, list, (oldSize*sizeof(E)) );
	//delete[] list;
	list = newList;
}*/


template<typename E>
void ArrayList<E>::resize(int increase) {
	int newSize = arraySize + increase;
	E* newList = new E[newSize];
	int loopNum = (arraySize < newSize ? arraySize : newSize);
	for (int i = 0; i < loopNum; i++) {
		newList[i] = list[i];
	}
	arraySize = newSize;
	list = newList;
}
