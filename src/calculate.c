/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:17:33 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 19:00:58 by sapark           ###   ########.fr       */
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
	/* width와 height비교해서 큰 값이 n이 되게 한다.
	tetriminoes->width
	tetriminoes->height
	*/
	t_tet	*tmp;
	int		cnt;
	int		wid_max;
	int		hei_max;
	int		n;
	int		size;

	tmp = (*tetriminoes);
	cnt = count_piece(tetriminoes);
	n = 0;
	size = 0;
	while (ft_pow(++n, 2) < cnt * 4)	/* piece가 다른 게 들어온다면.....저거 가능... */
	wid_max = tmp->width;
	hei_max = tmp->height;
	tmp = tmp->next;	/*2번째 값부터 비교해야하므로 tmp->next를 해야한다. */
	while (tmp)
	{
		if (wid_max < tmp->width)
			wid_max = tmp->width;
		if (hei_max < tmp->height)
			hei_max = tmp->height;
		tmp = tmp->next;
	}
	size = hei_max >= wid_max ? hei_max : wid_max;
	if (size == 2 && cnt > 1)
		size = 4;
	else if (n == 2)
		size = hei_max >= wid_max ? hei_max : wid_max;

	// else if (n > 4)
	// 	size = n;
	else if (n > 4)
	{
		// if (same_piece(tetriminoes, size) == 0 && n >= 6 && cnt >= 9)
		// 	n++;
		size = n;
	}

	// printf("size %d\n", size);
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
				break;
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
				break;
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
	while(input[++i] != '\0')
	{
		if (input[i] == '#')
			hashcnt++;
	}
	if (hashcnt == 4)
		return(hashcnt);
	return(0);
		
}
