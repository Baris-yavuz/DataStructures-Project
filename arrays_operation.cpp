#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// --- Fonksiyonlar ---

void display(int arr[], int n) {
    if (n == 0) {
        printf("-> Dizi su an bos!\n");
        return;
    }
    printf("-> Dizi Elemanlari: [ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// 'delete' ismi C++'da reserved oldugu icin 'deleteElement' yaptik
void insertElement(int arr[], int *n, int pos, int elem) {
    // Kapasite kontrolu
    if (*n >= MAX) {
        printf("Hata: Dizi dolu!\n");
        return;
    }
    // Pozisyon kontrolu (1'den baslayan sira no)
    if (pos < 1 || pos > *n + 1) {
        printf("Hata: Gecersiz sira numarasi!\n");
        return;
    }

    // Kaydirma (Sondan basa dogru)
    for(int i = *n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = elem;
    (*n)++;
    printf("Basarili: %d degeri %d. siraya eklendi.\n", elem, pos);
}

void deleteElement(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Hata: Dizi zaten bos.\n");
        return;
    }
    if (pos < 1 || pos > *n) {
        printf("Hata: Gecersiz sira numarasi!\n");
        return;
    }

    int silinen = arr[pos-1];

    // Kaydirma (Silinen yerin ustunu kapatma)
    for(int i = pos-1; i < *n-1; i++) {
        arr[i] = arr[i+1];
    }
    (*n)--;
    printf("Basarili: %d degeri silindi.\n", silinen);
}

// --- Main ve Menü ---
int main() {
    int arr[MAX];
    int n = 0; // Mevcut eleman sayisi
    int secim, sayi, pozisyon;

    printf("=== ARRAY ISLEMLERI ODEVI ===\n");

    while(1) {
        printf("\n1. Listele\n2. Ekle (Insert)\n3. Sil (Delete)\n4. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Eklenecek Sayi: ");
                scanf("%d", &sayi);
                printf("Hangi Siraya (1 - %d arasi): ", n + 1);
                scanf("%d", &pozisyon);
                insertElement(arr, &n, pozisyon, sayi);
                break;
            case 3:
                printf("Silinecek Sira No (1 - %d arasi): ", n);
                scanf("%d", &pozisyon);
                deleteElement(arr, &n, pozisyon);
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
