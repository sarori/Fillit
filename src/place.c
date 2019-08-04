/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:18:23 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 18:40:08 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "fillit.h"
=======
// 	while (tmp)
// 	{
// 		tmp->left = ft_strdup(tmp->input);	/*처음에 초기화 안해도 되고 tetriminoes를 사용할 수 있는 모든 곳에서 가능 */
// 		tmp->tmp_piece = ft_strdup(tmp->input);
// 		while (check_position(tmp->tmp_piece, board, tmp->idx) == 0 && (tmp->pmc) > (tmp->mc))
// 		{
// 			tmp->tmp_piece = move_piece(tmp, size, tmp->mc);
// 			printf("tmp->tmp_piece : %s\n", tmp->tmp_piece);
// 			printf("tmp->mc : %d\n", tmp->mc);
// 			// (tmp->mc)++;
// 		}
// 		printf("1111tmp->pmc : %d\n", tmp->pmc);
// 		printf("2222tmp->mc : %d\n", tmp->mc);
// 		printf("3333tmp->tmp_piece : %s\n", tmp->tmp_piece);
// 		// tmp->mc += 1;
// 		printf("[pre_board]\n");
// 		print_tetriminoes(board, size);
// 		if ((check_position(tmp->tmp_piece, board, tmp->idx) == 0) && (tmp->pmc) -1 == tmp->mc)
// 		{
// 			printf("first\n");
// 			tmp->mc = 0;
// 			revert_board(board, tmp, tmp->idx);

// 			place_piece(tetriminoes, board, size);
// 		}
// 		printf("\n");
// 		printf("[post_board]\n");
// 		print_tetriminoes(board, size);
// 		printf("==============================================\n");
// 		tmp = tmp->next;
// 	}
// 	//if	/*조건 달아서 다시 */
// 	//print_tetriminoes(board, size);
// 	//free(tmp->left)
// 	//free(tmp->tmp_piece)
// }

// void	revert_board(char *board, t_tet *tmp, int index)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(tmp->tmp_piece);
// 	while (tmp && index > 0)
// 	{
// 		tmp = tmp->next;
// 		index--;
// 	}
// 	printf("the piece to remove : %s", tmp->tmp_piece);
// 	while (i++ < len)
// 	{
// 		if (tmp->tmp_piece[i] == '#')
// 			board[i] = '.';
// 	}
// 	printf("revert_board : %s\n", board);
// }

// char	*ft_countmove(char *dst, int move_cnt)	/*나중에 libft함수 안에 넣기  */
// {
// 	char	*tmp;
// 	int		i;
// 	int		len;

// 	tmp = ft_strdup(dst);
// 	len = ft_strlen(dst);
// 	i = 0;

// 	if (!dst)
// 		return (NULL);
// 	while(i < move_cnt)
// 		tmp[i++] = '.';
// 	i = 0;
// 	while (move_cnt < len)
// 		tmp[move_cnt++] = dst[i++];
// 	return (tmp);
// }
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18

void	sort_input_cases(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	possible_mc(tetriminoes, size);
	if (size == 2)
	{
		ft_putstr(SPECIAL_CASE);
		exit(0);
	}
<<<<<<< HEAD
	else if (size == 3)
		change_input_shape(tetriminoes, size);
=======
	if (hashcnt == 4)
		return(hashcnt);
	return(0);

>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
}

char	*ft_countmove(char *dst, int move_cnt)
{
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_strdup(dst);
	len = ft_strlen(dst);
	i = 0;
	if (!dst)
		return (NULL);
	while(i < move_cnt)
		tmp[i++] = '.';
	i = 0;
	while (move_cnt < len)
		tmp[move_cnt++] = dst[i++];
	return (tmp);
}
