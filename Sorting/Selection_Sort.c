/******************************************************************************
This code is for Selection Sort Algorithm in C
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
void selection_sort(int arr[], int size_of_arr){
    int i, j, min_idx;
    for(i = 0 ; i < size_of_arr - 1 ; i++){
        min_idx = i;
        for(j = i + 1 ; j < size_of_arr ; j++){
            if(arr[j] < arr[min_idx])
                min_idx = j ;
            if(min_idx != i)
                swap(&arr[min_idx],&arr[i]);
                
            
        }
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
    
    selection_sort(test_case, size_of_arr);
    
    
    printf("\nSorted Array: \t\t ");
    print_array(test_case, size_of_arr);
    return 0;
}

/*
EXPECTED OUTPUT
Original Unsorted Array: 21 51 54 48 54 24 15 85 46 74 73 
Sorted Array:            15 21 24 46 48 51 54 54 73 74 85
*/
