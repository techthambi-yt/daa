#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] == str[end])
        return isPalindrome(str, start + 1, end - 1);
    else
        return 0;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);
    if (isPalindrome(str, 0,strlen(str)-1)==1)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
    return 0;
}
