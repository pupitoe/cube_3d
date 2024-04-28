/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:37 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 14:36:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	find_width(char *map)
{
	int	width_max;
	int	width;

	width_max = 0;
	width = 0;
	while (*map)
	{
		if (*map == '\n' && width > width_max)
			width_max = width;
		if (*map == '\n')
			width = 0;
		else
			width++;
		map++;
	}
	if (width > width_max)
		width_max = width;
	return (width_max);
}

int	find_height(char *map)
{
	int	height;

	height = 0;
	while (*map)
	{
		if (*map == '\n')
			height++;
		map++;
	}
	if (*(map - 1) != '\n')
		height++;
	return (height);
}

int	clear_map(int **map, size_t line_to_clear)
{
	size_t	line_cleared;

	line_cleared = 0;
	while (line_cleared < line_to_clear)
	{
		free(map[line_cleared]);
		line_cleared++;
	}
	free(map);
	return (MALLOC_FAIL);
}

void	copy_line(t_data *data, int **map, size_t line)
{
	char	*src;
	size_t	cursor;
	size_t	line_src;

	src = data->map_parser->map;
	cursor = 0;
	line_src = 0;
	while (*src && line_src < line)
	{
		if (*src == '\n')
			line_src++;
		src++;
	}
	while (cursor < data->map_size.x && src[cursor] != '\n')
	{
		if (src[cursor] == ' ')
			map[line][cursor] = 0;
		else if (src[cursor] == 'D')
			map[line][cursor] = 2;
		else
			map[line][cursor] = (int) src[cursor] - '0';
		cursor++;
	}
	while (cursor < data->map_size.x)
		map[line][cursor++] = 0;
}

int	convert(t_data *data)
{
	size_t	line;
	int		**map;

	data->map_size.y = find_height(data->map_parser->map);
	data->map_size.x = find_width(data->map_parser->map);
	map = malloc(data->map_size.y * sizeof(int *));
	if (!map)
		return (MALLOC_FAIL);
	line = 0;
	while (line < data->map_size.y)
	{
		map[line] = malloc(data->map_size.x * sizeof(int));
		if (!map[line])
			return (clear_map(map, line));
		copy_line(data, map, line);
		line++;
	}
	data->map = map;
	return (SUCCESS);
}
