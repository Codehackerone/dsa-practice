//program to implement queue using array
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front=-1,rear=-1;
int queue[MAX];
void enqueue(int);
int dequeue();
void display();

void main()
{
    int choice,item;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted:");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                item=dequeue();
                if(item!=-1)
                    printf("Deleted element is %d\n",item);
                else
                    printf("Queue is empty\n");
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void enqueue(int item)
{
    if(rear==MAX-1)
        printf("Queue is full\n");
    else
    {
        if(front==-1)
            front=0;    
        rear++;
        queue[rear]=item;
    }
}

int dequeue()
{
    int item;
    if(front==-1)
        return -1;
    else
    {
        item=queue[front];
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
        return item;
    }
}

void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements are:\n");
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}