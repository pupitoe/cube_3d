/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:01:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/12 19:23:55 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

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
