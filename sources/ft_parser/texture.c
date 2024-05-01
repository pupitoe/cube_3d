/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:37 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/12 20:40:43 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_texture(char *line, t_map *map)
{
	if (ft_strlen(line) < 4)
		return (0);
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) != '\0')
		return (!map->north_texture);
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) != '\0')
		return (!map->south_texture);
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) != '\0')
		return (!map->west_texture);
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) != '\0')
		return (!map->east_texture);
	return (0);
}

char	*skip_space(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

void	trim_space(char *line)
{
	while (*line)
		line++;
	line--;
	line--;
	while (*line == ' ')
		line--;
	line++;
	*line = '\0';
}

void	set_texture(char *line, t_map *map)
{
	trim_space(line);
	if (*(line + 0) == 'N' && *(line + 1) == 'O')
	{
		map->north_texture = ft_strdup_parser(skip_space(line + 2));
		if (map->north_texture > (char *) 1)
			map->north_texture[ft_strlen(map->north_texture)] = 0;
	}
	if (*(line + 0) == 'S' && *(line + 1) == 'O')
	{
		map->south_texture = ft_strdup_parser(skip_space(line + 2));
		if (map->south_texture > (char *) 1)
			map->south_texture[ft_strlen(map->south_texture)] = 0;
	}
	if (*(line + 0) == 'W' && *(line + 1) == 'E')
	{
		map->west_texture = ft_strdup_parser(skip_space(line + 2));
		if (map->west_texture > (char *) 1)
			map->west_texture[ft_strlen(map->west_texture)] = 0;
	}
	if (*(line + 0) == 'E' && *(line + 1) == 'A')
	{
		map->east_texture = ft_strdup_parser(skip_space(line + 2));
		if (map->east_texture > (char *) 1)
			map->east_texture[ft_strlen(map->east_texture)] = 0;
	}
}
