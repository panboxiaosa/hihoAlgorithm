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
    void release(TreeNode* node){
        if(node == 0)
            return;
        release(node->leftChild);
        release(node->rightChild);
        delete node;
        node = 0;
    }

    void add(TreeNode* element, TreeNode* target){
        if(target->leftChild == 0)
            target->leftChild = element;
        else if(target->rightChild == 0)
            target->rightChild = element;
        else
    }

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

