/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:31:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/30 17:32:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static bool	ft_collision(size_t box, size_t box2)
{
	size_t	box_pos;

	box_pos = box2 * SCALE;
	return (box >= box_pos && box < box_pos + SCALE);
}

bool	ft_is_hit(t_data *data, t_vec pos)
{
	bool	status;
	size_t	i;

	status = false;
	i = 0;
	while (i / data->map_size.x < data->map_size.y && status == false)
	{
		if (data->map[i / data->map_size.x][i % data->map_size.x] == WALL)
		{
			if (ft_collision(pos.x, i % data->map_size.x)
				&& ft_collision(pos.y, i / data->map_size.x))
				status = true;
		}
		i++;
	}
	return (status);
}

bool	ft_is_hitbox(t_data *data, t_vec pos)
{
	bool	status;
	size_t	i;

	status = false;
	i = 0;
	while (i / data->map_size.x < data->map_size.y && status == false)
	{
		if (data->map[i / data->map_size.x][i % data->map_size.x] == WALL)
		{
			if ((ft_collision(pos.x, i % data->map_size.x)
					|| ft_collision(pos.x + SCALE - 1, i % data->map_size.x))
				&& (ft_collision(pos.y, i / data->map_size.x)
					|| ft_collision(pos.y + SCALE - 1, i / data->map_size.x)))
				status = true;
		}
		i++;
	}
	return (status);
}
