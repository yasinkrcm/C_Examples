#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5 // Hash tablosunun boyutu 5 olarak belirlendi

struct DataItem {
    int key;
};

struct DataItem *hashArray[SIZE]; // Hash tablosu

int hashCode(int key) {
    return key % SIZE;  // Anahtar için hash değeri
}

void insert(int key) {
    struct DataItem *newItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    if (newItem == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    newItem->key = key;
    int hashIndex = hashCode(key);  // Anahtar için hash indeksi hesaplanır

    // Çarpışma yönetimi (Lineer probing yöntemi)
    while (hashArray[hashIndex] != NULL) {
        hashIndex++;  // Bir sonraki indekse geç
        hashIndex %= SIZE;  // Tabloda döngüye girerek sarmalayıp, devam et
    }
    hashArray[hashIndex] = newItem;  // Yeni item'ı uygun indeksin bulunduğu pozisyona ekle
}

void displayTable() {
    printf("\nHash Table State:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("Index %d: Key %d\n", i, hashArray[i]->key);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    srand(time(NULL)); // Rastgele sayı üreteci başlatma

    // Tabloyu başta NULL ile başlatıyoruz.
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }

    // 5 rastgele anahtar ekliyoruz
    for (int i = 0; i < 5; i++) {
        int key = rand() % 100;  // 0 ile 99 arasında rastgele sayı
        printf("Inserting key: %d\n", key);
        insert(key);  // Anahtarı ekle
        displayTable();  // Tabloyu yazdır
    }

    return 0;
}
