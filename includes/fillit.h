/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:21:39 by sapark            #+#    #+#             */
/*   Updated: 2019/08/09 15:43:22 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_SIZE 4
# define SPECIAL_CASE "AA\nAA\n"
# define YES 1
# define NO	0

typedef struct		s_tet
{
	char			*input;
	char			**p_set;

	int				size;
	int				width;
	int				height;
	int				pmc;
	int				mc;
	int				idx;
	struct s_tet	*next;
}					t_tet;

/*
**	====================calculate========================
*/
int					count_piece(t_tet **tetriminoes);
int					calculate_size(t_tet **tetriminoes);
int					count_width(char *input, int size);
int					count_height(char *input, int size);
int					count_hash(char *input);
/*
**	======================check==========================
*/
char				*check_x(char *piece, char *x_axis, int size);
char				*check_y(char *piece, char *y_axis, int size);
int					validate_xshape(char *piece, char *moved, int size);
int					validate_yshape(char *piece, char *moved, int size);
int					check_position(char *piece, char *board, int idx);
/*
**	======================free===========================
*/
void				clear_lst(t_tet **tetriminoes);
void				clear_valid_set(t_tet *tetriminoes);
/*
**	====================fillit===========================
*/
int					fillit(t_tet *tet, char *board, int size);
char				*put_piece(char *piece, char *board);
void				revert_board(char *board, char *tmp);
/*
**	=====================place===========================
*/
void				sort_input_cases(t_tet **tetriminoes, int size);
char				*ft_countmove(char *dst, int move_cnt);
/*
**	=====================print===========================
*/
void				print_alpha(t_tet *tet, char *board, int size);
char				*change_alpha(char *board, char *piece, int idx);
void				print_error(void);
/*
**	======================read===========================
*/
void				read_file(int fd, t_tet **head);
/*
**	=====================solve===========================
*/
void				make_valid_set(t_tet *tmp, int size);
void				play_tetrimino(t_tet **tetriminoes, int size);
/*
**	=====================store===========================
*/
void				insert_node(t_tet **target, char *input);
char				*create_board(int size);
void				possible_mc(t_tet **tetriminoes, int size);
int					calculate_board_size(t_tet **tetriminoes);
/*
**	===================transform==========================
*/
void				change_input_shape(t_tet **tetriminoes, int size);
char				*trim_edge(char *input, int size);
void				enlarge_piece(t_tet **tetriminoes, int size, int len);
char				*insert_edge(char *input, int size, int len);
/*
**	===================-validate==========================
*/
void				check_condition(char *input);
int					binary_conversion(char *input);
char				*validate_tetriminoes(char *input);
char				*transform_character(char *input);

#endif
