#include <stdio.h>
void selectionSort(int array[], int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}
int main() {
    int array[100];
    int size;
    printf("enter size of array:");
    scanf("%d",&size);
     for (int i=0;i<size;i++)
    {
    	printf("enter element [%d]:",i);
    	scanf("%d",&array[i]);
	}
    selectionSort(array, size);
    printf("SORTED ARRAY: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
