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

void postorderTraversal(TreeNode<int>* root){
    if(root==nullptr)return;    
    for(int i=0;i<root->children.size();i++){
        postorderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
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

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* n1 = new TreeNode<int>(2);
    // TreeNode<int>* n2 = new TreeNode<int>(3);

    // root->children.push_back(n1);
    // root->children.push_back(n2);

    TreeNode<int>* root = takeInputLevelWise();
    cout<<endl;
    postorderTraversal(root);
    return 0;
}