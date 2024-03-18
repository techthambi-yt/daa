#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsackDP(int W, int weights[], int values[], int n) {
    int DP[n + 1][W + 1];

    // Build up the DP table using bottom-up approach
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                DP[i][w] = 0;
            else if (weights[i - 1] <= w)
                DP[i][w] = max(values[i - 1] + DP[i - 1][w - weights[i - 1]], DP[i - 1][w]);
            else
                DP[i][w] = DP[i - 1][w];
        }
    }
    return DP[n][W];
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);
    int maxValue = knapsackDP(W, weights, values, n);
    printf("Maximum value that can be obtained: %d\n", maxValue);
    return 0;
}
