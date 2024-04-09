/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:37 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:12:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_texture(char *line, t_map *map)
{
	if (ft_strlen(line) < 4)
		return (0);
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (!map->north_texture);
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (!map->south_texture);
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		return (!map->west_texture);
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		return (!map->east_texture);
	return (0);
}

void	set_texture(char *line, t_map *map)
{
	if (*(line + 0) == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
	{
		map->north_texture = ft_strdup(line + 3);
		if (map->north_texture != (char *) 1)
			map->north_texture[ft_strlen(map->north_texture) - 1] = 0;
	}
	if (*(line + 0) == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
	{
		map->south_texture = ft_strdup(line + 3);
		if (map->south_texture != (char *) 1)
			map->south_texture[ft_strlen(map->south_texture) - 1] = 0;
	}
	if (*(line + 0) == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
	{
		map->west_texture = ft_strdup(line + 3);
		if (map->west_texture != (char *) 1)
			map->west_texture[ft_strlen(map->west_texture) - 1] = 0;
	}
	if (*(line + 0) == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
	{
		map->east_texture = ft_strdup(line + 3);
		if (map->east_texture != (char *) 1)
			map->east_texture[ft_strlen(map->east_texture) - 1] = 0;
	}
}
