#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** last, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    if (*last == NULL) {
        *last = temp;
        temp->next = *last;
    } else {
        temp->next = (*last)->next;
        (*last)->next = temp;
        *last = temp;
    }
    printf("%d eklendi.\n", data);
}

void deleteNode(struct Node** last, int key) {
    if (*last == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Node *curr = (*last)->next, *prev = *last;
    
    // Tek eleman varsa
    if (curr == *last && curr->data == key) {
        free(curr); *last = NULL; 
        printf("%d silindi.\n", key);
        return;
    }
    
    do {
        if (curr->data == key) {
            prev->next = curr->next;
            if (curr == *last) *last = prev;
            free(curr);
            printf("%d silindi.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != (*last)->next);
    
    printf("Eleman bulunamadi.\n");
}

void display(struct Node* last) {
    if (last == NULL) { printf("Liste bos.\n"); return; }
    struct Node* temp = last->next;
    printf("Circular Liste: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(BASA)\n");
}

int main() {
    struct Node* last = NULL;
    int ch, val;

    printf("=== CIRCULAR LINKED LIST ===\n");
    while(1) {
        printf("\n1. Ekle\n2. Sil\n3. Yazdir\n4. Cikis\nSecim: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Sayi: "); scanf("%d", &val); insertEnd(&last, val); break;
            case 2: printf("Silinecek: "); scanf("%d", &val); deleteNode(&last, val); break;
            case 3: display(last); break;
            case 4: return 0;
            default: printf("Gecersiz.\n");
        }
    }
}
