//This is not something I wrote.
//The whole BST framework that was given to me by the Professor. 
//Credit is below. 

// Binary Search Tree (TreeSet)
// Code from Daniel Liang, C++ Data Structures, Georgia Southern University
//
// changed significantly by W.P. Iverson
// Bellevue College, WA
// Spring 2023

#pragma once
#include "TreeNode.h"
#include "BST_Iterator.h""




template <typename T>
class TreeSet
{
public:
    TreeSet();
    TreeSet(T elements[], int arraySize);
    TreeSet(TreeSet<T>& tree);
    ~TreeSet();
    bool search(T element) const;
    bool insert(T element);
    bool remove(T element);
    int getSize() const;

    Iterator<T> begin() const
    {
        return Iterator<T>(root);
    };

    Iterator<T> end() const
    {
        return Iterator<T>(NULL);
    };

private:
    int size;
    TreeNode<T>* root;
    TreeNode<T>* createNewNode(T element);
    void copy(TreeNode<T>* root);
    void deleteAllNodes(TreeNode<T>* root);
};

template <typename T>
TreeSet<T>::TreeSet()
{
    root = NULL;
    size = 0;
}

template <typename T>
TreeSet<T>::TreeSet(T elements[], int arraySize)
{
    root = NULL;
    size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        insert(elements[i]);
    }
}

template <typename T>
TreeSet<T>::TreeSet(TreeSet<T>& tree)
{
    root = NULL;
    size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
}

template <typename T>
void TreeSet<T>::copy(TreeNode<T>* root)
{
    if (root != NULL)
    {
        insert(root->element);
        copy(root->left);
        copy(root->right);
    }
}

template <typename T>
TreeSet<T>::~TreeSet()
{
    deleteAllNodes(root);
}

template <typename T>
void TreeSet<T>::deleteAllNodes(TreeNode<T>* root)
{
    TreeNode<T>* temp;
    if (root != nullptr) {
        temp = root;
        deleteAllNodes(temp->left);
        deleteAllNodes(temp->right);
        delete root;
    }
    else {
        return;
    }
}





/* Return true if the element is in the tree */
template <typename T>
bool TreeSet<T>::search(T element) const
{
    TreeNode<T>* current = root; // Start from the root

    while (current != NULL)
        if (element < current->element)
        {
            current = current->left; // Go left
        }
        else if (element > current->element)
        {
            current = current->right; // Go right
        }
        else // Element matches current.element
            return true; // Element is found

    return false; // Element is not in the tree
}

template <typename T>
TreeNode<T>* TreeSet<T>::createNewNode(T element)
{
    return new TreeNode<T>(element);
}

/* Insert element into the binary tree
 * Return true if the element is inserted successfully
 * Return false if the element is already in the list
 */
template <typename T>
bool TreeSet<T>::insert(T element)
{
    if (root == NULL)
        root = createNewNode(element); // Create a new root
    else
    {
        // Locate the parent node
        TreeNode<T>* parent = NULL;
        TreeNode<T>* current = root;
        while (current != NULL)
            if (element < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (element > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                return false; // Duplicate node not inserted

        // Create the new node and attach it to the parent node
        if (element < parent->element)
            parent->left = createNewNode(element);
        else
            parent->right = createNewNode(element);
    }

    size++;
    return true; // Element inserted
}


/* Get the number of nodes in the tree */
template <typename T>
int TreeSet<T>::getSize() const
{
    return size;
}

/* Delete an element from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */

template <typename T>
bool TreeSet<T>::remove(T element)
{
    // Locate the node to be deleted and also locate its parent node
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;
    while (current != NULL)
    {
        if (element < current->element)
        {
            parent = current;
            current = current->left;
        }
        else if (element > current->element)
        {
            parent = current;
            current = current->right;
        }
        else
            break; // Element is in the tree pointed by current
    }

    if (current == NULL)
        return false; // Element is not in the tree

    // Case 1: current has no left children
    if (current->left == NULL)
    {
        // Connect the parent with the right child of the current node
        if (parent == NULL)
        {
            root = current->right;
        }
        else
        {
            if (element < parent->element)
                parent->left = current->right;
            else
                parent->right = current->right;
        }

        delete current; // Delete current
    }
    else
    {
        // Case 2: The current node has a left child
        // Locate the rightmost node in the left subtree of
        // the current node and also its parent
        TreeNode<T>* parentOfRightMost = current;
        TreeNode<T>* rightMost = current->left;

        while (rightMost->right != NULL)
        {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right; // Keep going to the right
        }

        // Replace the element in current by the element in rightMost
        current->element = rightMost->element;

        // Eliminate rightmost node
        if (parentOfRightMost->right == rightMost)
            parentOfRightMost->right = rightMost->left;
        else
            // Special case: parentOfRightMost->right == current
            parentOfRightMost->left = rightMost->left;

        delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
}
