#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W[], int P[], int n, int M)
{
    int V[n + 1][M + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if (W[i - 1] > j)
            {
                V[i][j] = V[i - 1][j];
            }
            else
            {
                V[i][j] = max(
                    V[i - 1][j],
                    V[i - 1][j - W[i - 1]] + P[i - 1]
                );
            }
        }
    }

    return V[n][M];
}

int main()
{
    int n, M;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int W[n], P[n];
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &W[i]);
    }
    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &P[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);
    int result = knapsack(W, P, n, M);
    printf("Maximum Profit = %d\n", result);
    return 0;
}
