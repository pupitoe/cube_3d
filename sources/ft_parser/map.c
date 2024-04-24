/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:02 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/12 20:32:21 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_map(t_map *map)
{
	if (map->north_texture < (char *) 2)
		return (0);
	if (map->south_texture < (char *) 2)
		return (0);
	if (map->west_texture < (char *) 2)
		return (0);
	if (map->east_texture < (char *) 2)
		return (0);
	if (map->floor < (t_rgb *) 2)
		return (0);
	if (map->celling < (t_rgb *) 2)
		return (0);
	return (1);
}

static
int	is_valid(char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '0' && *line != ' ' && *line != '\n' && \
			*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W' && \
			*line != 'D')
			return (0);
		line++;
	}
	return (1);
}

int	add_line_map(char *line, t_map *map)
{
	if (!is_valid(line))
		return (FAIL);
	if (!map->map)
		map->map = ft_strdup_parser(line);
	else
		map->map = ft_strjoin_parser(map->map, line, LEFT);
	if (!map->map)
		return (FAIL);
	return (SUCCESS);
}

char	get_cell(char *map, int x, int y)
{
	int	iteration;
	int	pos_x;
	int	pos_y;

	iteration = 0;
	pos_x = 0;
	pos_y = 0;
	while (map[iteration])
	{
		if (pos_x == x && pos_y == y)
			return (map[iteration]);
		pos_x++;
		if (map[iteration++] == '\n')
		{
			pos_x = 0;
			pos_y++;
		}
	}
	return ((char) 0);
}

int	is_leak(char *map, t_point pos, int buffer, int i)
{
	if (map[i - 1] == '\n' || map[i + 1] == '\n')
		return (1);
	if (pos.x == 0 || pos.x == pos.y)
		return (1);
	if (get_cell(map, buffer, pos.x - 1) == '\n')
		return (1);
	if (get_cell(map, buffer, pos.x - 1) == 0)
		return (1);
	if (get_cell(map, buffer, pos.x + 1) == '\n')
		return (1);
	if (get_cell(map, buffer, pos.x + 1) == 0)
		return (1);
	return (0);
}
