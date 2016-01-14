#ifndef PBY_TREE
#define PBY_TREE
#include <iostream>

using namespace std;

template<typename T>
typedef struct TreeNode{
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    T data;
} BinTreeNode;

template<typename T>
class BinTree{
private:
    TreeNode<T> root;

};

#endif // PBY_TREE

