#include <stdio.h>

void floydWarshall(int n, int cost[10][10])
{
    int dist[10][10];
    int i, j, k;

    // Initialize the distance matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = cost[i][j];
        }
    }

    // Apply Floyd Warshall's algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == 999)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, cost[10][10], i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (For infinity, enter 999):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    floydWarshall(n, cost);

    return 0;
} 