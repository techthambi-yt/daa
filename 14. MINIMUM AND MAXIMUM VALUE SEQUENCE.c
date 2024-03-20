#include <stdio.h>
void printMinMaxFrequency(int arr[], int size) {
    int minFreq = size + 1, maxFreq = 0;
    for (int i = 0; i < size; ++i) {
        int freq = 1;
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                freq++;
            }
        }
        if (freq < minFreq) {
            minFreq = freq;
        }
        if (freq > maxFreq) {
            maxFreq = freq;
        }
        printf("Frequency of %d: %d\n", arr[i], freq);
    }
    printf("Minimum frequency: %d\n", minFreq);
    printf("Maximum frequency: %d\n", maxFreq);
}
int main() {
    int arr[] = {3, 1, 4, 3,4,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Input list: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Minimum and Maximum value frequencies:\n");
    printMinMaxFrequency(arr, size);
    return 0;
}
	