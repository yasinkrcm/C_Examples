#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Hash tablosunun boyutu

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

void delete(int key) {
    int hashIndex = hashCode(key);  // Anahtar için hash indeksi hesaplanır

    // Çakışma çözümü (Lineer probing)
    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->key == key) {
            // Anahtar bulunduysa silinir
            free(hashArray[hashIndex]);
            hashArray[hashIndex] = NULL;
            printf("Key %d deleted\n", key);
            return;
        }
        hashIndex++;
        hashIndex %= SIZE;  // Tabloda döngüye girerek sarmalayıp, devam et
    }

    printf("Key %d not found\n", key);  // Anahtar bulunamadı
}

void displayTable(const char *message) {
    printf("%s\n", message);
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("Index %d: Key %d\n", i, hashArray[i]->key);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
    printf("\n");
}

int main() {
    // Tabloyu başta NULL ile başlatıyoruz
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }

    // 5 anahtar ekliyoruz
    insert(15);  // 15 % 5 = 0
    insert(20);  // 20 % 5 = 0 (çakışma olacak)
    insert(25);  // 25 % 5 = 0 (çakışma olacak)
    insert(30);  // 30 % 5 = 0 (çakışma olacak)
    insert(35);  // 35 % 5 = 0 (çakışma olacak)

    // Tabloyu ilk ekleme işleminden sonra kaydediyoruz
    displayTable("Hash Table after insertions:");

    // Silme işlemi ve her adımda tabloyu kaydetme
    delete(25);  // 25 anahtarını siliyoruz
    displayTable("Hash Table after deleting 25:");

    delete(35);  // 35 anahtarını siliyoruz
    displayTable("Hash Table after deleting 35:");

    delete(100); // 100 anahtarını siliyoruz (bulunamadı)
    displayTable("Hash Table after trying to delete 100:");

    delete(15);  // 15 anahtarını siliyoruz
    displayTable("Hash Table after deleting 15:");

    delete(30);  // 30 anahtarını siliyoruz
    displayTable("Hash Table after deleting 30:");

    return 0;
}
