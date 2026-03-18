#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *data, int left, int right)
{
    int pivot;
    int store;
    int i;

    pivot = data[right];
    store = left;
    i = left;
    while (i < right)
    {
        if (data[i] < pivot)
        {
            swap(&data[i], &data[store]);
            store++;
        }
        i++;
    }
    swap(&data[store], &data[right]);
    return store;
}

static void quicksort(int *data, int left, int right)
{
    int pivotIndex;

    if (left >= right)
        return;
    pivotIndex = partition(data, left, right);
    quicksort(data, left, pivotIndex - 1);
    quicksort(data, pivotIndex + 1, right);
}

int main(void)
{
    int data[] = {8, 3, 7, 4, 9, 2, 6, 5};
    int size = sizeof(data) / sizeof(data[0]);
    int i;

    quicksort(data, 0, size - 1);
    i = 0;
    while (i < size)
    {
        printf("%d ", data[i]);
        i++;
    }
    printf("\n");
    return 0;
}
