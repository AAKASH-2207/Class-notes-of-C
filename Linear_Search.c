/******************************************************************************
This code is created by Aakash Sharma
For and as class notes of programs
Date: 12 May 2024
*******************************************************************************/
#include <stdio.h>
 int linear_search(int arr[], int num,int length_of_array){
    for(int i = 0 ; i < length_of_array ; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1; 
}
int main()
{
    int test_array[] = {12,15,62,46,23,34,65,34};
    int test_element = 46;
    int length_of_array = sizeof(test_array)/sizeof(test_array[0]);
    int output = linear_search(test_array, test_element, length_of_array);
    if(output != -1){
        printf("the element is present at postion: %d",output);
    }else{
        printf("the element is not present");
    }
    return 0;
}

/* 
EXPECTED OUTPUT
the element is present at postion: 3 
*/
