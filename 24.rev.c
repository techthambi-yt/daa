#include <stdio.h>
int reverseNumber(int number, int reversedNumber) 
{
    if (number == 0)
        return reversedNumber;
    int lastDigit = number % 10;
    reversedNumber = reversedNumber * 10 + lastDigit;
    return reverseNumber(number / 10, reversedNumber);
}
int main() {
    int number, reversedNumber = 0;
    printf("Enter a number: ");
    scanf("%d", &number);
    int result = reverseNumber(number, reversedNumber);
    printf("Reverse of %d is %d\n", number, result);
    return 0;
}