#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertFront();
void displayList();
void insertLast();
void delete();


int main(){
    struct node* head = (struct node *)(malloc(sizeof (struct node )));
    int key ,key2, key3 ;
    
    printf("Listenin baş düğümündeki veri : ");
    scanf("%d",&key);

    head -> data = key;
    head -> next = head;

    printf("Listenin başına eklemek istediğiniz veri : ");
    scanf("%d",&key2);
    insertFront(key2,&head);


    printf("Listenin sonuna eklemek istediğiniz veri : ");
    scanf("%d",&key3);
    insertLast(key3,head);

    delete(5,&head);

    displayList(head);

    return 0 ;
}

void insertFront(int key2,struct node **head){
    struct node* temp = (struct node * )(malloc(sizeof(struct node)));
    if (*head == NULL){
        printf("Head boş yeni head oluşturuluyor.");
        *head = temp;
        temp->next = *head;
    }

    else{
        struct node* last = *head;

        while (last -> next != *head)
            last = last->next;

        temp -> next = *head;
        *head = temp;
        last -> next = temp;
    }
}

void displayList(struct node *head){
    if (head == NULL){
        printf("Liste Boş");
        return ;
    }
        struct node* temp = head;

        printf("Liste elemanları:\n");
    
    do {
        printf("%p adresindeki düğümün verisi %d\n", temp, temp->data);
        temp = temp->next;
    } while (temp != head);
    
}


void insertLast(int key3,struct node *head){
    if (head == NULL){
        printf("Head boş yeni head oluşturuluyor.");

        struct node* head = (struct node *)(malloc(sizeof (struct node)));

        head -> data = key3;
        head -> next = head;
    }
    else{
        struct node* temp = (struct node *)(malloc(sizeof (struct node)));
        struct node* last = head;
        
        temp -> data= key3;

        while (last -> next != head)
        {
            
            if (last->next == NULL) { // Geçersiz erişimi önlemek için.
                printf("Hata: last -> next NULL oldu.\n");
                break;
            }
            else{
            last = last->next;

            }
        }
        temp -> next = head;
        last -> next = temp;
        }
}
void delete(int key, struct node **head) {
    if (*head == NULL) {
        printf("Liste boş.\n");
        return;
    }

    struct node *temp = *head, *prev = NULL;

    // Baş düğüm siliniyor
    if (temp->data == key) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;  // Tek eleman varsa başı NULL yap
        } else {
            prev = *head;
            while (prev->next != *head) {
                prev = prev->next;
            }

            prev->next = temp->next;
            *head = temp->next;  // Baş düğümü güncelle
            free(temp);
        }
        return;
    }

    // Diğer düğümleri sil
    prev = temp;
    temp = temp->next;

    while (temp != *head) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}