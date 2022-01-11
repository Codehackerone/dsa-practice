#include<iostream>
#include<pair>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

pair<bool, Node*> detectCycle(Node* head){
    if(head || !head->next)return false;
    Node *f=head, *s=head, *c=head, *t;

    while(s->next && f->next->next){
        if(s == f){
            t = s;
            return true;            
        }
        s=s->next;
        f=f->next->next;
    }

    return false;
}