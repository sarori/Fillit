/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/07/31 19:40:06 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_tet	*head;

	head = NULL;
	if (argc != 2)
		return (0);
	int		fd = open(argv[1], O_RDONLY);
	int		size;
	char	*board;

	read_file(fd, &head);
	/*head->size = calculate_size(&head);	head에만 initialize해서 두번째꺼부터 쓰레기값 들어가있다. */
	size = calculate_size(&head);
	if (size == 2)
		ft_putstr(SPECIAL_CASE);
	
	else
	{
		if (size == 5)
			enlarge_piece(&head, size);
		while (1)
		{
			
			board = sort_input_cases(&head, size);
			if (fillit(head, board, size) == YES)
			{
				print_alpha(head, board, size);
				return (0);
			}
			else
			{
				size++;
				enlarge_piece(&head, size);
			}
		}
	}
	ft_strdel(&board);
	return (0);
}
