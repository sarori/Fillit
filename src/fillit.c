/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/07/27 23:44:34 by hnam             ###   ########.fr       */
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
	// sort_input_cases(&head);
	// put_piece(print_tetriminoes, board);
	// return (0);
	// t_tet *tmp = head;
	// while (tmp)
	// {
	// 	printf("[width] : %d\n", tmp->width);
	// 	printf("[height] : %d\n", tmp->height);
	// 	printf("[input] : %s\n", tmp->input);
	// 	// printf("[idx] : %d\n", head->idx);
	// 	// printf("[mc] : %d\n", head->mc);
	// 	printf("\n");
	// 	tmp = tmp->next;
	// }

	board = sort_input_cases(&head);
	// while (head)
	// {
	// 	printf("[input] : %s\n\n", head->input);
	// 	head = head->next;
	// }
	// return (0);
	if (fillit(head, board) == YES)
		return (print_tetriminoes(board, head->size));
	else
	{
		printf("need to be bigger\n");
		// reset_value(tetriminoes);
		return (0);
		// return (put_piece(head, board));
	}

	//ft_strdel(&board);
	return (0);
}

// void	reset_value(t_tet **tetriminoes)
// {
// 	t_tet	*tmp;


// }
