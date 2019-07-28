#include "fillit.h"

// int		check_position(char *piece, char *board, int call)
// {
// 	int		i;
// 	int		j;
// 	int		num;
// 	int		len;
// 	char	*tmp;

// 	i = 0;
// 	j = 0;
// 	num = 0;
// 	len = ft_strlen(board);
// 	tmp = ft_strdup(board);
// 	while (len > i)
// 	{
// 		if (piece[i] == '#')
// 			tmp[j] = piece[i];
// 		i++;
// 		j++;
// 	}
// 	j = 0;
// 	while(len > j)
// 	{
// 		if (tmp[j] == '#')
// 			num++;
// 		j++;
// 	}
// 	if ((call + 1) * DEFAULT_SIZE == num)
// 	{
// 		ft_strcpy(board, tmp);
// 		return (1);		/*overlap 되지 않을때 = 적합한 위치일 때 */
// 	}
// 	return (0);		/*overlap 될 때 = 이미 그 위치에 다른 piece가 있다.  */
// 	//free(tmp)
// }


// void	place_piece(t_tet **tetriminoes, char *board, int size)
// {
// 	t_tet	*tmp;

// 	tmp = (*tetriminoes);
// 	possible_mc(tetriminoes, size);

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

int		count_hash(char *input)
{
	int		i;
	int		hashcnt;

	i = -1;
	hashcnt = 0;
	while(input[++i] != '\0')
	{
		if (input[i] == '#')
			hashcnt++;
	}
	if (hashcnt == 4)
		return(hashcnt);
	return(0);
		
}

// char	*move_piece(t_tet *tmp, int size, int cnt)
// {
// 	int		i;
// 	char	*ap;	/*tmp->tmp_piece에 최종 valid한 piece만 넣고 싶어서 ap임시로 사용. */
// 	char	*bp;

// 	i = 0;
// 	ap = ft_strdup(tmp->input);
// 	while (count_hash(ap) == 4)
// 	{
// 		if ((tmp->width == count_width(ap, size)) && (tmp->height == count_height(ap, size)) && cnt == 0)
// 		{
// 			tmp->mc += 1;
// 			printf("taaaaaaaaaaaamp->mc : %d\n", tmp->mc);
// 			return(ap);
// 		}
// 		else
// 		{
// 			bp = ft_countmove(ap, 1);
// 			free(ap);
// 			ap = bp;	/*반복하다보면 같은 곳을 가리키므로 free한번만 해도 된다. */
// 			if ((tmp->width == count_width(ap, size)) && (tmp->height == count_height(ap, size)))
// 				(cnt)--;
// 		}
// 	}
// 	return (NULL);
// }

// void	enlarge_board(t_tet **tetriminoes, int size)
// {
// 	char	*new_board;		/*char *는 처음에  선언하고 나중에 값 집어넣으면 된다. (선언과 동시에 초기화하면 norm 걸림)*/
// 	int		total_size;

// 	total_size = size * size;
// 	new_board = ft_memalloc(total_size + 1);	/*원하는 size만큼 char * 만들고 싶을때 size만큼 malloc해야한다.  */
// 	ft_memset(new_board, '.', total_size);
// 	new_board[total_size] = '\0';			/* null 값에 접근해도 seg fault 안뜸 */
// 	place_piece(tetriminoes, new_board, size);
// 	// free(board)
// }



// // printf("first\n");
// 	// char	*square;
// 	// square = ft_memalloc(size * size + 1);
// 	// ft_memset(square, '.', size * size);

// 	// printf("emptdy - square : %s\n", square);
// 	// printf("pmc : %d\n", pmc);

