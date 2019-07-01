#include "fillit.h"

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
