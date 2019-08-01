/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:18:23 by sapark            #+#    #+#             */
/*   Updated: 2019/07/31 17:36:25 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*sort_input_cases(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	possible_mc(tetriminoes, size);
	if (size == 3)
		change_input_shape(tetriminoes, size);
	// create_board(tmp->size);
	return (create_board(size));
}

char	*create_board(int size)
{
	char	*board;

	board = ft_memalloc(size * size + 1);
	ft_memset(board, '.', size * size);
	board[size * size] = '\0';
	return (board);
}

void	change_input_shape(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	if (size == 3)
	{
		while (tmp)
		{
			tmp->input = trim_edge(tmp->input, DEFAULT_SIZE);
			tmp = tmp->next;
		}
	}
}

void	enlarge_piece(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	while (tmp)
	{
		tmp->input = insert_edge(tmp->input, size);
		tmp = tmp->next;
	}
}

char	*insert_edge(char *input, int size)
{
	int		i;
	int		j;
	int		total_size;
	char	*piece;

	i = 0;
	j = 0;
	total_size = size * size;
	piece = ft_memalloc(total_size + 1);
	piece[total_size] = '\0';
	while (total_size > i)
	{
		if ((i % size == size - 1) || (i / size == size - 1))
		{
			piece[i] = '.';
			i++;
		}
		else
		{
			piece[i] = input[j];
			i++;
			j++;
		}
	}
	return (piece);
	//piece free
}

int		fillit(t_tet *tet, char *board, int size)
{
	char	*tmp;
	int		mc;

	mc = 0;
	if (tet == NULL)	/*더이상 체크할 게 없을 경우 */
		return (YES);
	while (tet && mc < tet->pmc)
	{
		tmp = move_piece(tet, size, mc);	/*3이나 다른 크기에도 할 수 있어야함. */
		// printf("idx : %d, pmc : %d, mc : %d, tmp : %s\n", tet->idx, tet->pmc, mc, tmp);
		if (check_position(tmp, board, tet->idx))
		{
			board = put_piece(tmp, board);
			// printf("[%d] tet\n", tet->idx);

			// print_tetriminoes(tmp, size);
			// printf("%d x %d size board\n",size,size);
			// print_tetriminoes(board, size);
			// printf("\n\n");
			tet->mc = mc;	/*마지막 mc값만 기억함 */
			if (fillit(tet->next, board, size))
			{
				free(tmp);
				return (YES);
			}
			else
			{
				revert_board(board, tet, size);
				mc += 1;
				tet->mc = -1;	/*tet=->mc는 최종 확정 될때만 넣기 */
			}
		}
		else
			mc += 1;
		free(tmp);
	}
	return (0);
}

int		check_position(char *piece, char *board, int idx)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	while (board[++i])
	{
		if (piece[i] == '#' || board[i] == '#')
			cnt++;
	}
	if (cnt == (idx + 1) * DEFAULT_SIZE)
		return (YES);		/*overlap 되지 않을때 = 적합한 위치일 때 */
	return (NO);
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

char	*check_x(char *piece, char *x_axis, int size)
{
	int x;
	int y;
	int x_num;

	x = 0;
	y = 0;
	x_num = 0;
	while (y < size)
	{
		x = 0;
		x_num = 0;
		while (x < size)
		{
			if (piece[x * size + y] == '#')
				x_num++;
			x++;
		}
		x_axis[y] = x_num + '0';
		y++;
	}
	return (x_axis);
}

char	*check_y(char *piece, char *y_axis, int size)
{
	int		x;
	int		y;
	int		y_num;

	x = 0;
	y = 0;
	y_num = 0;
	while (x < size)
	{
		y = 0;
		y_num = 0;
		while (y < size)
		{
			if (piece[x * size + y] == '#')
				y_num++;
			y++;
		}
		y_axis[x] = y_num + '0';
		x++;
	}
	return (y_axis);
}

int		validate_xshape(char *piece, char *moved, int size)
{
	int		valid;
	char	*original_x;
	char	*moved_x;
	char	*tmp1;
	char	*tmp2;

	// printf("moved : %s\n", moved);
	original_x = ft_strnew(size);
	moved_x = ft_strnew(size);
	original_x = check_x(piece, original_x, size);
	moved_x = check_x(moved, moved_x, size);
	
	// printf("original_x : %s\n", original_x);
	// printf("moved_x : %s\n", moved_x);
	tmp1 = ft_strtrimby(original_x, '0');
	tmp2 = ft_strtrimby(moved_x, '0');	/*여기서도 malloc하므로 free 해결해야한다. */
	// printf("tmp1 : %s\n", tmp1);
	// printf("tmp2 : %s\n", tmp2);
	ft_strdel(&original_x);
	ft_strdel(&moved_x);
	valid = strcmp(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (valid == 0 ? 1 : 0);
}

int		validate_yshape(char *piece, char *moved, int size)
{
	int		valid;
	char	*original_y;
	char	*moved_y;
	char	*tmp1;
	char	*tmp2;

	original_y = ft_strnew(size);
	moved_y = ft_strnew(size);
	original_y = check_y(piece, original_y, size);
	moved_y = check_y(moved, moved_y, size);
	// printf("original_y : %s\n", original_y);
	// printf("moved_y : %s\n", moved_y);
	tmp1 = ft_strtrimby(original_y, '0');
	tmp2 = ft_strtrimby(moved_y, '0');	/*여기서도 malloc하므로 free 해결해야한다. */
	// printf("tmp1 : %s\n", tmp1);
	// printf("tmp2 : %s\n", tmp2);
	ft_strdel(&original_y);
	ft_strdel(&moved_y);
	valid = strcmp(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (valid == 0 ? 1 : 0);
}


char	*move_piece(t_tet *tmp, int size, int cnt)
{
	char	*moved;
	char	*temp;

	moved = ft_strdup(tmp->input);
	while (count_hash(moved) == 4)
	{
		// if (count_width(moved, size) == tmp->width
		// 	&& count_height(moved, size) == tmp->height && cnt == 0)
		// 	return (moved);
		if (validate_xshape(tmp->input, moved, size) == 1 && validate_yshape(tmp->input, moved, size) == 1 && cnt == 0)
			return (moved);
		else
		{
			temp = ft_countmove(moved, 1);
			free(moved);
			moved = ft_strdup(temp);
			free(temp);
			if (validate_xshape(tmp->input, moved, size) == 1 && validate_yshape(tmp->input, moved, size) == 1)
				cnt--;
		}
	}
	return (NULL);
}

char	*ft_countmove(char *dst, int move_cnt)
{
	// leak문제 해결해야한다.
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
	return (tmp);
}

void	revert_board(char *board, t_tet *tet, int size)
{
	int		i;
	char	*moved;

	i = -1;
	moved = move_piece(tet, size, tet->mc);
	while (moved[++i])
	{
		if (moved[i] == '#')
			board[i] = '.';
	}
}
