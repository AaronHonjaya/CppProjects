#include "BST_Iterator.h"
#include <string>
//#include "TreeIterator.h"


using namespace std;

// CS212, Spring 2023
// W.P. Iverson, instructor

int main()
{
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







	cout << endl;

	return 0;
}