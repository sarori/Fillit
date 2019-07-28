#include "fillit.h"

char    *sort_input_cases(t_tet **tetriminoes)
{
    t_tet   *tmp;

    tmp = (*tetriminoes);
    calculate_size(tetriminoes);
    possible_mc(tetriminoes, tmp->size);
    if (tmp->size == 2)
        ft_putstr(SPECIAL_CASE);
    else
    {
        if (tmp->size == 3)
            change_input_shape(tetriminoes);
        // create_board(tmp->size);
    }
    return (create_board(tmp->size));
}

char    *create_board(int size)
{
    char    *board;

    board = ft_memalloc(size * size + 1);
    ft_memset(board, '.', size * size);
    board[size * size] = '\0';
    //free(board);
    return (board);
}

void    change_input_shape(t_tet **tetriminoes)
{
    t_tet   *tmp;

    tmp = (*tetriminoes);
    while (tmp)
    {
        tmp->input = trim_edge(tmp->input, DEFAULT_SIZE);
        tmp = tmp->next;
    }
}

int    put_piece(t_tet **tetriminoes, char *board)
{
    t_tet   *tmp;

    tmp = (*tetriminoes);
    while (tmp)
    {
        printf("======================================\n");
        printf("[idx : %d]\n", tmp->idx);
        tmp->tmp_piece = ft_strdup(tmp->input); // malloc
        printf("overlap :%d\n", check_position(tmp->tmp_piece, board, tmp->idx));
        while (check_position(tmp->tmp_piece, board, tmp->idx) == 0 && tmp->mc < tmp->pmc - 1)
        {
            tmp->tmp_piece = move_piece(tmp);
            printf("tmp->tmp_piece : %s\n", tmp->tmp_piece);
            (tmp->mc)++;
            printf("tmp->mc : %d\n", tmp->mc);
           
        }
        printf("board : %s\n", board);
        // printf("tmp->mc : %d\n", tmp->mc);
        printf("(tmp->mc : %d tmp->pmc - 1 : %d, yes or no : %d\n",tmp->mc, tmp->pmc - 1, check_position(tmp->tmp_piece, board, tmp->idx));
        if ((tmp->mc == tmp->pmc - 1) && check_position(tmp->tmp_piece, board, tmp->idx) == 0)
            return (NO);
        tmp = tmp->next;
    }
    return (YES);
    //ft_strdel(&(tmp->tmp_piece));
}

char    *move_piece(t_tet *tmp)
{
    char    *ap;
    char    *bp;
    printf("second\n");

    ap = ft_strdup(tmp->tmp_piece);
    // ap = ft_countmove(ap, 1);

    // printf("ap : %s\n", ap);


    while (count_hash(ap) == 4)
    {
        bp = ft_countmove(ap, 1);
        free(ap);
        ap = bp;
        if(count_width(ap, tmp->size) == count_width(tmp->input, tmp->size)
            && count_height(ap, tmp->size) == count_height(tmp->input, tmp->size))
            return (ap);
    }
    return (NULL);
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

// char    *move_piece(t_tet *tmp)
// {
//     char    *ap;
//     char    *bp;
//     printf("second\n");

//     ap = ft_strdup(tmp->tmp_piece);
//     // ap = ft_countmove(ap, 1);

//     // printf("ap : %s\n", ap);


//     while (count_hash(ap) == 4)
//     {
//         if(count_width(ap, tmp->size) == count_width(tmp->input, tmp->size)
//             && count_height(ap, tmp->size) == count_height(tmp->input, tmp->size))
//             return (ap);
//         else
//         {
//             bp = ft_countmove(ap, 1);
//             free(ap);
//             ap = bp;
//             if ((tmp->width == count_width(ap, tmp->size)) && (tmp->height == count_height(ap, tmp->size)))
// 				break;
//         }
//     }
//     return (NULL);
// }

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

int		check_position(char *piece, char *board, int idx)
{
	int		i;
	int		j;
	int		num;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	num = 0;
	len = ft_strlen(board);
	tmp = ft_strdup(board);
	while (len > i)
	{
		if (piece[i] == '#')
			tmp[j] = piece[i];
		i++;
		j++;
	}
	j = 0;
	while(len > j)
	{
		if (tmp[j] == '#')
			num++;
		j++;
	}
	if ((idx + 1) * DEFAULT_SIZE == num)
	{
		ft_strcpy(board, tmp);
		return (1);		/*overlap 되지 않을때 = 적합한 위치일 때 */
	}
	return (0);		/*overlap 될 때 = 이미 그 위치에 다른 piece가 있다.  */
	//free(tmp)
}