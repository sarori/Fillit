/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 12:35:38 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_tet	*head;
	int		fd = open(argv[1], O_RDONLY);
	int		size;
	char	*board;

	head = NULL;
	if (argc != 2)
		return (0);

	read_file(fd, &head);
	/*head->size = calculate_size(&head);	head에만 initialize해서 두번째꺼부터 쓰레기값 들어가있다. */
	size = calculate_size(&head);
	if (size >= 5)
		enlarge_piece(&head, size, size - 4);
	while (1)
	{
		sort_input_cases(&head, size);
		board = create_board(size);
		
		make_valid_set(head, size);
		if (fillit(head, board, size) == YES)
			break ;
		else
		{
			ft_strdel(&board);	/*커질때 이전 보드 필요없고 새로만드니까 free해야한다. */
			enlarge_piece(&head, ++size, 1);
		}
	}
	print_alpha(head, board, size);
	ft_strdel(&board);
	clear_lst(&head);
	// while (1)
	// 	sleep(1);
	return (0);
}
