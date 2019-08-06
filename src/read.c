/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:19:53 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 20:01:24 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	read_file(int fd, t_tet **head)
{
	int		cnt;
	char	*line;
	char	input[17];

	cnt = 0;
	ft_strchr(input, '0');
	while (get_next_line(fd, &line) > 0)
	{
		cnt++;
		ft_strcat(input, line);
		if (cnt == 5 && ft_strlen(input) == 16)
		{
			cnt = 0;
			insert_node(head, validate_tetriminoes(input));
			ft_memset(input, '\0', 17);
		}
		ft_strdel(&line);
	}
	if (cnt == 4 && ft_strlen(input) == 16)
		insert_node(head, validate_tetriminoes(input));
	else
		print_error();
}
