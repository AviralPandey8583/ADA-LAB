#include <stdio.h>

int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &prerequisitesSize);

    int indegree[100] = {0};
    int graph[100][100];
    int graphSize[100] = {0};

    printf("Enter prerequisite pairs:\n");

    for (int i = 0; i < prerequisitesSize; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[b][graphSize[b]++] = a;
        indegree[a]++;
    }

    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int ans[100];
    int count = 0;

    while (front < rear) {
        int node = queue[front++];

        ans[count++] = node;

        for (int i = 0; i < graphSize[node]; i++) {
            int next = graph[node][i];

            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    if (count != numCourses) {
        printf("[]\n");
    } else {
        printf("[");

        for (int i = 0; i < count; i++) {
            printf("%d", ans[i]);

            if (i != count - 1)
                printf(",");
        }

        printf("]\n");
    }

    return 0;
}
