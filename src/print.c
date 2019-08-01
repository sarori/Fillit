/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:19:26 by sapark            #+#    #+#             */
/*   Updated: 2019/07/31 17:52:38 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_tetriminoes(char *board, int size)
{
	int	i;

	i = 0;
	while ((size * size) > i)
	{
		if (i % size == size - 1)
			printf("%c\n", board[i]);
		else
			printf("%c", board[i]);
		i++;
	}
	return (1);
}

void	print_alpha(t_tet *tet, char *board, int size)
{
	char	*tmp;
	int		i;

	while (tet)
	{
		tmp = move_piece(tet, size, tet->mc);
		board = change_alpha(board, tmp, tet->idx);
		tet = tet->next;
	}
	i = 0;
	while (board[i] != '\0')
	{
		ft_putchar(board[i]);
		if (i % size == size -1)
			ft_putchar('\n');
		i++;
	}
}

char	*change_alpha(char *board, char *piece, int idx)
{
	int	i;

	i = -1;
	while (board[++i])
	{
		if (piece[i] == '#')
			board[i] = idx + 'A';
	}
	return (board);
}
