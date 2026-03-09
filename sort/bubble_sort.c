#include <stdio.h>

void bubblesort(int *data, int length)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < length - 1)
    {
        j = 0;
        while (j < length - (i + 1))
        {
            if (data[j] > data[j+1])
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int data[] = {6, 4, 2, 3, 1, 5};
    int size = sizeof(data)/sizeof(data[0]);
    bubblesort(data, size);

    for (int i = 0; i < size; i++)
        printf("%d : %d\n", i, data[i]);
}