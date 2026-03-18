#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertsort(int *data, int length)
{
    int i;
    int j;
    int value;

    i = 1;
    while (i < length)
    {
        if (data[i-1] <= data[i])
        {
            i++;
            continue;
        }
        value = data[i];
        j = 0;

        while (j < i)
        {
            if (data[j] > value)
            {
                memmove(&data[j+1], &data[j], sizeof(data[0]) * (i-j));
                data[j] = value;
                break;
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
    insertsort(data, size);

    for (int i = 0; i < size; i++)
        printf("%d : %d\n", i, data[i]);
    return 0;
}
