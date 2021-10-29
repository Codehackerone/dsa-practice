/* Stack implementation using linked lists */
#include <stdio.h>
#include <stdlib.h>

struct link{
    int data;
    struct link *next;
} *start;

void display(struct link*);
struct link *push(struct link*);
struct link *pop(struct link*);

int main_menu();

void display(struct link* start)
{    
    while(start != NULL)
    {
        printf("%d\n", start->data);
        start = start->next;
    }
}

struct link *push(struct link* start)
{
    struct link *temp;
    temp = (struct link*)malloc(sizeof(struct link));
    printf("Enter the data to be pushed\n");
    scanf("%d", &temp->data);
    temp->next = start;
    return temp;    
}

struct link *pop(struct link* start)
{
    struct link *temp;
    
    if(start == NULL)
    {
        printf("Stack is empty\n");        
    }
    else
    {
        temp = start->next;
        free(start);
        start = temp;
        printf("Element deleted.\nNew Stack\n");
        display(start);
        if(start == NULL)
        {
            printf("Stack is empty\n");
        }
    }
    return start;
}

int main_menu(){
    int choice;
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    return choice;
}

int main(){
    struct link *start;
    int choice;
    start = NULL;
    do{
        choice = main_menu();
        switch(choice){
            case 1:
                start = push(start);
                break;
            case 2:
                start = pop(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);
}