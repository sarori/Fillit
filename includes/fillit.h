/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:21:39 by sapark            #+#    #+#             */
/*   Updated: 2019/07/04 17:41:07 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
# define FILLIT_H
# include "libft.h"

# include <fcntl.h>         /* open -> O_WRONLY */
# include <unistd.h>        /* write(), read(), close()*/ 
# include <stdlib.h>		//melloc

//
#include <stdio.h>
//


typedef struct		s_tet
{
	char			*input;
	int				width;
	int				height;
	char			alpha;
	struct s_tet	*next;
}					t_tet;

//fillit함수 prototype
void				check_condition(char *input);
void				two_dprint(char *arr);
int					binary_conversion(char *input);
char				*validate_tetriminoes(char *input);
char				*transform_character(char *input);
void 				read_file(int fd, t_tet **head);


int     			calculate_width(char *input);
int    				calculate_height(char *input);
char    			*alpha(char *input, int num);
void				store_data(char *input);
void				insertNode(t_tet **target, char *input);
#endif