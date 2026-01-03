#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols, numElements;
    int matrix[MAX_ROWS][MAX_COLS] = {0}; // Hepsini baþta 0 yap

    printf("=== SPARSE MATRIX DONUSUMU ===\n");
    
    // 1. Matris Boyutlarýný Al
    printf("Matris satir sayisini girin (Max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Matris sutun sayisini girin (Max %d): ", MAX_COLS);
    scanf("%d", &cols);

    // 2. Dolu Elemanlarý Al
    printf("\nKac tane 0 olmayan (dolu) eleman gireceksiniz? ");
    scanf("%d", &numElements);

    printf("\nVerileri girin (Satir Sutun Deger) formatinda:\n");
    printf("Ornek: 0 1 5 (0. satir 1. sutuna 5 yazar)\n");

    for (int i = 0; i < numElements; i++) {
        int r, c, val;
        printf("%d. Eleman: ", i + 1);
        scanf("%d %d %d", &r, &c, &val);
        
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            matrix[r][c] = val;
        } else {
            printf("Hata: Gecersiz satir/sutun! Tekrar deneyin.\n");
            i--; // Sayacý geri al
        }
    }

    // 3. Normal Matrisi Göster
    printf("\n--- Normal Matris ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // 4. Sparse Matris Oluþtur ve Göster
    printf("\n--- Sparse Matrix (Sikistirilmis) ---\n");
    printf("Satir\tSutun\tDeger\n");
    printf("---------------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}
