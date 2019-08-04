/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:30:51 by sapark            #+#    #+#             */
/*   Updated: 2019/08/03 18:39:06 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*check_x(char *piece, char *x_axis, int size)
{
	int x;
	int y;
	int x_num;

	x = 0;
	y = 0;
	x_num = 0;
	while (y < size)
	{
		x = 0;
		x_num = 0;
		while (x < size)
		{
			if (piece[x * size + y] == '#')
				x_num++;
			x++;
		}
		x_axis[y] = x_num + '0';
		y++;
	}
	return (x_axis);
}

char	*check_y(char *piece, char *y_axis, int size)
{
	int		x;
	int		y;
	int		y_num;

	x = 0;
	y = 0;
	y_num = 0;
	while (x < size)
	{
		y = 0;
		y_num = 0;
		while (y < size)
		{
			if (piece[x * size + y] == '#')
				y_num++;
			y++;
		}
		y_axis[x] = y_num + '0';
		x++;
	}
	return (y_axis);
}

int		validate_xshape(char *piece, char *moved, int size)
{
	int		valid;
	char	*original_x;
	char	*moved_x;
	char	*tmp1;
	char	*tmp2;

	original_x = ft_strnew(size);
	moved_x = ft_strnew(size);
	original_x = check_x(piece, original_x, size);
	moved_x = check_x(moved, moved_x, size);
	tmp1 = ft_strtrimby(original_x, '0');
	tmp2 = ft_strtrimby(moved_x, '0');	/*여기서도 malloc하므로 free 해결해야한다. */
	ft_strdel(&original_x);
	ft_strdel(&moved_x);
	valid = strcmp(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (valid == 0 ? 1 : 0);
}

int		validate_yshape(char *piece, char *moved, int size)
{
	int		valid;
	char	*original_y;
	char	*moved_y;
	char	*tmp1;
	char	*tmp2;

	original_y = ft_strnew(size);
	moved_y = ft_strnew(size);
	original_y = check_y(piece, original_y, size);
	moved_y = check_y(moved, moved_y, size);
	tmp1 = ft_strtrimby(original_y, '0');
	tmp2 = ft_strtrimby(moved_y, '0');	/*여기서도 malloc하므로 free 해결해야한다. */
	ft_strdel(&original_y);
	ft_strdel(&moved_y);
	valid = strcmp(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	return (valid == 0 ? 1 : 0);
}

int		check_position(char *piece, char *board, int idx)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	while (board[++i])
	{
		if (piece[i] == '#' || board[i] == '#')
			cnt++;
	}
	if (cnt == (idx + 1) * DEFAULT_SIZE)
		return (YES);		/*overlap 되지 않을때 = 적합한 위치일 때 */
	return (NO);
}
