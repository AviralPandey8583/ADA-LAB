#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

// Function to sort items by profit/weight ratio (descending)
void sortItems(Item items[], int n) {
    int i, j;
    Item temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    int i;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    // Input profits and weights
    for (i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);

        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items based on ratio
    sortItems(items, n);

    printf("\nSelected items:\n");

    // Fractional Knapsack Logic
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take full item
            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            printf("Item %d -> 100%% taken\n", i + 1);
        } else {
            // Take fraction of item
            float fraction = (float)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;

            printf("Item %d -> %.2f%% taken\n", i + 1, fraction * 100);

            capacity = 0;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
