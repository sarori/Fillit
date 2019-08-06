/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:20:02 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 19:54:26 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	make_valid_set(t_tet *tmp, int size)
{
	char	*moved;
	char	*temp;
	int		mc;

	while (tmp)
	{
		if (!(tmp->p_set = (char **)malloc((tmp->pmc + 1) * sizeof(char *))))
			return ;
		moved = ft_strdup(tmp->input);
		tmp->p_set[0] = ft_strdup(moved);
		mc = 1;
		while (count_hash(moved) == 4)
		{
			temp = ft_countmove(moved, 1);
			free(moved);
			moved = temp;
			if (validate_xshape(tmp->input, moved, size) == 1
			&& validate_yshape(tmp->input, moved, size) == 1)
				tmp->p_set[mc++] = ft_strdup(moved);
		}
		ft_strdel(&moved);
		tmp->p_set[tmp->pmc] = "\0";
		tmp = tmp->next;
	}
}

void	play_tetrimino(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;
	char	*board;

	tmp = (*tetriminoes);
	if (size >= 5)
		enlarge_piece(tetriminoes, size, size - 4);
	while (1)
	{
		sort_input_cases(tetriminoes, size);
		board = create_board(size);
		make_valid_set(tmp, size);
		if (fillit(tmp, board, size) == YES)
			break ;
		else
		{
			clear_valid_set(tmp);
			ft_strdel(&board);
			enlarge_piece(tetriminoes, ++size, 1);
		}
	}
	print_alpha(tmp, board, size);
	ft_strdel(&board);
}
