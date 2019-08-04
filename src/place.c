/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:18:23 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 19:01:25 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	sort_input_cases(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	possible_mc(tetriminoes, size);
	if (size == 2)
	{
		ft_putstr(SPECIAL_CASE);
		exit(0);
	}
	else if (size == 3)
		change_input_shape(tetriminoes, size);
}

char	*ft_countmove(char *dst, int move_cnt)
{
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_strdup(dst);
	len = ft_strlen(dst);
	i = 0;
	if (!dst)
		return (NULL);
	while(i < move_cnt)
		tmp[i++] = '.';
	i = 0;
	while (move_cnt < len)
		tmp[move_cnt++] = dst[i++];
	return (tmp);
}
