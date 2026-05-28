#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numCourses, prerequisitesSize;

    printf("Enter number of courses: ");
    scanf("%d", &numCourses);

    printf("Enter number of prerequisite pairs: ");
    scanf("%d", &prerequisitesSize);

    int indegree[100] = {0};
    int graph[100][100] = {0};
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

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < graphSize[node]; i++) {
            int next = graph[node][i];

            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }

    if (count == numCourses)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
