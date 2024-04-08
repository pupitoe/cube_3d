/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by by UwU            #+#    #+#             */
/*   Updated: 2024/04/08 17:18:34 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_celling(char *line, t_map *map)
{
	if (*(line + 0) == 'C' && *(line + 1) == ' ' && *(line + 2) != '\0')
		return (!map->celling);
	return (0);
}

void	set_celling(char *line, t_map *map)
{
	t_rgb	*result;

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
	map->celling = result;
}
