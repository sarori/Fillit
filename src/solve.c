#include "fillit.h"

char    *trim_edge(char *input, int size)
{
    int     i;
    int     j;
    int     total_size;
    char    *piece;
       
    i = 0;
    j = 0;
    total_size = size * size;
    piece = ft_memalloc(total_size + 1);;
    total_size = size * size;
    while (total_size > i)
    {
        if ((i % size == size - 1) || (i / size == size - 1))
            i++;
        else
        {
            piece[j] = input[i];
            i++;
            j++;
        }
    }
    // print_tetriminoes(piece, 3);
    // printf("\n");
    return (piece);

    //piece free
}

void	special_case(t_tet **tetriminoes, char *board, int size)
{
	t_tet	*tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	tmp = (*tetriminoes);
	len = ft_strlen(tmp->input);
	while (len > i)
	{
		if ((tmp->input)[i] == '#')
		{
			board[j] = '#';
			j++;
		}
		i++;
		//print
	}
	board[j] = '\0';
	print_tetriminoes(board , size);
}

// void	sort_cases(t_tet **tetriminoes, char *board, int size)
// {
// 	t_tet	*tmp;
// 	int		i;
// 	int		cnt;	/* piece개수 */
// 	char	*piece;

// 	i = 0;
// 	cnt = count_piece(tetriminoes);
// 	tmp = (*tetriminoes);
// 	if (size == 2 && cnt == 1)
// 		special_case(tetriminoes, board, size);	/*print_tetriminoes 넣기*/
// 	else if (size == 3 && cnt <= 2) 
// 	{
// 		while (tmp)
// 		{
// 			piece = trim_edge(tmp->input, DEFAULT_SIZE);	/*원래 input이 4 by 4로 구성되어 있기 때문에 size + 1 */
// 			tmp->input = piece;	/*리스트에 들어있는 전체 piece들의 형태 바꾸면 됨 */
// 			tmp = tmp->next;
// 		}
// 		place_piece(tetriminoes, board, size);
// 	}
// 	else
// 		place_piece(tetriminoes, board, size);
// }