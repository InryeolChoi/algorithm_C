#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *data, int left, int right)
{
    int first = left;
    int pivot = data[first];
    left++;

    while (left <= right)
    {
        while (data[left] <= pivot && left < right)
            ++left;
        
        while (data[right] >= pivot && left <= right)
            --right;
        
        if (left < right)
            swap(&data[left], &data[right]);
        else
            break;
    }
    swap(&data[first], &data[right]);
    return (right);
}

void    quick_sort(int *data, int left, int right)
{
    int index;

    if (left < right)
    {
        index = partition(data, left, right);

        quick_sort(data, left, index - 1);
        quick_sort(data, index + 1, right);
    }
}

int main()
{
    int data[] = {6, 4, 2, 3, 1, 5};
    int size = sizeof(data)/sizeof(data[0]);
    insertsort(data, size);

    for (int i = 0; i < size; i++)
        printf("%d : %d\n", i, data[i]);
}