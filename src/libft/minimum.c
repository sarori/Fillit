#include "libft.h"

int     minimum(int *arr, int size)
{
    int i;
    int min;

    i = 0;
    min = arr[0];
    while (i < size)
    {
        if (arr[i] < min)
            min = arr[i];
        i++;
    }
    return (min);
}
