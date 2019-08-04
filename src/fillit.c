/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/08/04 01:23:59 by sapark           ###   ########.fr       */
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
			clear_valid_set(head);
			ft_strdel(&board);	/*커질때 이전 보드 필요없고 새로만드니까 free해야한다. */
			enlarge_piece(&head, ++size, 1);
		}
	}
	print_alpha(head, board, size);
	ft_strdel(&board);
	clear_lst(&head);
	close(fd);
	// while (1)
	// 	sleep(1);
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

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '#')
			board[i] = '.';
	}
}
