/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:40:07 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 19:58:01 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		insert_node(t_tet **target, char *input)
{
	t_tet			*new_node;
	t_tet			*tmp;
	static int		i = 0;

	new_node = (t_tet *)malloc(sizeof(t_tet));
	tmp = (*target);
	new_node->width = count_width(input, 4);
	new_node->height = count_height(input, 4);
	new_node->idx = i++;
	new_node->mc = 0;
	new_node->input = ft_strdup(input);
	new_node->next = NULL;
	if (!tmp)
		(*target) = new_node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

char		*create_board(int size)
{
	char	*board;

	board = ft_memalloc(size * size + 1);
	ft_memset(board, '.', size * size);
	board[size * size] = '\0';
	return (board);
}

void		possible_mc(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	while (tmp)
	{
		tmp->pmc = ((size - (tmp->width) + 1) * (size - (tmp->height) + 1));
		tmp = tmp->next;
	}
}

int			calculate_board_size(t_tet **tetriminoes)
{
	int		cnt;
	int		n;
	int		size;

	cnt = count_piece(tetriminoes);
	size = calculate_size(tetriminoes);
	n = 1;
	while (ft_pow(n, 2) < cnt * 4)
		n++;
	if (size == 2 && cnt > 1)
		size = 4;
	else if (n > 4)
		size = n;
	return (size);
}
