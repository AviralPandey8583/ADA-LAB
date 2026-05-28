#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Heapify (bottom-up)
void heapify(int arr[], int n, int i) {
    int largest;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        largest = i;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n-1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main() {
    int sizes[] = {10000, 20000, 50000, 100000};
    int k = 4;
    srand(time(0));
    for (int i = 0; i < k; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        generateRandom(arr, n);
        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("n = %d -> Time = %f seconds\n", n, time_taken);
        free(arr);
    }
    return 0;
}
