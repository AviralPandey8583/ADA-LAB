#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int findLargestMobile(int a[], int dir[], int n) {
    int largest = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && a[i] > a[i - 1]) {
            if (a[i] > largest) {
                largest = a[i];
                index = i;
            }
        }
        if (dir[i] == RIGHT && i < n - 1 && a[i] > a[i + 1]) {
            if (a[i] > largest) {
                largest = a[i];
                index = i;
            }
        }
    }
    return index;
}

void johnsonTrotter(int n) {
    int a[n], dir[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }
    printPerm(a, n);
    while (1) {
        int k = findLargestMobile(a, dir, n);

        if (k == -1)
            break;
        int swapIndex = k + dir[k];
        int temp = a[k];
        a[k] = a[swapIndex];
        a[swapIndex] = temp;
        int tempDir = dir[k];
        dir[k] = dir[swapIndex];
        dir[swapIndex] = tempDir;
        int movedValue = a[swapIndex];
        for (int i = 0; i < n; i++) {
            if (a[i] > movedValue)
                dir[i] = -dir[i];
        }
        printPerm(a, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
