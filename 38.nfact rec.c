#include <stdio.h>
void generateFactors(int n, int i) {
	printf("\nn=%d___i=%d\n",i,n);
    if (i > n)
    {
        return;
    }
    if (n % i == 0)
        printf("\n yes%d ", i);
    generateFactors(n, i + 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    generateFactors(n, 1); // Start with i = 1
    return 0;
}
