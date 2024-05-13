/******************************************************************************
This code is for Insertion Sort Algorithm in C
This code is created by Aakash Sharma
For and as class notes of programs
Date: 13 May 2024
*******************************************************************************/
#include <stdio.h>

void insertionsort(int arr[], int size_of_arr){
    int i, key, j ; 
    for(i = 1 ; i < size_of_arr ; i++){
        key = arr[i];
        j = i - 1;
      // Compare key with each element on the left of it until an element smaller than
      // it is found.
      // For descending order, change key<array[j] to key>array[j].
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
    arr[j + 1] = key;
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
    insertionsort(test_case, size_of_arr);
    printf("\nSorted Array: \t\t ");
    print_array(test_case, size_of_arr);
    return 0;
}

 /*
 EXPECETED OUTPUT:
Original Unsorted Array: 21 51 54 48 54 24 15 85 46 74 73
Sorted Array:            15 21 24 46 48 51 54 54 73 74 85 
 */
