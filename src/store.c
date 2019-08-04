/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:40:07 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 12:23:06 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insertNode(t_tet **target, char *input)
{
	t_tet			*newNode;
	t_tet			*tmp;
	static int		i = 0;
	
	newNode = (t_tet *)malloc(sizeof(t_tet));
	tmp = (*target);
	newNode->width = count_width(input, 4);
	newNode->height = count_height(input, 4);
	newNode->idx = i++;	/*piece는 0번째부터 시작하고 몇번째까지 있는지 알려준다 */
	newNode->mc = 0;
	newNode->input = ft_strdup(input);
	/*문자열을 list에 넣을 때에는 바로 넣을 수 없고 문final_list.c자열 크기만큼 malloc을 해야함, free는 마지막에 하기 */
	newNode->next = NULL;

	if (!tmp)
	{
		(*target) = newNode;
	}
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
	}
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
