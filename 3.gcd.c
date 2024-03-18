#include <stdio.h>

int findGCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return findGCD(b, a % b);
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int gcd = findGCD(a, b);
    printf("GCD of %d and %d is %d\n", a, b, gcd);

    return 0;
}
