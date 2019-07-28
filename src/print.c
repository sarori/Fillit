#include "fillit.h"

int	print_tetriminoes(char *board, int size)
{
	int	i;

	i = 0;
	while ((size * size) > i)
	{
		// col = 0;
		if (i % size ==  size - 1)
		{
			printf("%c", board[i]);
			printf("\n");
		}	
		else
		{
			printf("%c", board[i]);
		}
		i++;
	}
	return (1);
}

// char    *alpha(t_tet **tetriminoes, int num)
// {
//     /*num == 0부터 시작 */
//     int i;
// 	char *input;

//     i = 0;
//     while (input[i] != '\0')
//     {
//         if (input[i] == '#')
//             input[i] = 'A' + num;
//         i++;
//     }
//     return (input);
// }

