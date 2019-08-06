/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 19:46:13 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(t_tet *tet, char *board, int size)
{
	int	mc;

	mc = 0;
	while (tet && mc < tet->pmc)
	{
		if (check_position(tet->p_set[mc], board, tet->idx))
		{
			board = put_piece(tet->p_set[mc], board);
			tet->mc = mc;
			if (fillit(tet->next, board, size))
				return (YES);
			else
			{
				revert_board(board, tet->p_set[tet->mc]);
				mc++;
				tet->mc = 0;
			}
		}
		else
			mc++;
	}
	return (tet == NULL);
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

void	revert_board(char *board, char *tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
			board[i] = '.';
	}
}
