#include <stdio.h>
#include <math.h>

int countDigits(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int number, int originalNumber, int sum) {
    if (number == 0) {
        if (originalNumber == sum)
            return 1; // Number is Armstrong
        else
            return 0; // Number is not Armstrong
    } else {
        int digit = number % 10;
        sum += pow(digit, countDigits(originalNumber));
        return isArmstrong(number / 10, originalNumber, sum);
    }
}

void checkArmstrong(int number) {
    if (isArmstrong(number, number, 0))
        printf("%d is an Armstrong number\n", number);
    else
        printf("%d is not an Armstrong number\n", number);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    checkArmstrong(number);
    return 0;
}
