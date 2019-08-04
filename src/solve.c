/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:20:02 by sapark            #+#    #+#             */
/*   Updated: 2019/08/04 00:20:19 by sapark           ###   ########.fr       */
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
		tmp->p_set[0] = ft_strdup(moved);/*첫번째는 따로 넣어줘야 한다. */
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
		tmp->p_set[tmp->pmc] = "\0";/*'\0'넣어야하고 char *형이니까 " "로 넣어야한다.  */
		tmp = tmp->next;
	}
}
