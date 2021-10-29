#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *tail=NULL;
int size=0;

void addFirst(int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=head;
    head=temp;
    if(size==0){
        tail=temp;
    }
    size++;    
    printf("Element inserted at first of linkedlist\n");
}

void addLast(int val){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    if(size==0){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    size++;    
    printf("Element inserted at the end of the linkedlist\n");
}

void addAtIndex(int val,int pos){
    if(pos==0){
        addFirst(val);
    }
    else if(pos==size){
        addLast(val);
    }
    else{
        struct Node *temp =(struct Node *)malloc(sizeof(struct Node));
        temp->data=val;
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t=head;
        for(int i=0;i<pos-1;i++){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
        size++;
        printf("Element inserted at %d position\n",pos);
    }
}

void deleteFirst(){
    if(size==0){
        printf("List is empty\n");
        return;
    }
    else if(size==1){
        printf("Deleted element is: %d/n",head->data);
        head=NULL;
        tail=NULL;
        size--;
    }
    else{
        printf("The deleted element is: %d\n",head->data);
        head=head->next;
        size--;
    }
}

void deleteLast(){
    if(size==0){
        printf("Linkedlist is empty\n");
        return;
    }
    else if(size==1){
        printf("Element deleted is: %d\n",tail->data);
        head=NULL;
        tail=NULL;
        size--;
    }
    else{
        printf("Deleted element is: %d\n",tail->data);
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp=head;
        for(int i=0;i<size-2;i++){
            temp=temp->next;
        }
        tail=temp;
        tail->next=NULL;
        size--;
    }
}

void deleteAtIndex(int pos){
    if(pos==0){
        deleteFirst();
    }
    else if(pos==size-1){
        deleteLast();
    }
    else{
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        printf("Deleted element is: %d\n",temp->next->data);
        temp->next=temp->next->next;
        size--;
    }
}

void display(){
    if(size==0){
        printf("Linkedlist is empty\n");
    }
    else{
        struct Node*temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    printf("1.Insert element at beginning\n");
    printf("2.Insert element at end\n");
    printf("3.Insert element at desired location\n");
    printf("4.Delete element at the beginning\n");
    printf("5.Delete element at the end\n");
    printf("6.Delete element at particular location\n");
    printf("7.Display the list\n");
    printf("8.Exit\n");
    int choice,val,pos;

    do{
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter the element to be added:");
                scanf("%d",&val);
                addFirst(val);
                break;
            case 2:
                printf("Enter the element to be inserted:");
                scanf("%d",&val);
                addLast(val);
                break;            
            case 3: 
                printf("Enter the element to be inserted:");
                scanf("%d",&val);
                printf("Enter the position at which u want the element to be inserted:");
                scanf("%d",&pos);
                addAtIndex(val,pos);
                break;                    
            case 4: 
                deleteFirst();
                break;                
            case 5: 
                deleteLast();
                break;
            case 6: 
                printf("Enter the position at which u want to delete the element:");
                scanf("%d",&pos);
                deleteAtIndex(pos);
                break;
            case 7: 
                display();
                break;
            default:
                printf("Invalid choice\n");
        }   
    }while(choice!=8);
    return 0;
}