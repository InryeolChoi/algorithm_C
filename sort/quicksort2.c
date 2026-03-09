#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ComparePoint (const void *num1, const void *num2) {
    int *elem1 = (int *)num1;
    int *elem2 = (int *)num2;

    if (elem1 > elem2) {
        return 1;
    }

    else if (elem1 < elem2) {
        return -1;
    }

    else {
        return 0;
    }

    return 0;
}

int main() {
    int dataset[] = {5, 2, 9, 1, 5, 6};
    size_t dataset_size = sizeof(dataset) / sizeof(dataset[0]);

    qsort(dataset, dataset_size, sizeof(int), ComparePoint);

    printf("Sorted dataset: ");
    for (size_t i = 0; i < dataset_size; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n");

    return 0;
}