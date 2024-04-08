/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 12:14:13 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

static
int	is_player(char map)
{
	if (map == 'N' || map == 'S' || map == 'E' || map == 'O')
		return (1);
	return (0);
}

static
void	set_around(char *map, int x, int y)
{
	int	pos_x;
	int	pos_y;
	int	i;

	pos_x = 0;
	pos_y = 0;
	i = 0;
	while (map[i])
	{
		if (pos_x == x - 1 && pos_y == y && empty(map[i]))
			map[i] = '2';
		if (pos_x == x + 1 && pos_y == y && empty(map[i]))
			map[i] = '2';
		if (pos_y == y - 1 && pos_x == x && empty(map[i]))
			map[i] = '2';
		if (pos_y == y + 1 && pos_x == x && empty(map[i]))
			map[i] = '2';
		pos_x++;
		if (map[i++] == '\n')
		{
			pos_x = 0;
			pos_y++;
		}
	}
}

static
void	flood_map(char *map, int *pos_x, int *pos_y)
{
	int	j;
	int	i;

	j = 0;
	while (map[j])
	{
		i = 0;
		*pos_y = 0;
		while (map[i])
		{
			if (map[i] == '2')
				set_around(map, *pos_x, *pos_y);
			(*pos_x)++;
			if (map[i++] == '\n')
			{
				*pos_x = 0;
				(*pos_y)++;
			}
		}
		j++;
	}
}

static
int	check_map(char *map)
{
	int	i;
	int	pos_x;
	int	pos_y;
	int	buffer;

	pos_x = 0;
	pos_y = 0;
	buffer = 0;
	flood_map(map, &pos_x, &pos_y);
	i = 1;
	pos_x = 0;
	while (map[i])
	{
		if (map[i] == '2' && is_leak(map, (t_point){pos_x, pos_y}, buffer, i))
			return (free(map), 1);
		buffer++;
		if (map[i++] == '\n')
		{
			buffer = 0;
			pos_x++;
		}
	}
	return (free(map), 0);
}

int	flood(char *map)
{
	int	iteration;
	int	pos_x;
	int	pos_y;

	iteration = 0;
	pos_x = 0;
	pos_y = 0;
	while (map[iteration] && !is_player(map[iteration]))
	{
		pos_x++;
		if (map[iteration++] == '\n')
		{
			pos_x = 0;
			pos_y++;
		}
	}
	if (is_player(map[iteration]))
		set_around(map, pos_x, pos_y);
	else
		return (free(map), 1);
	return (check_map(map));
}
