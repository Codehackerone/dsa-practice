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

class BST{
    BTNode<int>* root;
    
    void printLevelWise(BTNode<int>* root){        
        queue<BTNode<int>*> q;
        q.push(root);    
        q.push(nullptr);

        cout<<root->data<<endl;

        while(!q.empty()){
            BTNode<int>* f = q.front();
            q.pop();        
            
            if(f->left!=nullptr){
                cout<<f->left->data;
                q.push(f->left);            
            }        
            if(f->right!=nullptr){
                cout<<f->right->data;
                q.push(f->right);            
            }        

            if(f == nullptr && !q.empty()){
                cout<<endl;
                q.push(nullptr);
            }        
        }
    }

    public:
        BST(){
            root = nullptr;
        }
        ~BST(){
            delete root;            
        }

        void deleteData(int data){

        }

        void insertData(int data){

        }

        bool hasData(int data){
            if(root == nullptr)return false;
            if(root->data == data)return true;
            if(root->data > data)return hasData(root->left, data);
            if(root->data < data)return hasData(root->right, data);
            return false;
        }

        void print(){
            printLevelWise(root);
        }
}
