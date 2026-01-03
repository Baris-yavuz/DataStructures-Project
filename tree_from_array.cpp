#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

// Diziden aðaç oluþturma
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n) {
        root = createNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n;
    int *arr;

    printf("=== DIZIDEN AGAC OLUSTURMA ===\n");
    printf("Dizide kac eleman olacak? ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    printf("Elemanlari sirayla girin:\n");
    for(int i=0; i<n; i++) {
        printf("%d. Eleman: ", i+1);
        scanf("%d", &arr[i]);
    }

    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("\nOlusturulan Agacin Inorder Gezintisi (Test):\n");
    inorder(root);
    printf("\n");

    free(arr);
    return 0;
}
