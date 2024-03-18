#include <stdio.h>

int findLargestElement(int array[], int size) {
    if (size == 0)
        return -1; 
    int largestElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > largestElement)
            largestElement = array[i];
    }
    return largestElement;
}

int main() {
    int array[100];
    printf("enter size of array");
    int size;
    scanf("%d",&size);
    for (int i=0;i<size;i++)
    {
    	printf("enter element [%d]:",i);
    	scanf("%d",&array[i]);
	}
    int largest = findLargestElement(array, size);

    if (largest != -1)
        printf("The largest element in the array is %d\n", largest);
    else
        printf("The array is empty\n");

    return 0;
}
