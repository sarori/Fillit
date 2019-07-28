/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:40:07 by sapark            #+#    #+#             */
/*   Updated: 2019/07/23 17:41:55 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    insertNode(t_tet **target, char *input)
{   
	t_tet   		*newNode;
    t_tet   		*tmp;
	static int 		i = 0;
	
    newNode = (t_tet *)malloc(sizeof(t_tet));
    tmp = (*target);

    newNode->width = count_width(input, 4);
    newNode->height = count_height(input, 4);
    newNode->length = calculate_length(input);
	newNode->idx = i++;	/*piece는 0번째부터 시작하고 몇번째까지 있는지 알려준다 */
	newNode->mc = 0;
    newNode->input = ft_strdup(input);
    /*문자열을 list에 넣을 때에는 바로 넣을 수 없고 문final_list.c자열 크기만큼 malloc을 해야함, free는 마지막에 하기 */
    newNode->next = NULL;

	if (!tmp)
	{
        // printf("first\n");
		(*target) = newNode;
	}
	else
	{
        // printf("next %s\n", input);

		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
	}
}

// void	squareboard(t_tet **tetriminoes)
// {
// 	char	*board;		/*char *는 처음에  선언하고 나중에 값 집어넣으면 된다. (선언과 동시에 초기화하면 norm 걸림)*/
// 	int		total_size;

// 	total_size = calculate_size(tetriminoes) * calculate_size(tetriminoes);
// 	board = ft_memalloc(total_size + 1);	/*원하는 size만큼 char * 만들고 싶을때 size만큼 malloc해야한다.  */
// 	ft_memset(board, '.', total_size);
// 	board[total_size] = '\0';			/* null 값에 접근해도 seg fault 안뜸 */
// 	sort_cases(tetriminoes, board, calculate_size(tetriminoes));
// 	// free(board)
// }

void		possible_mc(t_tet **tetriminoes, int size)
{
	t_tet	*tmp;

	tmp = (*tetriminoes);
	while (tmp)
	{
		tmp->pmc = ((size - (tmp->width) + 1) * (size - (tmp->height) + 1));
		tmp = tmp->next;
	}
}
