#include <stdio.h>
void bubbleSort(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main()
 {
 	int array[100];
    int size;
    printf("enter size of array:");
    scanf("%d",&size);
     for (int i=0;i<size;i++)
    {
    	printf("enter element [%d]:",i);
    	scanf("%d",&array[i]);
	}
    bubbleSort(array, size);
    printf("Array after sorting: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
