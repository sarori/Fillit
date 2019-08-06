/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 18:18:58 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(t_tet *tet, char *board, int size)
{
	int	mc;
	
	mc = 0;
	while (tet && mc < tet->pmc)
	{
		// tmp[mc] = move_piece(tet, size, mc);	/*3이나 다른 크기에도 할 수 있어야함. */
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
				tet->mc = 0;/*tet=->mc는 최종 확정 될때만 넣기 */
			}
		}
		else
			mc++;;
	}
	return (tet == NULL);/*더이상 체크할 게 없을 경우 */
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
