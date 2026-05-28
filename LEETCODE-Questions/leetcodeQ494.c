#include <stdio.h>
#include <string.h>

int findTargetSumWays(int nums[], int numsSize, int target) {

    int total = 0;

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    // Impossible case
    if ((target + total) % 2 != 0 || total < target)
        return 0;

    int sum = (target + total) / 2;

    int dp[1001];

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {

        for (int j = sum; j >= nums[i]; j--) {

            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[sum];
}

int main() {

    int nums[] = {1,1,1,1,1};
    int size = 5;
    int target = 3;

    int ans = findTargetSumWays(nums, size, target);

    printf("Number of ways = %d\n", ans);

    return 0;
}
