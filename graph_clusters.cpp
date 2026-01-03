#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maksimum düðüm sayýsý

int adj[MAX][MAX] = {0};
bool visited[MAX];
int numVertices;

void DFS(int i) {
    visited[i] = true;
    printf("%d ", i);
    for(int j=0; j < numVertices; j++) {
        if(adj[i][j] && !visited[j]) DFS(j);
    }
}

int main() {
    int ch, u, v;

    printf("=== GRAF CLUSTER BULUCU ===\n");
    printf("Kac dugum (vertex) olacak (Max %d): ", MAX);
    scanf("%d", &numVertices);

    while(1) {
        printf("\n1. Baglanti (Edge) Ekle\n2. Clusterlari Bul ve Cikis\nSecim: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Hangi dugumler bagli (Orn: 0 1): ");
            scanf("%d %d", &u, &v);
            if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
                adj[u][v] = 1;
                adj[v][u] = 1;
                printf("Baglanti eklendi: %d -- %d\n", u, v);
            } else {
                printf("Gecersiz dugum!\n");
            }
        } else if (ch == 2) {
            int clusters = 0;
            printf("\n--- Bulunan Clusterlar ---\n");
            
            // Visited dizisini sýfýrla
            for(int i=0; i<numVertices; i++) visited[i] = false;

            for(int i=0; i < numVertices; i++) {
                if(!visited[i]) {
                    clusters++;
                    printf("Cluster %d: { ", clusters);
                    DFS(i);
                    printf("}\n");
                }
            }
            printf("Toplam Cluster Sayisi: %d\n", clusters);
            return 0;
        }
    }
}
