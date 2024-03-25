/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:01:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/25 21:56:48 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	*ft_dup_line(int *line, int with)
{
	int	*new_line;

	new_line = malloc(sizeof(int) * with);
	if (new_line)
		ft_memmove(new_line, line, sizeof(int) * (with));
	return (new_line);
}

void	ft_map_free(int ***map, int heigth)
{
	if (map && *map)
	{
		while (heigth)
		{
			heigth--;
			free((*map)[heigth]);
		}
		free(*map);
	}
	*map = NULL;
}

int	**ft_map_dup(int **map, t_vec size)
{
	int	**new_map;
	int	heigth;
	int	i;

	heigth = size.y;
	new_map = malloc(sizeof(int *) * (heigth));
	i = 0;
	if (new_map)
	{
		ft_bzero(new_map, sizeof(int *) * (heigth));
		while (i != -1 && i < heigth)
		{
			new_map[i] = ft_dup_line(map[i], size.x);
			if (new_map[i] == NULL)
			{
				ft_map_free(&new_map, i);
				i = -1;
			}
			else
				i++;
		}
	}
	return (new_map);
}
