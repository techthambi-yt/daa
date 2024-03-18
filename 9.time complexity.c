 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
void multiplyMatrices(int A[N][N], int B[N][N], int C[N][N], int size) {
    int i, j, k;
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            C[i][j] = 0;
            for (k = 0; k < size; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main() {
    int A[N][N], B[N][N], C[N][N];
    int size = N;
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    start = clock();
    multiplyMatrices(A, B, C, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %lf seconds\n", cpu_time_used);

    return 0;
}
