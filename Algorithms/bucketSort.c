#include <stdio.h>
#include <stdlib.h>
#define BUCKETS 10
#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j;
    int buckets[BUCKETS][MAX];
    int count[BUCKETS] = {0};

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKETS;
        buckets[bucketIndex][count[bucketIndex]++] = arr[i];
    }

    for (i = 0; i < BUCKETS; i++) {
        for (j = 0; j < count[i] - 1; j++) {
            for (int k = 0; k < count[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }
    int index = 0;
    for (i = 0; i < BUCKETS; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 84, 64, 65, 94, 46, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Orijinal Dizi: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sıralı Dizi: \n");
    printArray(arr, n);

    return 0;
}