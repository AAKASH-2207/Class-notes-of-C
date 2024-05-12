/******************************************************************************

Code for binary search algorithm in c

This code is created by Aakash Sharma
For and as class notes of programs

Date: 12 May 2024


*******************************************************************************/
#include <stdio.h>
 int binary_search(int arr[], int low ,int length_of_array, int num){
    while(low <= length_of_array){
        int mid = low + (length_of_array - low) / 2 ;
        
        if(arr[mid] == num)
            return mid;    /*condition where the element is found*/
        
        if(arr[mid] < num)
            low = mid + 1 ; /*condition where the element is greater than the mid i.e on the right*/
            
        if(arr[mid] > num)
            length_of_array = mid - 1 ; /*condition where the element is lesser than the mid i.e on the left*/
    }
    return -1;
}
int main()
{
    /* for the test case we need a sorted array because binary search only works on sorted arrays*/
    int test_array[] = {12,15,23,34,46,62,65};
    int test_element = 46;
    int length_of_array = sizeof(test_array)/sizeof(test_array[0]);
    int output = binary_search(test_array,0 , length_of_array, test_element);
    if(output != -1){
        printf("the element is present at postion: %d",output);
    }else{
        printf("the element is not present");
    }
    return 0;
}

/*
EXPECTED OUTPUT
the element is present at postion: 4
*/
