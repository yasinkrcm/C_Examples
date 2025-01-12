#include <stdio.h>
#include <stdlib.h>

// AVL ağacı düğümü
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Yükseklik hesaplama
int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}

// Maksimum değeri bulma
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Yeni düğüm oluşturma
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Yeni düğümün başlangıç yüksekliği
    return node;
}

// Sağ rotasyon
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotasyon yap
    x->right = y;
    y->left = T2;

    // Yükseklikleri güncelle
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Sol rotasyon
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotasyon yap
    y->left = x;
    x->right = T2;

    // Yükseklikleri güncelle
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Balans faktörü hesaplama
int getBalance(Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

// AVL ağacına düğüm ekleme
Node* insert(Node* node, int data) {
    // 1. Adım: Yeni düğüm ekle
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // Aynı değeri eklemeye çalışmıyoruz

    // 2. Adım: Düğümün yüksekliğini güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Adım: Dengeyi kontrol et
    int balance = getBalance(node);

    // Dengeyi sağlamak için uygun rotasyonları yap

    // Sol-Sol durumu
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Sağ-Sağ durumu
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Sol-Sağ durumu
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Sağ-Sol durumu
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Pre-order dolaşımı
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Sol-Sağ örneği
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("Pre-order traversal after inserting 10, 30, 20:\n");
    preOrder(root);

    printf("\n\n");

    // Sağ-Sol örneği
    root = NULL;
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);

    printf("Pre-order traversal after inserting 30, 10, 20:\n");
    preOrder(root);

    return 0;
}