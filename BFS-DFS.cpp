#include <stdio.h>
#include <stdbool.h>

#define MAX 10
int adj[MAX][MAX] = {0};
bool visited[MAX];
int numVertices;

void addEdge(int u, int v) { 
    if(u < numVertices && v < numVertices) {
        adj[u][v] = 1; adj[v][u] = 1; 
        printf("%d -- %d baglandi.\n", u, v);
    } else printf("Gecersiz dugum.\n");
}

void DFS(int start) {
    printf("%d ", start);
    visited[start] = true;
    for(int i=0; i<numVertices; i++)
        if(adj[start][i] && !visited[i]) DFS(i);
}

void BFS(int start) {
    bool bfs_visited[MAX] = {false};
    int queue[MAX], front = 0, rear = 0;
    
    queue[rear++] = start;
    bfs_visited[start] = true;

    while(front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for(int i=0; i<numVertices; i++) {
            if(adj[curr][i] && !bfs_visited[i]) {
                queue[rear++] = i;
                bfs_visited[i] = true;
            }
        }
    }
}

// Visited sýfýrlama yardýmcýsý
void resetVisited() {
    for(int i=0; i<MAX; i++) visited[i] = false;
}

int main() {
    int ch, u, v, start;
    printf("=== DFS ve BFS UYGULAMASI ===\n");
    printf("Dugum sayisi (Max %d): ", MAX);
    scanf("%d", &numVertices);

    while(1) {
        printf("\n1. Baglanti Ekle\n2. DFS Calistir\n3. BFS Calistir\n4. Cikis\nSecim: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Baglanti (u v): "); scanf("%d %d", &u, &v);
                addEdge(u, v);
                break;
            case 2:
                printf("Baslangic dugumu: "); scanf("%d", &start);
                resetVisited();
                printf("DFS Sonucu: "); DFS(start); printf("\n");
                break;
            case 3:
                printf("Baslangic dugumu: "); scanf("%d", &start);
                printf("BFS Sonucu: "); BFS(start); printf("\n");
                break;
            case 4: return 0;
        }
    }
}
