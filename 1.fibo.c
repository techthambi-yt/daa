#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSeries(int terms) {
    printf("Fibonacci Series up to %d terms: \n", terms);
    for (int i = 0; i < terms; ++i) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &terms);

    if (terms < 0) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    printFibonacciSeries(terms);

    return 0;
}
