#include <iostream>
#include <limits.h>

int maxCrossSubArraySum(int s, int m, int e, int* nums) {
    int leftSum = INT_MIN;
    int sum1 = 0;
    for (int i = m; i >= s; --i) {
        sum1 += nums[i];
        if (leftSum < sum1) {
            leftSum = sum1;
        }
    }

    int rightSum = INT_MIN;
    int sum2 = 0;
    for (int i = m + 1; i <= e; ++i) {
        sum2 += nums[i];
        if (rightSum < sum2) {
            rightSum = sum2;
        }
    }

    return leftSum + rightSum;
}

int maxSubArray(int s, int e, int* nums) {
    if (s == e) {
        return nums[s];
    }

    int mid = s + (e - s) / 2;
    int LSS = maxSubArray(s, mid, nums);
    int RSS = maxSubArray(mid + 1, e, nums);
    int CSS = maxCrossSubArraySum(s, mid, e, nums);

    return std::max(std::max(LSS, RSS), CSS);
}

int main() {
    int nums[] = {5,4,-1,7,8};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxSum = maxSubArray(0, n - 1, nums);

    std::cout << "Maximum Subarray Sum: " << maxSum << std::endl;

    return 0;
}