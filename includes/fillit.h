/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:21:39 by sapark            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/03 18:15:51 by sapark           ###   ########.fr       */
=======
/*   Updated: 2019/07/27 23:37:58 by hnam             ###   ########.fr       */
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

<<<<<<< HEAD
# include <fcntl.h>/* open -> O_WRONLY */
# include <unistd.h>/* write(), read(), close()*/ 
# include <stdlib.h>/*malloc */
=======
# include <fcntl.h>         /* open -> O_WRONLY */
# include <unistd.h>        /* write(), read(), close()*/
# include <stdlib.h>		//melloc
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18

//
#include <stdio.h>
//
# define DEFAULT_SIZE 4
# define SPECIAL_CASE "AA\nAA"
# define YES 1
# define NO	0

typedef struct		s_tet
{
	char			*input;
	char			*left;/*piece의 모양 기억할 변수 */
	char			*tmp_piece;/*이동할 변수 */
	char			**p_set;

	int				size;
	int				width;
	int				height;
	int				pmc;
	int				mc;
	int				idx;	/*몇번째 piece인지 기억 */
	struct s_tet	*next;
}					t_tet;

//fillit함수 prototype
void				check_condition(char *input);
int					binary_conversion(char *input);
char				*validate_tetriminoes(char *input);
char				*transform_character(char *input);
void 				read_file(int fd, t_tet **head);
void				print_error(void);

void				store_data(char *input);
void				insertNode(t_tet **target, char *input);
<<<<<<< HEAD
int					calculate_size(t_tet **tetriminoes);
=======
void				squareboard(t_tet **tetriminoes);
int	     			calculate_size(t_tet **tetriminoes);
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18

int					print_tetriminoes(char *board, int	size);
int					count_piece(t_tet **tetriminoes);
void				possible_mc(t_tet **tetriminoes, int size);
char				*ft_countmove(char *dst, int move_cnt);

int     			count_width(char *input, int size);
int					count_height(char *input, int size);
int					count_hash(char *input);
void				enlarge_board(t_tet **tetriminoes, int size);
<<<<<<< HEAD
void				sort_input_cases(t_tet **tetriminoes, int size);
=======
void	revert_board(char *board, t_tet *tet);
>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18

/* =================================================================================== */
int					fillit(t_tet *tet, char *board, int size);
void    			change_input_shape(t_tet **tetriminoes, int size);


char				*trim_edge(char *input, int size);
char				*create_board(int size);


char				*put_piece(char *piece, char *board);
int					check_position(char *piece, char *board, int idx);
char				*move_piece(t_tet *tmp, int size);
void				revert_board(char *board, char *tmp);
char				*change_alpha(char *board, char *piece, int idx);
void				print_alpha(t_tet *tet, char *board, int size);

char				*check_x(char *piece, char *x_axis, int size);
char				*check_y(char *piece, char *y_axis, int size);
int					validate_xshape(char *piece, char *moved, int size);
int					validate_yshape(char *piece, char *moved, int size);

<<<<<<< HEAD
char				*insert_edge(char *input, int size, int len);
void				enlarge_piece(t_tet **tetriminoes, int size, int len);
void				clear_lst(t_tet **tetriminoes);
void				make_valid_set(t_tet *tmp, int size);


=======
char    			*sort_input_cases(t_tet **tetriminoes);
void    			change_input_shape(t_tet **tetriminoes);
// int					put_piece(t_tet **tetriminoes, char *board);
// int					put_piece(t_tet *tet, char *board);

// int					check_position(char *piece, char *board, int call);
char    			*trim_edge(char *input, int size);
// char				*move_piece(t_tet *tmp);
char    			*create_board(int size);

char	*put_piece(char *piece, char *board);
int		fillit(t_tet *tet, char *board);
char	*move_piece(t_tet *tmp, int size, int cnt);
int		check_position(char *piece, char *board, int idx);

>>>>>>> 9a83fdd7ba0bcbe08a634b5cbd6df28c10571e18
#endif
