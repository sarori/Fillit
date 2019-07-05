/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:40:07 by sapark            #+#    #+#             */
/*   Updated: 2019/07/04 17:50:01 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     calculate_width(char *input)
{
    int width;

    width = 0;
    if (input[0] == '#' || input[4] == '#' || input[8] == '#' || input[12] == '#')
        width++;
    if (input[1] == '#' || input[5] == '#' || input[9] == '#' || input[13] == '#')
        width++;
    if (input[2] == '#' || input[6] == '#' || input[10] == '#' || input[14] == '#')
        width++;
    if (input[3] == '#' || input[7] == '#' || input[11] == '#' || input[15] == '#')
        width++;
    return (width);
}

int     calculate_height(char *input)
{
    int height;

    height = 0;
    if (input[0] == '#' || input[1] == '#' || input[2] == '#' || input[3] == '#')
        height++;
    if (input[4] == '#' || input[5] == '#' || input[6] == '#' || input[7] == '#')
        height++;
    if (input[8] == '#' || input[9] == '#' || input[10] == '#' || input[11] == '#')
        height++;
    if (input[12] == '#' || input[13] == '#' || input[14] == '#' || input[15] == '#')
        height++;
    return (height);
}

// void    insertNode(node **target, char *data)
// {
// 	node *newNode;
// 	newNode = (node *)malloc(sizeof(node));
// 	node *tmp = *target;
// 	newNode->data = data;
// 	newNode->next = NULL;
// 	if (!tmp)
// 	{
// 		(*target) = newNode;
// 	}
// 	else
// 	{
// 		while(tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = newNode;
// 	}
// }

void    insertNode(t_tet **target, char *input)
{   
	t_tet   *newNode;
    t_tet   *tmp;
	
    newNode = (t_tet *)malloc(sizeof(t_tet));
	tmp = (*target);
    newNode->width = calculate_width(input);
    newNode->height = calculate_height(input);
    newNode->input = ft_strdup(input);
    newNode->next = NULL;

	if (!tmp)
	{
        printf("first\n");
		(*target) = newNode;
	}
	else
	{
        printf("next %s\n", input);

		while(tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
	}
}

// void    store_data(char *input)
// {
//     /*list 사용해서 데이터 저장하기 */
//     t_tet *tetrimino = NULL;

//     // tetrimino->width = calculate_width(input);
//     // tetrimino->height = calculate_height(input);
//     // tetrimino->input = input;
//     // tetrimino->next = next;
//     insertNode(&tetrimino, input);
    
    
// }


char    *alpha(char *input, int num)
{
    /*num == 0부터 시작 */
    int i;

    i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '#')
            input[i] = 'A' + num;
        i++;
    }
    return (input);
}