/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:26 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 18:22:42 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_floor(char *line, t_map *map)
{
	if (*(line + 0) == 'F' && *(line + 1) == ' ' && *(line + 2) != '\0')
		return (!map->floor);
	return (0);
}

void	set_floor(char *line, t_map *map)
{
	t_rgb	*result;

	result = (t_rgb *) 0;
	if (validate_line(line))
		result = malloc(sizeof(t_rgb));
	if (!result)
	{
		map->floor = (void *) 1;
		return ;
	}
	result->red = ft_atoi(line + 2);
	while (*line != ',' && *line)
		line++;
	result->green = ft_atoi(++line);
	while (*line != ',' && *line)
		line++;
	result->blue = ft_atoi(++line);
	map->floor = result;
}
