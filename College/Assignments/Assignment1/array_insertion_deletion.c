#include<stdio.h>

int deletion(char *, int, int);
int insertion(char *, int, int, char);
void input(char *, int);
void display(char *, int);

int deletion(char *a, int n, int p)
{
    int temp = p;
    while(temp <= n - 1){
        a[temp] = a[temp+1];
        temp++;        
    }
    n--;
    return n;    
}

int insertion(char *a, int n, int p, char e)
{
    int temp = n;
    while(temp >= p){
        a[temp + 1] = a[temp];
        temp--;        
    }
    a[p] = e;
    n++;
    return n;    
}

void input(char *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter element %d: ", (i+1));
        scanf("%c", &a[i]);
    }
}

void display(char *a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%c ", a[i]);
    }
}

int main()
{
    int n, p;
    char e;
    char a[100];
    fflush(stdin);
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    input(a, n);
    printf("The array is: ");
    display(a, n);
    printf("\n");    
    int ch;
    do{        
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the position where you want to enter the element:");
                scanf("%d", &p);
                fflush(stdin);
                printf("Enter the element to be inserted: ");
                scanf("%c", &e);
                n = insertion(a, n, p, e);
                printf("The array after insertion is: ");
                display(a, n);
                break;
            case 2:
                printf("Enter the position where you want to delete the element:");
                scanf("%d", &p);
                n = deletion(a, n, p);
                printf("The array after deletion is: ");
                display(a, n);
                break;
            case 3:
                printf("The array is: ");
                display(a, n);                
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }        
    }while(ch != 4);    
}