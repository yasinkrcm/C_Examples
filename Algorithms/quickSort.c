#include <stdio.h>

void quickSort(int arr [], int altindis , int ustindis){
    int i = altindis;
    int j = ustindis;
    int x = arr[(altindis + ustindis) / 2 ];

    while (i <= j)
    {
        while (arr[i]<x)
            i++;
        while (arr[j] > x)
            j--;
        if (i <= j){
            int temp = arr[i] ;
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    if (altindis < j)
        quickSort(arr,altindis,j);
    if (i < ustindis)
        quickSort(arr,i,ustindis);
    }
    
}


void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int arr[] = {12, 34, 7, 9, 5, 19, 23, 2, 11, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, length);

    quickSort(arr, 0, length - 1);

    printf("Sorted array: ");
    printArray(arr, length);

    return 0;
}
