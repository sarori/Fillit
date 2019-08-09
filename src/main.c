/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:46:43 by sapark            #+#    #+#             */
/*   Updated: 2019/08/09 15:52:58 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_tet	*head;
	int		fd;
	int		size;

	head = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("put ./fillit file name\n");
		return (1);
	}
	read_file(fd, &head);
	size = calculate_board_size(&head);
	play_tetrimino(&head, size);
	clear_lst(&head);
	return (0);
}
