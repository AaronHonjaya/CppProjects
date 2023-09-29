
//This was given by my Professor
//The only thing I added was a visited boolean to the TreeNode struct (labeled with comments).

//Credit: Professor William Iverson at Bellevue College, WA. 


#pragma once
template<typename T>
class TreeNode
{
public:
    T element;
    TreeNode<T>* left;
    TreeNode<T>* right;

    //added
    bool visited;

    TreeNode(T element)
    {
        this->element = element;
        left = NULL;
        right = NULL;

        //added
        visited = false;

    }
};