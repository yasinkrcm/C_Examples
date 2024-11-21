#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void generateRandomArray(int arr[]) {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void printArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[SIZE], arr2[SIZE];
    
    generateRandomArray(arr1);
    for (int i = 0; i < SIZE; i++) arr2[i] = arr1[i];

    printf("Original array:\n");
    printArray(arr1);

    clock_t start, end;

    // QuickSort
    start = clock();
    quickSort(arr1, 0, SIZE - 1);
    end = clock();
    printf("\nQuickSort sorted array:\n");
    printArray(arr1);
    printf("\nQuickSort execution time: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // MergeSort
    start = clock();
    mergeSort(arr2, 0, SIZE - 1);
    end = clock();
    printf("\nMergeSort sorted array:\n");
    printArray(arr2);
    printf("\nMergeSort execution time: %.6f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}