#include <stdio.h>
#define SIZE 10


struct DataItem {
    int key;
};

struct DataItem *hashArray[SIZE]; 

int hashCode(int key) {
    return key % SIZE;
}


void insert(struct DataItem *item) {
    int hashIndex = hashCode(item->key);
    while (hashArray[hashIndex] != NULL) { 
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}


struct DataItem *search(int key) {
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];
        ++hashIndex; 
        hashIndex %= SIZE; 
    }
    return NULL; 
}

int main() {
    // Elemanlar
    struct DataItem item1 = {10};
    struct DataItem item2 = {20};
    struct DataItem item3 = {30};
    struct DataItem item4 = {40};
    struct DataItem item5 = {50};

    insert(&item1);
    insert(&item2);
    insert(&item3);
    insert(&item4);
    insert(&item5);

    
    int keysToSearch[] = {10, 20, 50, 25, 45};

    
    for (int i = 0; i < 5; i++) {
        struct DataItem *result = search(keysToSearch[i]);
        printf("The element to be searched: %d\n", keysToSearch[i]);
        if (result != NULL)
            printf("Element found: %d\n", result->key);
        else
            printf("Element not found\n");
    }

    return 0;
}




