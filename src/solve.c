/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:20:02 by sapark            #+#    #+#             */
/*   Updated: 2019/08/02 23:54:05 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*trim_edge(char *input, int size)
{
	int		i;
	int		j;
	int		total_size;
	char	*piece;
	// char	*tmp;
		
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
	// tmp = piece;
	// ft_strdel(&piece);
	// piece = tmp;
	// ft_strdel(&tmp);
	return (piece);
	//piece free
}
