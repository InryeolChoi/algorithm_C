#include <stdlib.h>
#include <stdio.h>
int ComparePoint(const void *num1, const void *num2)
{
    const int *elem1 = (const int *)num1;
    const int *elem2 = (const int *)num2;

    if (*elem1 > *elem2) {
        return 1;
    }

    else if (*elem1 < *elem2) {
        return -1;
    }

    else {
        return 0;
    }

    return 0;
}

int main()
{
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
