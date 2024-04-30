/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:42:37 by abareux           #+#    #+#             */
/*   Updated: 2024/04/15 17:27:27 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	validate_map(t_map *map)
{
	char	*buffer;

	buffer = ft_strdup(map->map);
	if (!buffer)
		return (MALLOC_FAIL);
	if (flood(buffer))
		return (FAIL);
	return (SUCCESS);
}

int	validate_data(t_map *map)
{
	if (map->celling->blue > 255)
		return (map_error(map, "Blue celling color invalid\n"));
	if (map->celling->red > 255)
		return (map_error(map, "Red celling color invalid\n"));
	if (map->celling->green > 255)
		return (map_error(map, "Green celling color invalid\n"));
	if (map->celling->blue < 0)
		return (map_error(map, "Blue celling color invalid\n"));
	if (map->celling->red < 0)
		return (map_error(map, "Red celling color invalid\n"));
	if (map->celling->green < 0)
		return (map_error(map, "Green celling color invalid\n"));
	if (map->floor->blue > 255)
		return (map_error(map, "Blue floor color invalid\n"));
	if (map->floor->red > 255)
		return (map_error(map, "Red floor color invalid\n"));
	if (map->floor->green > 255)
		return (map_error(map, "Green floor color invalid\n"));
	if (map->floor->blue < 0)
		return (map_error(map, "Blue floor color invalid\n"));
	if (map->floor->red < 0)
		return (map_error(map, "Red floor color invalid\n"));
	if (map->floor->green < 0)
		return (map_error(map, "Green floor color invalid\n"));
	return (SUCCESS);
}

int	validate_line(char *line)
{
	int	cursor;

	cursor = 2;
	while (line[cursor] && line[cursor] == ' ')
		cursor++;
	if (intlen(line + cursor) > 3)
		return (0);
	while (line[cursor] && line[cursor] != ',')
		cursor++;
	if (intlen(++line + cursor) > 3)
		return (0);
	while (line[cursor] && line[cursor] != ',')
		cursor++;
	if (intlen(++line + cursor) > 3)
		return (0);
	line += 2;
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != ',' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}
