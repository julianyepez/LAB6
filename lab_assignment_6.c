#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == value) return mid;

        if (numbers[mid] > value) return search(numbers, low, mid - 1, value);

        return search(numbers, mid + 1, high, value);
    }

    return -1;
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int numInputs;
    int value = 5; // Search for the value 5 in each number array
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *)malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed\n");
            fclose(inFile);
            return 1;
        }
        for (int i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &numArray[i]);
        }

        printArray(numArray, countOfNums);

        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}