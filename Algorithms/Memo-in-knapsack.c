#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsackRec(int W, int val[], int wt[], int n, int** memo) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);

    int notPick = knapsackRec(W, val, wt, n - 1, memo);

    memo[n][W] = max(pick, notPick);
    return memo[n][W];
}

int knapsack(int W, int val[], int wt[], int n) {
    int** memo = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        memo[i] = (int*)malloc((W + 1) * sizeof(int));
        for (int j = 0; j <= W; j++) {
            memo[i][j] = -1;
        }
    }

    int result = knapsackRec(W, val, wt, n, memo);

    for (int i = 0; i <= n; i++) {
        free(memo[i]);
    }
    free(memo);

    return result;
}

int main() {
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Memoization Çıktı : %d\n", knapsack(W, val, wt, n));
    return 0;
}
