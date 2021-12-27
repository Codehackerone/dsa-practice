#include<iostream>
using namespace std;

template<typename T>
class BTNode{
    public:
        T data;
        BTNode* left;
        BTNode* right;

        BTNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BTNode(){
            delete left;
            delete right;
        }
};

int main(){

    BTNode<int>* root = new BTNode<int>(1);
    BTNode<int>* leftC = new BTNode<int>(1);
    BTNode<int>* rightC = new BTNode<int>(1);

    root->left = leftC;
    root->right = rightC;

    delete root;

    return 0;
}