#include <stdio.h>
#include <stdlib.h>

int stack[20];
int visited[20] = {0};
int top = -1;

void createmat(int m[10][10], int n)
{
    int i, j;
    char ans;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = 0;
            if (i != j)
            {
                printf("Is ther an edge between %d and %d(1/0):", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }
} 

void dispmat(int m[10][10], int n)
{
    int i, j;
    char ans;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d \t", m[i][j]);
        }
        printf("\n");
    }
}

void dfs(int m[10][10], int i, int n)
{
    int j;
    visited[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (m[i][j] == 1 && !visited[j])
        {
            dfs(m, j, n);
        }
    }
    stack[++top] = i;
}

void topologicalSort(int m[10][10], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(m, i, n);
        }
    }
    printf("\nTopological Sort is: \n");
    while (top != -1)
    {
        printf("%d", stack[top--]);
    }
}

int main()
{
    int m[10][10];
    int n;
    printf("Enter the no. of vertices \n");
    scanf("%d", &n);
    createmat(m, n);
    dispmat(m, n);
    topologicalSort(m, n);
}