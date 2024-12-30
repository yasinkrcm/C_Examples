#include <stdio.h>
#include <stdlib.h>

// Ağaç düğümü yapısı
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

// Yeni bir düğüm oluşturma fonksiyonu
BTREE *new_node(int data) {
    BTREE *p = (BTREE*)malloc(sizeof(BTREE));
    if (p == NULL) {  // malloc başarısızsa hata mesajı ver
        printf("Bellek tahsisi başarısız!\n");
        exit(1);  // Bellek hatası durumunda programı sonlandır
    }
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Ağaca veri ekleme fonksiyonu
BTREE *insert(BTREE *root, int data) {
    if (root == NULL) {
        root = new_node(data);
    } else {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

// Preorder (önceden ziyaret) gezinti fonksiyonu
void preorder(BTREE *root) {
    if (root != NULL) {
        printf("%3d ", root->data);  // Öncelikle kök
        preorder(root->left);        // Sonra sol alt ağaç
        preorder(root->right);       // Sonra sağ alt ağaç
    }
}

// Inorder (orta sırada ziyaret) gezinti fonksiyonu
void inorder(BTREE *root) {
    if (root != NULL) {
        inorder(root->left);         // İlk sol alt ağaç
        printf("%3d ", root->data);  // Sonra kök
        inorder(root->right);        // Sonra sağ alt ağaç
    }
}

// Postorder (sonra ziyaret) gezinti fonksiyonu
void postorder(BTREE *root) {
    if (root != NULL) {
        postorder(root->left);       // İlk sol alt ağaç
        postorder(root->right);      // Sonra sağ alt ağaç
        printf("%3d ", root->data);  // Son olarak kök
    }
}

// Ağaçtaki tüm düğümleri serbest bırakma fonksiyonu
void free_tree(BTREE *root) {
    if (root != NULL) {
        free_tree(root->left);  // Sol alt ağacı serbest bırak
        free_tree(root->right); // Sağ alt ağacı serbest bırak
        free(root);             // Kök düğümü serbest bırak
    }
}

int main() {
    BTREE *myroot = NULL;
    int i = 0;
    
    // Kullanıcıdan veri almak ve ağaca eklemek
    do {
        printf("\n\nAgaca veri eklemek icin sayi girin...\n sayi = ");
        scanf("%d", &i);
        if (i != -1)
            myroot = insert(myroot, i);  // Sayı -1 değilse ağaca ekle
    } while (i != -1);
    
    // Gezinti işlemleri
    printf("\nPreorder gezintisi: ");
    preorder(myroot);
    
    printf("\nInorder gezintisi: ");
    inorder(myroot);
    
    printf("\nPostorder gezintisi: ");
    postorder(myroot);
    
    // Belleği serbest bırak
    free_tree(myroot);
    
    return 0;
}
