/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/07/27 17:03:27 by sapark           ###   ########.fr       */
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
	char	*board;

	read_file(fd, &head);
	
	// printf("%s\n", head->input);
	// for(int i = 0; i < 6; i++)
	// {
	// 	print_tetriminoes(move_piece(head, 4, i), 4);
	// 	printf("\n");
	// }
	// while (head)
	// {
	// 	// printf("[width] : %d\n", head->width);
	// 	// printf("[height] : %d\n", head->height);
	// 	printf("[input] : %s\n", head->input);
	// 	// printf("[idx] : %d\n", head->idx);
	// 	// printf("[mc] : %d\n", head->mc);
	// 	printf("\n");
	// 	head = head->next;
	// }
	
	// sort_input_cases(&head);
	// put_piece(print_tetriminoes, board);

	board = ft_strdup(sort_input_cases(&head));
	if (put_piece(&head, board) == YES)
		return (print_tetriminoes(board, head->size));
	else
	{
		// reset_value(tetriminoes);
		return (put_piece(&head, board));
	}
	
	//ft_strdel(&board);
	return (0);
}

// void	reset_value(t_tet **tetriminoes)
// {
// 	t_tet	*tmp;


// }