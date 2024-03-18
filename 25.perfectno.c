#include <stdio.h>
int isPerfectNumber(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum == number) {
        return 1; 
    } else {
        return 0;    }
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }
    return 0;
}
