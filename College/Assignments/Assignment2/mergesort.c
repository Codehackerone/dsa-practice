//program to perform merge sort
#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *arr, int n);

int main()
{
    int n, min_index, temp;   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    merge_sort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)printf("%d ", arr[i]); 
    return 0;
}

void merge_sort(int *arr, int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((n - mid) * sizeof(int));
        for (int i = 0; i < mid; i++)left[i] = arr[i];
        for (int i = mid; i < n; i++)right[i - mid] = arr[i];

        //recursively sort the left and right halves
        merge_sort(left, mid);
        merge_sort(right, n - mid);

        //three subarrays are sorted now merge them
        int i = 0, j = 0, k = 0;        
        //merge the left and right subarrays
        while (i < mid && j < n - mid)
        {
            if (left[i] < right[j])arr[k++] = left[i++];//left[i] is smaller than right[j]
            else arr[k++] = right[j++];//right[j] is smaller than left[i]            
        }
        // copy the remaining elements of left
        while (i < mid)arr[k++] = left[i++];
        // copy the remaining elements of right
        while (j < n - mid)arr[k++] = right[j++];
        free(left);
        free(right);
    }
}