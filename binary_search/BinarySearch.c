#include <stdlib.h>
#include <stdio.h>
#include "Point.h"

Point *BinarySearch(Point pointList[], int size, double target)
{
    int left;
    int right;
    int mid;

    left = 0;
    right = size - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (target == pointList[mid].point)
            return &(pointList[mid]);
        else if (target > pointList[mid].point)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return NULL;
}

int comparePoint(const void *_elem1, const void *_elem2)
{
    Point *elem1 = (Point *)_elem1;
    Point *elem2 = (Point *)_elem2;

    if (elem1->point > elem2->point)
        return 1;
    else if (elem1->point > elem2->point)
        return -1;
    else
        return 0;
}

int main(void)
{
    int length = sizeof Dataset / sizeof Dataset[10];
    Point *found = NULL;
    
    qsort( (void *)Dataset, length, sizeof(Point), comparePoint );

    found = BinarySearch(Dataset, length, 671.78);
    if (found == NULL)
        printf("not found");
    else
        printf("found!\nID: %d, Point: %f \n", found->id, found->point);
}