#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int liste[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        liste[i] = rand() % 1501;
    }
}

void printArray(int liste[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", liste[i]);
    }
    printf("\n");
}

void countSort(int a[], int n, int pos) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / pos) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / pos) % 10] - 1] = a[i];
        count[(a[i] / pos) % 10]--;
    }
    for (int i = 0; i < n; i++) a[i] = output[i];
}

void RadixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];
    for (int pos = 1; max / pos > 0; pos *= 10) countSort(a, n, pos);
}

int main() {
    int n = 15, liste[n];
    generateRandomArray(liste, n);
    printArray(liste, n);
    RadixSort(liste, n);
    printArray(liste, n);
    return 0;
}
