/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:17:53 by sapark            #+#    #+#             */
/*   Updated: 2019/07/29 02:17:58 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	two_dprint(char *arr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(arr);
	while (len > i)
	{
		if (i % 4 == 3)
		{
			printf("%c", arr[i]);
			printf("\n");
		}	
		else
		{
			printf("%c", arr[i]);
		}
		i++;
	}
}
