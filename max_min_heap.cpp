#include <stdio.h>
#define MAX 100

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void insert(int arr[], int *n, int data) {
    if (*n == MAX) {
        printf("Hata: Heap dolu!\n");
        return;
    }
    arr[*n] = data;
    (*n)++;
    
    // Bubble Up (Yukarý taþýma)
    int i = *n - 1;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("%d eklendi.\n", data);
}

void printHeap(int arr[], int n) {
    if (n == 0) {
        printf("Heap bos.\n");
        return;
    }
    printf("Heap Yapisi: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, val;

    printf("=== MAX HEAP UYGULAMASI ===\n");
    while(1) {
        printf("\n1. Eleman Ekle\n2. Heap Yazdir\n3. Cikis\nSecim: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Sayi girin: ");
                scanf("%d", &val);
                insert(arr, &n, val);
                break;
            case 2:
                printHeap(arr, n);
                break;
            case 3:
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
