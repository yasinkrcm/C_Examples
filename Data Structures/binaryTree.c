#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

void printPreOrder(struct Node * root){
    if (root == NULL)
        return;
    printf("%d ",root -> data);
    printPreOrder(root->left);
    printPreOrder(root->right);


}   

// Function to print inorder traversal
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    printf("%d ", node->data);

    // Then recur on right subtree
    printInorder(node->right);
}

void printPostOrder(struct Node *root){
    if(root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ",root->data);
}

// Function to create a new node
struct Node* newNode(int v) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = v;
    node->left = node->right = NULL;
    return node;
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // Function call
    printf("PreOrder traversal of binary tree is: \n");
    printPreOrder(root);
    printf("\n\n");

    printf("Inorder traversal of binary tree is: \n");
    printInorder(root);
    printf("\n\n");
    
    printf("PreOrder traversal of binary tree is: \n");
    printPostOrder(root);

    return 0;
}