//#include "BST_Iterator.h"
#include <string>
#include "Tree.h"
#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;

// CS212, Spring 2023
// W.P. Iverson, instructor

void testBSTIterator() {
	// Create a tree for strings
	TreeSet<string> tree;

	// Add elements to the tree
	tree.insert("Kansas");
	tree.insert("Colorado");
	tree.insert("Maine");
	tree.insert("Washington");

	// Create an iterator from this set, 
	Iterator<string> iter = tree.begin();
	cout << *iter << "   ";
	++iter;

	// then add Alabama and far left/right data
	tree.insert("Alabama");
	cout << *iter << "   ";
	++iter;



	cout << *iter << "   ";
	tree.insert("Denver");
	++iter;




	tree.insert("AAAleft");
	tree.insert("ZZZright");

	// then iterate to end()
	while (iter != tree.end())
	{
		cout << *iter << "   ";
		++iter;
	}

};


void testLinkedList() {
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	LinkedList<int> list2 = list;
	list2.printList();
	list.remove(1);
	cout << endl;
	list2.printList();

	
};

void testArrayList() {
	ArrayList<int> arr;
	arr.add(1);
	arr.add(2);
	ArrayList<int> arr2 = arr;
	cout << arr2.to_string() << endl;
	arr2.addAll(arr);
	cout << arr2.to_string() << endl;
}

int main()
{
	testArrayList();






	cout << endl;

	return 0;
}

