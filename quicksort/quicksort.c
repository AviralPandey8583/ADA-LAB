#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX];

int partition(int low, int high)
{
int pivot = arr[low];
int i = low + 1;
int j = high;
int temp;

while (1)
{
while (i <= high && arr[i] <= pivot)
i++;

while (arr[j] > pivot)
j--;

if (i < j)
{
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
else
{
temp = arr[low];
arr[low] = arr[j];
arr[j] = temp;
return j;
}
}
}

void quicksort(int low, int high)
{
if (low < high)
{
int pos = partition(low, high);

quicksort(low, pos - 1);
quicksort(pos + 1, high);
}
}

int main()
{
int n, i;
clock_t start, end;
double time_taken;

srand(time(NULL));

printf("N\tTime Taken (seconds)\n");

for (n = 10000; n <= 50000; n += 10000)
{
for (i = 0; i < n; i++)
{
arr[i] = rand() % 10000;
}

start = clock();

quicksort(0, n - 1);

end = clock();

time_taken = (double)(end - start) / CLOCKS_PER_SEC;

printf("%d\t%f\n", n, time_taken);
}

return 0;
}
