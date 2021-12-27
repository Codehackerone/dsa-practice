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

void printRecursive(BTNode<int>* root){
    if(root == nullptr)return;
    cout<<root->data<<":";
    if(root->left != nullptr)cout<<root->left->data<<" ";
    if(root->right != nullptr)cout<<root->right->data<<" ";
    cout<<endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

int main(){

    BTNode<int>* root = new BTNode<int>(1);
    BTNode<int>* leftC = new BTNode<int>(5);
    BTNode<int>* rightC = new BTNode<int>(7);

    root->left = leftC;
    root->right = rightC;

    printRecursive(root);

    delete root;

    return 0;
}