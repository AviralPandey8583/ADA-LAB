#include <stdio.h>

#define MAX 10
#define INF 9999

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void unionSet(int u, int v)
{
    parent[u] = v;
}

int main()
{
    int n;
    int cost[MAX][MAX];
    int i, j;
    int a, b, u, v;
    int ne = 0;
    int min, mincost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    while(ne < n - 1)
    {
        min = INF;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v)
        {
            printf("%d -> %d = %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            ne++;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}
