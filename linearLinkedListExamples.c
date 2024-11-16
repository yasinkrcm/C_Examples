#include <stdlib.h>
#include <stdio.h>

struct node{
    int data ;
    struct node *next;
}*head;


void print(struct node *head){
    struct node *temp;
    
    if (head == NULL)
        printf("List is empty");
    
    else {
        temp = head;
        printf("\n Linked List :");
        while (temp != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
    }
    
}
    
struct node *addHead(struct node *head, int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return head; 
    }

    temp->data = key;
    temp->next = head;
    head = temp;
    return head;  
}


struct node *addLast(struct node *head,int key){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = key ;
    temp -> next = NULL;

    struct node *temp2 = head;

    while (temp2 -> next != NULL)
        temp2 = temp2 -> next;
    temp2 -> next = temp;
    return head;
}


// Başa ve sona eleman eklemek
int main(){
    int key;
    int key2;
    // Linked List oluşturma 
    struct node *head = (struct node*)malloc(sizeof(struct node));

    head -> data = 5;
    head -> next = NULL;

    printf("Başa eklemek istediğiniz sayı : ");
    scanf("%d",&key);

    head = addHead(head,key);

    printf("Sona eklemek istediğiniz sayı : ");
    scanf("%d",&key2);

    head = addLast(head,key);
    
    print(head);
    return 0;
}
