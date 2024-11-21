#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int size;
    size = 5;
    int arr[] = {1, 2, 3, 10, 20}; 
    int target = 10;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Eleman bulundu: Eleman : %d  Dizin %d\n",target, result);
    } else {
        printf("Eleman bulunamadı\n");
    }

    return 0;
}
