/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:36:13 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 19:50:22 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_input_shape(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;
	char	*tmp_piece;

	tmp = (*tetriminoes);
	if (size == 3)
	{
		while (tmp)
		{
			tmp_piece = trim_edge(tmp->input, DEFAULT_SIZE);
			free(tmp->input);
			tmp->input = tmp_piece;
			tmp = tmp->next;
		}
	}
}

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
}

void	enlarge_piece(t_tet **tetriminoes, int size, int len)
{
	t_tet	*tmp;
	char	*tmp_piece;

	tmp = (*tetriminoes);
	while (tmp)
	{
		tmp_piece = insert_edge(tmp->input, size, len);
		free(tmp->input);
		tmp->input = tmp_piece;
		tmp = tmp->next;
	}
}

char	*insert_edge(char *input, int size, int len)
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
		if ((i % size >= size - len && i % size <= size - 1)
			|| (i / size >= size - len && i / size <= size - 1))
			piece[i++] = '.';
		else
			piece[i++] = input[j++];
	}
	return (piece);
}
