/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:48:35 by sapark            #+#    #+#             */
/*   Updated: 2019/08/04 01:06:12 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_lst(t_tet **tetriminoes)
{
	t_tet	*tmp;
	int		mc;

	while (*tetriminoes)
	{
		// VALID_SET FREE
		mc = -1;
		while (++mc < (*tetriminoes)->pmc)
			ft_strdel(&(*tetriminoes)->p_set[mc]);
		free((*tetriminoes)->p_set);
		ft_strdel(&(*tetriminoes)->input);
		// free(*tetriminoes);
		tmp = (*tetriminoes);
		(*tetriminoes) = (*tetriminoes)->next;
		free(tmp);
	}
}

void	clear_valid_set(t_tet *tetriminoes)
{
	int		mc;

	while (tetriminoes)
	{
		mc = -1;
		while (++mc < tetriminoes->pmc)
			ft_strdel(&(tetriminoes->p_set[mc]));
		free(tetriminoes->p_set);
		(tetriminoes) = (tetriminoes)->next;
	}	
}
