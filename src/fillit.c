/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapark <sapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:17:06 by sapark            #+#    #+#             */
/*   Updated: 2019/07/01 01:11:23 by sapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* Validate part
void		check_condition(char *input)
{
	int		i;
	int		hashcnt;
	int		dotcnt;

	i = -1;
	hashcnt = 0;
	dotcnt = 0;
	while(input[++i] != '\0')
	{
		if (input[i] == '#')
			hashcnt++;
		if (input[i] == '.')
			dotcnt++;
	}
	if 	(hashcnt != 4 || dotcnt != 12)
	{
		write(1, "error\n", 6);
		exit(0);
	}
}

int		binary_conversion(char *input)
{
	int	sum;
	int	len;
	int	power;

	len = ft_strlen(input);
	sum = 0;
	power = 1;
	while (len > 0)
	{
		if (input[len - 1] == '#')
			sum = 1 * power + sum;
		if (input[len - 1] ==  '.')
			sum =  power * 0 + sum;
		power = power * 2;
		len--;
	}
	printf("sum : %d\n", sum);
	return (sum);
}

int		validate_tetriminoes(char *input)
{
	int	i;
	int	sum;
	static int valid_input[19] = {34952, 61440, 52224, 35008, 11776, 50240,
							19968, 19520, 35968, 58368, 50688, 19584, 27648,
							35904, 17600, 57856, 51328, 36352, 59392};

	i = 0;
	sum = binary_conversion(input);
	while (i < 19)
	{
		if (valid_input[i] == sum)
			return (1);
		i++;
	}
	write(1, "error\n", 6);
	exit(0);
}

char	*transform_character(char *input)
{
	top-left에 따라 character이동 시키기 전에 invalid input제거 해야한다. 
	int	len;

	len = (input) ? ft_strlen(input) : 0;
	check_condition(input);
	while (len-- > 0)
	{
		while (input[0] != '#' && input[4] != '#' && input[8] != '#' && input[12] != '#')
			ft_memmove(input, input + 1, 17);
		while (input[0] != '#' && input[1] != '#' && input[2] != '#' && input[3] != '#')
			ft_memmove(input, input + 4, 17);
		if ((input[0] == '#' || input[1] == '#' || input[2] == '#')
			&& (input[0] == '#' || input[4] == '#' || input[8] == '#'))
			break;
	}
	return (input);
}
*/


/*Read_part
void read_file(int fd)
{
	int		cnt;
	char	*line = NULL;
	char	input[17] = {0};
	char	*tet = NULL;

	cnt = 0;
	while (get_next_line(fd, &line) > 0)
	{
		cnt++;
		ft_strcat(input, line);
		if (cnt == 5 && ft_strlen(input) == 16)
		{
			cnt = 0;
			free(line);
			line = NULL;
			tet = transform_character(input);
			while (tet && ft_strlen(tet) < 16)
				ft_strcat(tet, ".");
			validate_tetriminoes(input);
			two_dprint(tet);
			ft_memset(input, '\0', 17);
		}
	}
	if (cnt == 4 && ft_strlen(input) == 16) //마지막이라는것의 조건 더 달아야함.
	{
		free(line);
		line = NULL;
		tet = transform_character(input);
		while (ft_strlen(tet) < 16)
			ft_strcat(tet, ".");
		validate_tetriminoes(input);
		two_dprint(tet);
		ft_memset(input, '\0', 17);
	}
	// if (cnt != 4 || ft_strlen(input) != 16)
	else
	{
		write(1, "error\n", 6);
		exit(0);
	}
}
*/

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int		fd = open(argv[1], O_RDONLY);
	read_file(fd);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 		return (0);
// 	int	fd;
// 	char	*line = NULL;
// 	// char	*input = NULL;

// 	fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		printf("[read line] : %s\n", line);
// 		// ft_strcpy(input, line);
// 		// printf("[input] : %s\n", input);
// 		// if (ft_strlen(input) == 16) //복사한 string이 16일때만
// 		// 	check_condition(&input);
// 		free(line);
// 		//free(input);
// 		line = NULL;
// 	}
// 	close(fd);
//     return (0);
// }

/*main
int main(int argc, char **argv)
{
	if (ac != 2)
		return (0);
	
	char	*line = NULL:
	int		fd = open(av[1], O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		line = NULL:
	}
	return (0);
}
*/



// int main(int argc, char *argv[])
// {
// 	t_tet	*list;

// 	list = transform_input(argv[1]);

// 	if (argc != 2)
// 		return (0);
// 	int		i;
// 	int		j;
// 	int		z;
// 	int		fd;
// 	int		cnt;
// 	char	*line = NULL;
// 	char	arr[5][4];
// 	char	input[17] = {0};
	
// 	i = 0;
// 	j = 0;
// 	z = 0;
// 	cnt = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		cnt++;
// 		printf("[read line] : %s\n", line);
// 		ft_strcat(input, line);

// 		printf("[input] : %s\n", input);
// 		printf("%d\n", cnt);

		


// 		// if (ft_strlen(input) == 16) //복사한 string이 16일때만
// 		// 	check_condition(&input);
// 		if (cnt == 5)
// 		{
// 			cnt = 0;
// 			free(line);
// 			line = NULL;
// 			printf("***[input] : %s\n", input);
// 			check_condition(input);
// 			ft_memset(input, '\0', 17);
// 			printf("after memset input : %s\n", input);
// 		}
// 		else
// 		{
// 			printf("ERROR\n");
// 			// return ;		//error처리하기 -> tetrimino자체에 에러가 있는 경우 그 다음에 tetrimino가 valid 하더
// 		}
		
// 	}
	
// 	close(fd);
//     return (0);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
	
// 	int		cnt;
// 	char	*line = NULL;
// 	int		fd = open(argv[1], O_RDONLY);
// 	char	input[17] = {0};
// 	char	*tet = NULL;


// 	cnt = 0;
// 	void read_file(fd)
// 	{

// 	}

// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		cnt++;
// 		// printf("[read line] : %s\n", line);
// 		ft_strcat(input, line);

// 		// printf("[input] : %s\n", input);
		
// 		if (cnt == 5)
// 		{
// 			cnt = 0;
// 			free(line);
// 			line = NULL;
// 			// printf("***[input] : %s\n", input);
// 			tet = transform_character(input);
// 			while (tet && ft_strlen(tet) < 16)
// 				ft_strcat(tet, ".");
// 			// printf("tet :%s\n", tet );
// 			two_dprint(tet);

// 			//tetriminoes = ft_strsplit(input, '\n');
// 			//printf("tetriminoes : %s\n", *tetriminoes);
// 			//printf("%d\n", check_condition(tetriminoes));
// 			ft_memset(input, '\0', 17);
// 			// printf("after memset input : %s\n", input);
// 		}
// 		else
// 		{
// 			printf("\n");
// 			// return ;		//error처리하기 -> tetrimino자체에 에러가 있는 경우 그 다음에 tetrimino가 valid 하더
// 		}
// 	}
// 	if (cnt == 4 && line) //마지막이라는것의 조건 더 달아야함.
// 	{
// 		free(line);
// 		line = NULL;
// 		// printf("***[input] : %s\n", input);
// 		tet = transform_character(input);
// 		while (ft_strlen(tet) < 16)
// 			ft_strcat(tet, ".");
// 		two_dprint(tet);
// 		// printf("tet :%s\n", tet);
		
// 		ft_memset(input, '\0', 17);
// 		// printf("after memset input : %s\n", input);

// 	}
// 	return (0);
// }