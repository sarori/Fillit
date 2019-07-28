#include "fillit.h"

int		count_piece(t_tet **tetriminoes)
{
	t_tet	*curr;
	int		cnt;

	cnt = 0;
	curr = (*tetriminoes);
	while (curr)
	{
		curr = curr->next;
		cnt++;
	}
	return (cnt);
}

int     calculate_size(t_tet **tetriminoes)
{
    /* width와 height비교해서 큰 값이 n이 되게 한다.
    tetriminoes->width
    tetriminoes->height
    */
    t_tet   *tmp;
	int		cnt;
	int		wid_max;
	int		hei_max;

	tmp = (*tetriminoes);
	cnt = count_piece(tetriminoes);
	wid_max = tmp->width;
	hei_max = tmp->height;
	tmp = tmp->next;	/*2번째 값부터 비교해야하므로 tmp->next를 해야한다. */
    while (tmp)
    {
		if (wid_max < tmp->width)
			wid_max = tmp->width;
		if (hei_max < tmp->height)
			hei_max = tmp->height;
        tmp = tmp->next;
	}
    size = (hei_max >= wid_max ? hei_max : wid_max);
	return (hei_max >= wid_max ? hei_max : wid_max);
}

int     calculate_length(char *input)
{
    int len;

    len = ft_strlen(input);
    while (len > 0)
    {
        if (input[len - 1] == '#')
            break;
        len--;
    }
    return (len);
}

int     count_width(char *input, int size)
{
    int i;
    int j;
    int width;

    i = 0;
    j = 0;
    width = 0;
    while (j < size)
    {
        i = 0;
        while (i < size)
        {
            if (input[i * size + j] == '#')
            {
                width++;
                break;
            }
            i++;
        }
        j++;
    }
    return (width);
}

int     count_height(char *input, int size)
{
    int i;
    int j;
    int height;

    i = 0;
    height = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (input[i * size + j] == '#')
            {
                height++;
                break;
            }
            j++;
        }
        i++;
    }
    return (height);
}

int     calculate_width(char *input)
{
    int width;

    width = 0;
    while (input)
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
