#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data){
            this->data = data;
        }
};

void printLevel(TreeNode<int>* root){    
    queue<TreeNode<int>*> q;
    q.push(root);    

    while(!q.empty()){        
        TreeNode<int>* f = q.front();
        q.pop();
        
        cout<<f->data<<":";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data;
            q.push(f->children[i]);
        }
        cout<<endl;
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the data"<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();

        cout<<"Enter no of children of "<<f->data<<endl;
        int n;
        cin>>n;

        for(int i=1;i<=n;i++){
            int childData ;
            cout<<"Enter "<<i<<"th of "<<f->data<<endl;
            cin>>childData;

            TreeNode<int>* childNode = new TreeNode<int>(childData);
            q.push(childNode);

            f->children.push_back(childNode);
        }
    }
    
    return root;
}

int countNodes(TreeNode<int>* root){
    int count=1;
    for(int i=0;i<root->children.size();i++){
        count += countNodes(root->children[i]);
    }
    return count;
}

int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* n1 = new TreeNode<int>(2);
    // TreeNode<int>* n2 = new TreeNode<int>(3);

    // root->children.push_back(n1);
    // root->children.push_back(n2);

    TreeNode<int>* root = takeInputLevelWise();

    printLevel(root);
    cout<<endl<<"Total Nodes: "<<countNodes(root)<<endl;

    return 0;
}