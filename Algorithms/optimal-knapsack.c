#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int val[], int wt[], int n) {
    int* dp = (int*)calloc(W + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= wt[i]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }

    int result = dp[W];
    free(dp);
    return result;
}

int main() {
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Optimal Çıktı : %d\n", knapsack(W, val, wt, n));
    return 0;
}
