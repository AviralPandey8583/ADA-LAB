#include <stdio.h>

#define MAX 100

int main() {
    int V[MAX][MAX], Indegree[MAX];
    int visited[MAX], TP[MAX];
    int n, i, j, w;
    int tp_count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        Indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (V[j][i] == 1) {
                Indegree[i]++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    while (1) {
        w = -1;
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && Indegree[i] == 0) {
                w = i;
                break;
            }
        }
        if (w == -1) {
            break;
        }
        TP[tp_count++] = w;
        visited[w] = 1;
        for (i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                Indegree[i]--;
            }
        }
    }
    if (tp_count < n) {
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Sequence:\n");
        for (i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
        printf("\n");
    }

    return 0;
}
