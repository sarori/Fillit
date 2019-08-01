/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:19:53 by sapark            #+#    #+#             */
/*   Updated: 2019/07/29 02:19:56 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	read_file(int fd, t_tet **head)
{
	int		cnt;
	char	*line;
	char	input[17] = {0};
	char	*tet;

	cnt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		cnt++;
		ft_strcat(input, line);
		if (cnt == 5 && ft_strlen(input) == 16)
		{
			cnt = 0;
			tet = validate_tetriminoes(input);
			insertNode(head, tet);
			ft_memset(input, '\0', 17);
		}
		free(line);
		line = NULL;
	}
	if (cnt == 4 && ft_strlen(input) == 16)
	{
		tet = validate_tetriminoes(input);
		insertNode(head, tet);
		ft_memset(input, '\0', 17);
	}
	else
		print_error();
}
