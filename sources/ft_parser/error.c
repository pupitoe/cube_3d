/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:10 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:11:12 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	map_error(t_map *map, char *reason)
{
	if (map->north_texture > (char *) 1)
		free(map->north_texture);
	if (map->south_texture > (char *) 1)
		free(map->south_texture);
	if (map->west_texture > (char *) 1)
		free(map->west_texture);
	if (map->east_texture > (char *) 1)
		free(map->east_texture);
	if (map->floor > (t_rgb *) 1)
		free(map->floor);
	if (map->celling > (t_rgb *) 1)
		free(map->celling);
	if (map->map > (char *) 1)
		free(map->map);
	free(map);
	write(1, "Error\n", 6);
	write(1, reason, ft_strlen(reason));
	return (FAIL);
}

int	malloc_error(t_map *map)
{
	purge_map(map);
	write(1, "Error\n", 6);
	write(1, "a malloc f*** up\n", 18);
	return (FAIL);
}
