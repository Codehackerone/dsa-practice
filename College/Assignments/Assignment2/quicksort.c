//program to perform quick sort
#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *arr, int n);

int main()
{
    int n, min_index, temp;   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    quick_sort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)printf("%d ", arr[i]); 
    return 0;
}

void quick_sort(int *arr, int n)
{
    if (n <= 1)return;
    int temp;
    int pivot = arr[0];
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (arr[i] <= pivot && i < j)i++;
        while (arr[j] > pivot)j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[0] = arr[j];
    arr[j] = pivot;
    quick_sort(arr, j);
    quick_sort(arr + j + 1, n - j - 1);
}