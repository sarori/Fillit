/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:48:35 by sapark            #+#    #+#             */
/*   Updated: 2019/08/02 23:55:39 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_lst(t_tet **tetriminoes)
{
	t_tet	*tmp;

	while (*tetriminoes)
	{
		ft_strdel(&(*tetriminoes)->input);
		// free(*tetriminoes);
		tmp = (*tetriminoes);
		(*tetriminoes) = (*tetriminoes)->next;
		free(tmp);
	}
}
