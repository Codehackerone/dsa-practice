#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10000 // Size of array

int top = -1;// Stack top
int flag = 0;// To check if operations are successful
int stack[SIZE];// Array to store the stack

void push(int *, int data);
int pop(int *);
int peep(int *);
int update(int *);
void display(int *);

// Function to push an element in stack
void push(int s[], int data){
    if(top == SIZE - 1){
        flag = 0;
    }
    else{
        ++top;
        s[top] = data;
        flag = 1;
    }
}

// Function to pop an element from stack
int pop(int s[]){
    int popped_element;
    if(top == -1){
        popped_element = 0;
        flag = 0;
    }
    else{
        popped_element = s[top];
        flag = 1;
        --top;
    }
    return popped_element;
}

//Function to peep an element from stack
int peep(int s[]){
    int i;
    int peeped_element;
    printf("\nEnter the index of element to peep: ");
    scanf("%d", &i);

    if(top + 1 - i < 0){
        peeped_element = 0;
        flag = 0;
    }
    else{
        peeped_element = s[top + 1 - i];
        flag = 1;
    }
    return peeped_element;
}

// Function to update an element in stack
int update(int s[]){
    int i;
    int updated_element;
    printf("\nEnter the index of element to update: ");
    scanf("%d", &i);

    if(top + 1 - i < 0){
        updated_element = 0;
        flag = 0;
    }
    else{
        updated_element = s[top + 1 - i];
        flag = 1;
        printf("\nEnter the updated element: ");
        scanf("%d", &s[top + 1 - i]);
    }
    return updated_element;
}

// Function to display the stack
void display(int s[]){
    int i;
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is: ");
        for(i = 0; i <= top; ++i){
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

// Driver code
int main(){
    int data;
    int choice;
    int q = 0;
    int top = -1;

    do{
        printf("\n\n1. Push\n2. Pop\n3. Peep\n4. Update\n5. Display\n6. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(stack, data);
                if(flag){
                    printf("Element pushed successfully\nThe stack is\n");
                    display(stack);
                    if(top == SIZE - 1){
                        printf("\nStack is full\n");
                    }                    
                }    
                else{
                    printf("\nStackOverflow. Stack is full.\n");
                }
                break;
            case 2:
                data = pop(stack);
                if(flag){            
                    printf("Element popped successfully\nThe stack is\n");
                    display(stack);
                }
                else{
                    printf("\nStack underflow. Stack is empty\n");                    
                }
                break;
            case 3:
                data=peep(stack);
                if(flag){
                    printf("Element %d peeked successfully\nThe stack is\n",data);
                    display(stack);
                }
                else{
                    printf("\nStack underflow. Stack is empty\n");
                }
                break;
            case 4:
                data=update(stack);
                if(flag){
                    printf("Element %d updated successfully\nThe stack is\n",data);
                    display(stack);
                }
                else{
                    printf("\nStack underflow. Stack is empty\n");
                }
                break;                
            case 5:
                display(stack);
                break;
            case 6:
                q = 1;
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }while(!q);
}