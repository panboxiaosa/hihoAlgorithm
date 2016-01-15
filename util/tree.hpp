#ifndef PBY_TREE
#define PBY_TREE
#include <iostream>

using namespace std;

template<typename T>
struct TreeNode{
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    T data;
};


template<typename T>
class BinTree{
private:
    TreeNode<T>* root;

public:
    BinTree(){
        root = 0;
    }

    ~BinTree(){
        release(root);
    }

    void addNode(const T& value){
        TreeNode<T>* node = new TreeNode<T>();
        node->data = T;

    }

};

#endif // PBY_TREE

