/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:51 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:12:52 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	validate_map(t_map *map)
{
	char	*buffer;

	buffer = ft_strdup(map->map);
	if (!buffer)
		malloc_error(map);
	if (flood(buffer))
		map_error(map);
}

void	validate_data(t_map *map)
{
	if (map->celling->blue > 255)
		map_error(map);
	if (map->celling->red > 255)
		map_error(map);
	if (map->celling->green > 255)
		map_error(map);
	if (map->celling->blue < 0)
		map_error(map);
	if (map->celling->red < 0)
		map_error(map);
	if (map->celling->green < 0)
		map_error(map);
}
