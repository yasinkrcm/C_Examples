#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

bool isDoublyPalindrome(struct Node* head) {
    struct Node* start = head;
    struct Node* end = head;

    while (end->next != NULL) {
        end = end->next;
    }

    while (start != end && end->next != start) {
        if (start->data != end->data)
            return false;
        start = start->next;
        end = end->prev;
    }

    return true;
}

void push(struct Node** head, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
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

    printf("Çift Bağlı Liste: ");
    printList(head);
    if (isDoublyPalindrome(head))
        printf("\nListe bir palindromdur.\n");
    else
        printf("\nListe bir palindrom değildir.\n");

    return 0;
}
