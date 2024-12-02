#include <stdio.h>

int binarySearch(int arr [], int size, int target){
    int low , high , mid;
    low = 0;
    high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }
    return -1 ;
} 

int main() {
    int arr[] = {1, 3, 6, 7, 8, 9, 11}; 
    int size = sizeof(arr) / sizeof(arr[0]);  
    int target = 6;
    
    int result = binarySearch(arr, size, target);  
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } 
        else {
        printf("Element not found\n");  
    }
    
    return 0;
}