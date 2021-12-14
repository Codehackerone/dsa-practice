#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

typedef struct Node BTNode;

struct BTNode* takeInput(){
    int rootData;
    printf("Enter data");
    scanf("%d",&rootData);

    if(rootData==-1)return NULL;

    BTNode* root = new BTNode(rootData);
    BTNode* leftChild = takeInput();
    BTNode* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void printTree(BTNode* root){
    if(root==NULL)return;

    printf("%d ",root->data);

    if(root->left!=NULL)printf("L:%d ",root->left->data);

    if(root->right!=NULL)printf("R:%d ",root->right->data);
    
    printf("\n");

    printTree(root->left);
    printTree(root->right);
}

int main(){
    BTNode* root = takeInput();
    printTree(root);
    
    return 0;
}