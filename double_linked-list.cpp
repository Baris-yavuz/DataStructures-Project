#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = n->prev = NULL;
    return n;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d sona eklendi.\n", data);
}

void insertAfter(struct Node* head, int prevData, int newData) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != prevData)
        temp = temp->next;

    if (temp == NULL) {
        printf("Hata: %d listede bulunamadi.\n", prevData);
        return;
    }

    struct Node* newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
    
    printf("%d, %d degerinden sonraya eklendi.\n", newData, prevData);
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Hata: Silinecek %d bulunamadi.\n", key);
        return;
    }

    if (temp == *head) *head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;

    free(temp);
    printf("%d silindi.\n", key);
}

void printList(struct Node* head) {
    printf("Liste: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int ch, val, posVal;

    printf("=== DOUBLY LINKED LIST ===\n");
    while(1) {
        printf("\n1. Sona Ekle\n2. Araya Ekle\n3. Sil\n4. Yazdir\n5. Cikis\nSecim: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Sayi: "); scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 2:
                printf("Hangi sayidan sonra: "); scanf("%d", &posVal);
                printf("Eklenecek sayi: "); scanf("%d", &val);
                insertAfter(head, posVal, val);
                break;
            case 3:
                printf("Silinecek sayi: "); scanf("%d", &val);
                deleteNode(&head, val);
                break;
            case 4:
                printList(head);
                break;
            case 5: return 0;
            default: printf("Gecersiz.\n");
        }
    }
}
