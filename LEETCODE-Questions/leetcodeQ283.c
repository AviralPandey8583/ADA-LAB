#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int j = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    while (j < numsSize) {
        nums[j++] = 0;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = 5;

    moveZeroes(nums, size);

    printf("Array after moving zeroes:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
