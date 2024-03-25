#include <stdio.h>

typedef struct node {
    int vertex;
    struct node *next;
} NODE;

void createmat(int m[10][10], int n) {
    int i, j;
    char ans;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = 0;
            if (i != j) {
                printf("\nIs there an edge between %d and %d (1/0): ", i + 1, j + 1);
                scanf("%d", &m[i][j]); 
            }
        }
    }
}

void dispmat(int m[10][10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

void dfs(int m[10][10], int n, int v) {
    int w;
    static int visited[20] = {0}; 
    visited[v] = 1;
    printf("v%d ", v + 1); 
    for (w = 0; w < n; w++) {
        if ((m[v][w] == 1) && (visited[w] == 0))
            dfs(m, n, w);
    }
}

int main() {
    int m[10][10];
    int n; 
    printf("\nEnter the number of vertices: "); 
    scanf("%d", &n);
    createmat(m, n);
    dispmat(m, n);
    dfs(m, n, 0);
    printf("\n"); 
    return 0; 
}
