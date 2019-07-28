#include "libft.h"

int     maximum(int *arr, int size)
{
    int i;
    int max;

    i = 0;
    max = arr[0];
    while (i < size)
    {
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    return (max);
}
