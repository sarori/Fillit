#include "fillit.h"

void	two_dprint(char *arr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arr);
	while (len > i)
	{
		if (i % 4 == 3)
		{
			printf("%c", arr[i]);
			printf("\n");
		}	
		else
		{
			printf("%c", arr[i]);
		}
		i++;
	}
}
