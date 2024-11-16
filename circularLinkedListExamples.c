#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertFront();
void displayList();
void insertLast();

int main(){
    struct node* head = (struct node *)(malloc(sizeof (struct node )));
    int key ,key2, key3 ;
    
    printf("Listenin baş düğümündeki veri : ");
    scanf("%d",&key);

    head -> data = key ;
    head -> next = head;

    printf("Listenin başına eklemek istediğiniz veri : ");
    scanf("%d",&key2);


    printf("Listenin sonuna eklemek istediğiniz veri : ");
    scanf("%d",&key3);

    insertFront(key,head);
    insertLast(key3,head);
    displayList(head);

    return 0 ;
}

void insertFront(int key2,struct node* head){
    if (head == NULL){
        printf("Head boş yeni head oluşturuluyor.");
        struct node* head = (struct node *)(malloc(sizeof (struct node )));
        head -> data = key2;
        head -> next = head;
    }

    else{
        struct node* temp = (struct node * )(malloc(sizeof(struct node)));
        struct node *last = head;

        temp -> data = key2;

        while (last->next!=head)
        {
            last = last->next;
        }
        temp -> next = head;
        last -> next = temp;
        head = temp ;
    }
}

void displayList(struct node* head){
    if (head == NULL)
        printf("Liste Boş");
    else{
        struct node* temp;
        head = temp;
        while (temp -> next != head)
        {
            printf("%d adresindeki düğümün verisi %d\n",temp,temp -> data);
            temp = temp -> next ; 

        }
        
    }
}

void insertLast(int key3,struct node *head ){
    if (head == NULL){
        printf("Head boş yeni head oluşturuluyor.");

        struct node* head = (struct node *)(malloc(sizeof (struct node)));

        head -> data = key3;
        head -> next = head;
    }
    else{
        struct node* temp = (struct node *)(malloc(sizeof (struct node)));
        struct node* last;
        
        temp->data= key3;

        while (last->next!=head)
        {
            last = last->next;
        }
        
        temp -> next = head;
        last ->next=temp;

    }
}