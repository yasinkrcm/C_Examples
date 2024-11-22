#include <stdlib.h>
#include <stdio.h>

struct node{
    int data ;
    struct node *next;
}*head;

void print();
void addHead();
void addLast();


// Başa ve sona eleman eklemek
int main(){
    int key , key2;
    // Linked List oluşturma 
    struct node *head = (struct node*)malloc(sizeof(struct node));

    head -> data = 5;
    head -> next = NULL;

    printf("Başa eklemek istediğiniz sayı : ");
    scanf("%d",&key);

    addHead(&head,key);

    printf("Sona eklemek istediğiniz sayı : ");
    scanf("%d",&key2);

    addLast(head,key2);
    
    print(head);
    return 0;
}


void print(struct node *head){
    struct node *temp = head;;
    
    if (head == NULL){
        printf("List is empty");
        return;
    }

    printf("\n Linked List :\n");

    while (temp != NULL){
        printf("%p adresindeki düğümün verisi %d\n", temp, temp->data);
        temp = temp -> next;
    }
    
}
    
void addHead(struct node **head, int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return ; 
    }

    temp -> data = key;
    temp -> next = *head;
    *head = temp;  
}


void addLast(struct node *head,int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = key ;
    temp -> next = NULL;

    struct node *temp2 = head;

    while (temp2 -> next != NULL)
        temp2 = temp2 -> next;
    temp2 -> next = temp;
    
}
