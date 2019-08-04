/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/03 18:44:21 by sapark           ###   ########.fr       */
=======
/*   Updated: 2019/07/27 23:44:34 by hnam             ###   ########.fr       */
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
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
<<<<<<< HEAD
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
			// VALID SET FREE
			ft_strdel(&board);	/*커질때 이전 보드 필요없고 새로만드니까 free해야한다. */
			enlarge_piece(&head, ++size, 1);
		}
	}
	print_alpha(head, board, size);
	ft_strdel(&board);
	clear_lst(&head);
	while (1)
		sleep(1);
=======

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
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
	return (0);
}

int		fillit(t_tet *tet, char *board, int size)
{
	int	mc;
	
	mc = 0;
	while (tet && mc < tet->pmc)
	{
		// tmp[mc] = move_piece(tet, size, mc);	/*3이나 다른 크기에도 할 수 있어야함. */
		if (check_position(tet->p_set[mc], board, tet->idx))
		{
			board = put_piece(tet->p_set[mc], board);
			tet->mc = mc;
			if (fillit(tet->next, board, size))
				return (YES);
			else
			{
				revert_board(board, tet->p_set[tet->mc]);
				mc++;
				tet->mc = 0;/*tet=->mc는 최종 확정 될때만 넣기 */
			}
		}
		else
			mc++;;
	}
	return (tet == NULL);/*더이상 체크할 게 없을 경우 */
}

char	*put_piece(char *piece, char *board)
{
	int	i;

	i = -1;
	while (board[++i])
	{
		if (board[i] == '#' || piece[i] == '#')
			board[i] = '#';
		else
			board[i] = '.';
	}
	return (board);
}

void	revert_board(char *board, char *tmp)
{
	int		i;

<<<<<<< HEAD
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
			board[i] = '.';
	}
}
=======
// }
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
