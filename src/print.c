/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:19:26 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 22:25:19 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_alpha(t_tet *tet, char *board, int size)
{
	int		i;

	i = 0;
	while (tet)
	{
		board = change_alpha(board, tet->p_set[tet->mc], tet->idx);
		tet = tet->next;
	}
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

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
