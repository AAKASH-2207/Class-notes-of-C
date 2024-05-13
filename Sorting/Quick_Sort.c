/******************************************************************************
This code is for Bubble Sort Algorithm in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 13 May 2024
*******************************************************************************/
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1 ;
    for(int j = low ; j <= high ; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1],&arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

void print_array(int arr[], int num){
    for(int i = 0 ; i < num ; i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int test_case[] = {21,51,54,48,54,24,15,85,46,74,73};
    int size_of_arr = sizeof(test_case)/sizeof(test_case[0]);
    printf("Original Unsorted Array: ");
    print_array(test_case, size_of_arr);
    quicksort(test_case, 0, size_of_arr - 1);
    printf("\nSorted Array: \t\t ");
    print_array(test_case, size_of_arr);
    return 0;
}

/*
 EXPECETED OUTPUT:
Original Unsorted Array: 21 51 54 48 54 24 15 85 46 74 73
Sorted Array:            15 21 24 46 48 51 54 54 73 74 85 
 */
