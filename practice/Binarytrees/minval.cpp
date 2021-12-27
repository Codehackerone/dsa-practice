#include<iostream>
#include<queue>
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
    if(root->left != nullptr)cout<<"L "<<root->left->data<<"  ";
    if(root->right != nullptr)cout<<"R "<<root->right->data<<"  ";
    cout<<endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

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

BTNode<int>* inputLevelWise(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BTNode<int>* f = q.front();
        q.pop();

        int leftC, rightC;
        cout<<"Enter data for left of "<<f->data<<":"<<endl;
        cin>>leftC;
        cout<<"Enter data for right of "<<f->data<<":"<<endl;
        cin>>rightC;

        if(leftC!=-1){
            BTNode<int>* child = new BTNode<int>(leftC);
            q.push(child);
            f->left=child;
        }
        if(rightC!=-1){
            BTNode<int>* child = new BTNode<int>(rightC);
            q.push(child);
            f->right=child;
        }
    }

    return root;
}

int minValue(BTNode<int>* root){
    if(root==NULL)return INT_MAX;
    int ans = root->data;
    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);
    return min(min(leftMin, rightMin), ans);
}


int main(){

    // BTNode<int>* root = new BTNode<int>(1);
    // BTNode<int>* leftC = new BTNode<int>(5);
    // BTNode<int>* rightC = new BTNode<int>(7);

    // root->left = leftC;
    // root->right = rightC;

    // BTNode<int>* root = inputRecursive();
    BTNode<int>* root = inputLevelWise();

    // printRecursive(root);
    // printLevelWise(root);

    cout<<"Min val"<<minValue(root)<<endl;

    delete root;

    return 0;
}