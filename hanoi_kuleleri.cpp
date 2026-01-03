#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Diski tasi: %c -> %c\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, yardimci, hedef);
    printf("Diski tasi: %c -> %c\n", kaynak, hedef);
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int diskSayisi;

    printf("=== HANOI KULELERI ===\n");
    printf("Disk sayisini giriniz: ");
    scanf("%d", &diskSayisi);

    if (diskSayisi < 1) {
        printf("Hata: Disk sayisi en az 1 olmalidir.\n");
        return 1;
    }

    printf("\n--- %d Disk Icin Cozum Adimlari ---\n", diskSayisi);
    // A: Kaynak, C: Hedef, B: Yardimci
    hanoi(diskSayisi, 'A', 'C', 'B');

    printf("\nIslem tamamlandi.\n");
    return 0;
}
