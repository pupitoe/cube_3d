/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:09:25 by abareux           #+#    #+#             */
/*   Updated: 2024/04/08 21:06:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	purge_map(t_map *map)
{
	if (map)
	{
		free(map->north_texture);
		free(map->south_texture);
		free(map->east_texture);
		free(map->west_texture);
		free(map->celling);
		free(map->floor);
		free(map->map);
		free(map);
	}
}
