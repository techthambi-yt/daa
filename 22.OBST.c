#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MAX

int min(int a, int b) {
    return (a < b) ? a : b;
}

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}
int optimalBST(int keys[], int freq[], int n) {
    int DP[n+1][n+1];
    for (int i = 0; i <= n; i++)
        DP[i][i] = freq[i];

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            DP[i][j] = INFINITY;
            int freqSum = sum(freq, i, j);
            for (int r = i; r <= j; r++) {
                int cost = ((r > i) ? DP[i][r - 1] : 0) +
                           ((r < j) ? DP[r + 1][j] : 0) +
                           freqSum;
                DP[i][j] = min(DP[i][j], cost);
            }
        }
    }
    return DP[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    int cost = optimalBST(keys, freq, n);
    printf("Cost of optimal BST is: %d\n", cost);

    return 0;
}
