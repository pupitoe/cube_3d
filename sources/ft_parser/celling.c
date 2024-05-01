/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:10:25 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:11:02 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_celling(char *line, t_map *map)
{
	if (*(line + 0) == 'C' && *(line + 1) != '\0')
		return (!map->celling);
	return (0);
}

void	set_celling(char *line, t_map *map)
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
	result->red = ft_atoi(line + 1);
	while (*line != ',' && *line)
		line++;
	result->green = ft_atoi(++line);
	while (*line != ',' && *line)
		line++;
	result->blue = ft_atoi(++line);
	map->celling = result;
}
