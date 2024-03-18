#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int binomialCoefficient(int n, int k) {
    int DP[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                DP[i][j] = 1;
            else
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }
    return DP[n][k];
}

int main() {
    int n = 5, k = 2; // Example values, change as needed
    int result = binomialCoefficient(n, k);
    printf("Binomial coefficient C(%d, %d) = %d\n", n, k, result);
    return 0;
}