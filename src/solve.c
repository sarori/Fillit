/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:20:02 by sapark            #+#    #+#             */
/*   Updated: 2019/07/29 02:30:57 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*trim_edge(char *input, int size)
{
	int		i;
	int		j;
	int		total_size;
	char	*piece;
		
	i = 0;
	j = 0;
	total_size = size * size;
	piece = ft_memalloc(total_size + 1);
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
	}
	board[j] = '\0';
	print_tetriminoes(board , size);
}
