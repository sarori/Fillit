/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:21:39 by sapark            #+#    #+#             */
/*   Updated: 2019/07/26 19:04:40 by sapark           ###   ########.fr       */
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
# define DEFAULT_SIZE 4
# define SPECIAL_CASE "AA\nAA"
# define YES 1
# define NO	2

typedef struct		s_tet
{
	char			*input;
	char			*left;	/*piece의 모양 기억할 변수 */
	char			*tmp_piece;	/*이동할 변수 */

	int				size;
	int				width;
	int				height;
	int				length;
	int				pmc;
	int				mc;
	int				idx;	/*몇번째 piece인지 기억 */
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
void				print_error(void);


int     			calculate_width(char *input);
int    				calculate_height(char *input);
void    			alpha(char *input, int num);
void				store_data(char *input);
void				insertNode(t_tet **target, char *input);
void				squareboard(t_tet **tetriminoes);
int     			calculate_size(t_tet **tetriminoes);

int					calculate_length(char *input);
//void				place_piece(t_tet **tetriminoes, char *board);
void				special_case(t_tet **tetriminoes, char *board, int size);
int					print_tetriminoes(char *board, int	size);
int					count_piece(t_tet **tetriminoes);
void				general_case(t_tet **tetriminoes, char *board, int size);


// void				sort_cases(t_tet **tetriminoes, char *board, int size);

// char				*move_piece(t_tet **tetriminoes, int size, int move_cnt);
// char				*move_piece(char *left, char *tmp_piece, int size, int pmc);
// void				place_piece(t_tet **tetriminoes, char *board, int size);

void				possible_mc(t_tet **tetriminoes, int size);
char				*ft_countmove(char *dst, int move_cnt);

int     			count_width(char *input, int size);
int     			count_height(char *input, int size);
int					count_hash(char *input);
// char				*move_piece(t_tet *tmp, int size, int cnt);
void				enlarge_board(t_tet **tetriminoes, int size);
void				revert_board(char *board, t_tet *tmp, int index);

/* =================================================================================== */


char    			*sort_input_cases(t_tet **tetriminoes);
void    			change_input_shape(t_tet **tetriminoes);
int					put_piece(t_tet **tetriminoes, char *board);

int					check_position(char *piece, char *board, int call);
char    			*trim_edge(char *input, int size);
char				*move_piece(t_tet *tmp);
char    			*create_board(int size);

#endif