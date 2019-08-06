/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:17:33 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 19:57:11 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_piece(t_tet **tetriminoes)
{
	t_tet	*curr;
	int		cnt;

	cnt = 0;
	curr = (*tetriminoes);
	while (curr)
	{
		curr = curr->next;
		cnt++;
	}
	return (cnt);
}

int		calculate_size(t_tet **tetriminoes)
{
	t_tet	*tmp;
	int		wid_max;
	int		hei_max;
	int		size;

	tmp = (*tetriminoes);
	size = 0;
	wid_max = tmp->width;
	hei_max = tmp->height;
	tmp = tmp->next;
	while (tmp)
	{
		if (wid_max < tmp->width)
			wid_max = tmp->width;
		if (hei_max < tmp->height)
			hei_max = tmp->height;
		tmp = tmp->next;
	}
	size = hei_max >= wid_max ? hei_max : wid_max;
	return (size);
}

int		count_width(char *input, int size)
{
	int i;
	int j;
	int width;

	i = 0;
	j = 0;
	width = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (input[i * size + j] == '#')
			{
				width++;
				break ;
			}
			i++;
		}
		j++;
	}
	return (width);
}

int		count_height(char *input, int size)
{
	int i;
	int j;
	int height;

	i = 0;
	height = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (input[i * size + j] == '#')
			{
				height++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (height);
}

int		count_hash(char *input)
{
	int		i;
	int		hashcnt;

	i = -1;
	hashcnt = 0;
	while (input[++i] != '\0')
	{
		if (input[i] == '#')
			hashcnt++;
	}
	if (hashcnt == 4)
		return (hashcnt);
	return (0);
}
