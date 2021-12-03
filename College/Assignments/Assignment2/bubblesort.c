//program to perform bubble sort
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n);

int main(){
    int n, min_index, temp;   
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
    bubble_sort(arr, n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)printf("%d ", arr[i]); 
    return 0;
}

void bubble_sort(int *arr, int n){
    int min_index, temp;
    for (int i = 0; i < n-1; i++){
        min_index = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_index])min_index = j;
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}