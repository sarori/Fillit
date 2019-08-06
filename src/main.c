/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:46:43 by sapark            #+#    #+#             */
/*   Updated: 2019/08/05 20:03:24 by sapark           ###   ########.fr       */
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
		return (0);
	read_file(fd, &head);
	size = calculate_board_size(&head);
	play_tetrimino(&head, size);
	clear_lst(&head);
	return (0);
}
