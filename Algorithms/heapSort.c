#include <stdio.h>
void heapify(int[], int);

void build_maxheap(int heap[], int n){
    int i, j, c, r, t;

    for (i = 1; i < n; i++) {
        c = i;
        do {
            r = (c - 1) / 2;
            if (heap[r] < heap[c]) { // to create MAX heap array
                t = heap[r];
                heap[r] = heap[c];
                heap[c] = t;
            }
            c = r;
        } while (c != 0);
    }

    printf("Heap array: ");

    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    heapify(heap, n);
}

void heapify(int heap[], int n){
    int i, j, c, root, temp;

    for (j = n - 1; j >= 0; j--) {
        temp = heap[0];
        heap[0] = heap[j]; // swap max element with rightmost leaf element
        heap[j] = temp;
        root = 0;

        do {
            c = 2 * root + 1; // left node of root element
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j) { // again rearrange to max heap array
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }   
            root = c;
            } while (c < j);
    }
    printf("\nThe sorted array is: ");

    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);
}

int main(){
    int n = 5;


    int heap[10] = {2, 3, 1, 0, 4}; // initialize the array
    
    build_maxheap(heap, n);
    
    printf("\n");
}