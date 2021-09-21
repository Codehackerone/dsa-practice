#include<stdio.h>

int deletion(char *, int, int);
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
    fflush(stdin);
    printf("Enter the position where you want to delete the element:");
    scanf("%d", &p);
    n = deletion(a, n, p);
    printf("The array after deletion is: ");
    display(a, n);
}