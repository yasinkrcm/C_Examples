#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

bool isPalindrome(struct Node* head) {
    struct Node* temp1 = head;
    struct Node* temp2 = NULL;
    struct Node* reverse = NULL;

    while (temp1 != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = temp1->data;
        new_node->next = reverse;
        reverse = new_node;
        temp1 = temp1->next;
    }

    temp1 = head;
    temp2 = reverse;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}

void push(struct Node** head, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    char input[100];

    printf("Bir kelime girin: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    for (int i = strlen(input) - 1; i >= 0; i--) {
        push(&head, input[i]);
    }

    printf("Tek Bağlı Liste: ");
    printList(head);
    if (isPalindrome(head))
        printf("\nListe bir palindromdur.\n");
    else
        printf("\nListe bir palindrom değildir.\n");

    return 0;
}
