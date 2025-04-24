#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int val[], int wt[], int n) {
    int i, j;

    // Dinamik programlama tablosu oluşturuluyor
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((W + 1) * sizeof(int));
    }

    // Bottom-Up hesaplama
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                int pick = 0;
                if (wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                int notPick = dp[i - 1][j];
                dp[i][j] = max(pick, notPick);
            }
        }
    }

    int result = dp[n][W];

    // Bellek temizliği
    for (i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main() {
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Tabulation Çıktı : %d\n", knapsack(W, val, wt, n));
    return 0;
}
