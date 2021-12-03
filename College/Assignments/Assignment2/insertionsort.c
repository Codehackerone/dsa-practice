//program to perform insertion sort
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *arr, int n);

int main()
{
    int n, min_index, temp;   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    insertion_sort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)printf("%d ", arr[i]); 
    return 0;
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}