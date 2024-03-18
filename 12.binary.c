#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int size;
    printf("enter size of array");
    scanf("%d",&size);
    int arr[size];
    printf("enter elements:");
    for (int i=0;i<size;i++) {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("enter the key value");
    scanf("%d",&key);
    clock_t start = clock();
    int index = binarySearch(arr, size, key);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (index != -1)
        printf("Element %d found at index %d.\n", key, index);
    else
        printf("Element %d not found.\n", key);
    return 0;
}
