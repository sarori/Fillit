#include "fillit.h"

char    *sort_input_cases(t_tet **tetriminoes)
{
    t_tet   *tmp;

    tmp = (*tetriminoes);
    calculate_size(tetriminoes);
    // calculate_size는 가장 큰 넓이나 높이를 리턴하는데, 이거를 받아서 쓰지를 않음
    possible_mc(tetriminoes, tmp->size);
    if (tmp->size == 2)
        ft_putstr(SPECIAL_CASE);
    else
    {
        if (tmp->size == 3)
            change_input_shape(tetriminoes);
        // create_board(tmp->size);
    }
    return (create_board(tmp->size));
}

char    *create_board(int size)
{
    char    *board;

    board = ft_memalloc(size * size + 1);
    ft_memset(board, '.', size * size);
    board[size * size] = '\0';
    //free(board);
    return (board);
}

void    change_input_shape(t_tet **tetriminoes)
{
    t_tet   *tmp;

    tmp = (*tetriminoes);
    while (tmp)
    {
        tmp->input = trim_edge(tmp->input, DEFAULT_SIZE);
        tmp = tmp->next;
    }
}

char	*put_piece(char *piece, char *board)
{
	int	i;

	i = -1;
	while (board[++i])
	{
		if (board[i] == '#' || piece[i] == '#')
			board[i] = '#';
		else
			board[i] = '.';
	}
	return (board);
}


void	revert_board(char *board, t_tet *tet)
{
	int	i;
	char	*moved;

	i = -1;
	moved = move_piece(tet, 4, tet->mc);
	while (moved[++i])
		if (moved[i] == '#')
			board[i] = '.';
}


int		fillit(t_tet *tet, char *board)
{
	char	*tmp;
	int		mc;

	mc = 0;
	if (tet == NULL)
		return (1);
	while (tet && mc < tet->pmc)
	{
		tmp = move_piece(tet, 4, mc);
		if (check_position(tmp, board, tet->idx))
		{
			board = put_piece(tmp, board);
			tet->mc = mc;
			// print_tetriminoes(board, 4);
			if (fillit(tet->next, board))
			{
				free(tmp);
				return (1);
			}
			else
			{
				revert_board(board, tet);
				mc += 1;
				tet->mc = 0;
			}
		}
		else
			mc += 1;
		free(tmp);
	}
	return (0);
}

char	*move_piece(t_tet *tmp, int size, int cnt)
{
	char	*moved;
	char	*temp;

	moved = ft_strdup(tmp->input);
	while (count_hash(moved) == 4)
	{
		if (tmp->width == count_width(moved, size) &&
		tmp->height == count_height(moved, size) && cnt == 0)
			return (moved);
		else
		{
			temp = ft_countmove(moved, 1);
			free(moved);
			moved = ft_strdup(temp);
			free(temp);
			if (tmp->width == count_width(moved, size) &&
				tmp->height == count_height(moved, size))
				cnt--;
		}
	}
	return (NULL);
}

char	*ft_countmove(char *dst, int move_cnt)
{
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_strdup(dst);
	len = ft_strlen(dst);
	i = 0;

	if (!dst)
		return (NULL);
	while(i < move_cnt)
		tmp[i++] = '.';
	i = 0;
	while (move_cnt < len)
		tmp[move_cnt++] = dst[i++];
	tmp[move_cnt] = '\0';
	return (tmp);
}

int		check_position(char *piece, char *board, int idx)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	while (board[++i])
		if (piece[i] == '#' || board[i] == '#')
			cnt++;
	if (cnt == (idx + 1) * DEFAULT_SIZE)
		return (1);
	return (0);
}
