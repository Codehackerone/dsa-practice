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

BTNode<int>* inputRecursive(){
    int rootData;
    cout<<"Enter data (-1 for termination):"<<endl;
    cin>>rootData;
    if(rootData == -1)return nullptr;
    BTNode<int>* root = new BTNode<int>(rootData);
    BTNode<int>* leftC = inputRecursive();
    BTNode<int>* rightC = inputRecursive();
    root->left = leftC;
    root->right = rightC;
    return root;
}

int countNodes(BTNode<int>* root){
    if(root==nullptr)return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool findNode(BTNode<int>* root, int key);
{
    if(!root)return false;
    if(root->data == ley)return true;

    return(findNode(root->left, key) || findNode(root->right, key));
}

int main(){

    // BTNode<int>* root = new BTNode<int>(1);
    // BTNode<int>* leftC = new BTNode<int>(5);
    // BTNode<int>* rightC = new BTNode<int>(7);

    // root->left = leftC;
    // root->right = rightC;

    BTNode<int>* root = inputRecursive();

    printRecursive(root);

    // cout<<endl<<"No of nodes:"<<countNodes(root)<<endl;
    int n;
    cout<<"Enter the node you want to find:"<<endl;
    cin>>n;

    if(findNode(n))cout<<"Found"<<endl;
    else cout<<"Not found"<<endl;
    
    delete root;
    return 0;
}