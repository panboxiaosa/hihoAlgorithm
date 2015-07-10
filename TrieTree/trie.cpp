#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct treeNode{
    char from;
    int contain;
    list<struct treeNode*> childs;
};

class Trie{
private:
    treeNode* root;
    treeNode* toNext(struct treeNode* pre, char through){
        list<struct treeNode*>::iterator it = pre->childs.begin();
        while(it != pre->childs.end()){
            if((*it)->from == through)
                return *it;
            it++;
        }
        struct treeNode* added = new treeNode();
        added->from = through;
        added->contain = 0;
        pre->childs.push_back(added);
        return added;
    }
    treeNode* findNext(treeNode* pre, char through){
        list<treeNode*>::iterator it = pre->childs.begin();
        while(it != pre->childs.end()){
            if((*it)->from == through)
                return *it;
            it++;
        }
        return NULL;
    }
    void release(treeNode* root){
        list<treeNode*>::iterator it = root->childs.begin();
        while(it != root->childs.end()){
            release(*it);
            it++;
        }
        delete root;
    }

public:
    Trie(){
        root = new treeNode();
        root->contain = 0;
        root->from = 0;
    }

    void add(string word){
        treeNode* current = root;
        for(int i = 0; i < word.length(); i++){
            current = toNext(current, word.at(i));
            (current->contain)++;
        }
    }

    int result(string word){
        treeNode* current = root;
        for(int i = 0; i < word.length(); i++){
            current = findNext(current, word.at(i));
            if(current == NULL)
                return 0;
        }
        return current->contain;
    }

    ~Trie(){
        release(root);
    }

};

int main()
{
    int dics;
    cin>>dics;
    stack<string> all;
    Trie tree;
    for(int i = 0; i < dics; i++){
        string str;
        cin>>str;
        all.push(str);
    }
    while(!all.empty()){
        tree.add(all.top());
        all.pop();
    }
    int toQuery;
    cin>>toQuery;
    vector<int> result;
    for(int i = 0; i < toQuery; i++){
        string str;
        cin>>str;
        result.push_back(tree.result(str));
    }
    for(int i = 0; i < result.size(); i++)
        cout<<result.at(i)<<endl;
    return 0;
}
