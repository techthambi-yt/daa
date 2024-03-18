#include <stdio.h>
void copyString(char *a, char *b) {
    if (*a == '\0') {
        *b = '\0';
        return;
    }
    *b = *a;
    copyString(a + 1, b + 1);
}

int main() {
    char a[100],b[100];
    printf("Enter a string: ");
    scanf("%s", a);
    copyString(a, b);
    printf("Original string: %s\n", a);
    printf("Copied string: %s\n", b);
    return 0;
}
