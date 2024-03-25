#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 9999999

typedef struct Edge
{
    int src, dest, weight;
} Edge;

void createmat(int m[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = 0;
            if (i != j)
            {
                printf("Is there an edge between %d and %d (weight, 0 for no edge): ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
}

void dispmat(int m[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// Compare function for sorting edges based on weight
int compare(const void *a, const void *b)
{
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskal(int n, int graph[10][10])
{
    Edge result[n];
    int e = 0;
    int i = 0;
    int totalWeight = 0;

    Edge edges[(n * (n - 1)) / 2];

    // Store all the edges in a separate array
    for (int u = 0; u < n; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            if (graph[u][v] != 0)
            {
                edges[i].src = u;
                edges[i].dest = v;
                edges[i].weight = graph[u][v];
                i++;
            }
        }
    }

    // Sort all edges based on weight
    qsort(edges, i, sizeof(Edge), compare);

    int parent[n];
    for (int j = 0; j < n; j++)
    {
        parent[j] = -1;
    }

    i = 0;
    while (e < n - 1 && i < ((n * (n - 1)) / 2))
    {
        Edge next_edge = edges[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            totalWeight += next_edge.weight;
            unionSet(parent, x, y);
        }
    }

    // Print the edges of the Minimum Spanning Tree
    printf("Edge : Weight\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);

    printf("Total Weight of Minimum Spanning Tree: %d\n", totalWeight);
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int m[10][10];
    createmat(m, n);
    dispmat(m, n);

    kruskal(n, m);

    return 0;
}