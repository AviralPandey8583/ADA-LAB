#include <stdio.h>

#define INF 1000000

int findTheCity(int n, int edges[][3], int edgesSize, int distanceThreshold) {

    int dist[100][100];

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Fill edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        dist[u][v] = wt;
        dist[v][u] = wt;
    }

    // Floyd Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int city = -1;
    int minCount = INF;

    // Count reachable cities
    for (int i = 0; i < n; i++) {

        int count = 0;

        for (int j = 0; j < n; j++) {

            if (dist[i][j] <= distanceThreshold)
                count++;
        }

        // Excluding itself
        count--;

        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    return city;
}

int main() {

    int n = 4;

    int edges[][3] = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };

    int edgesSize = 4;
    int threshold = 4;

    int ans = findTheCity(n, edges, edgesSize, threshold);

    printf("Answer: %d\n", ans);

    return 0;
}
