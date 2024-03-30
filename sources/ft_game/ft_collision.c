/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:31:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/30 23:24:08 by tlassere         ###   ########.fr       */
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

int	ft_collision_hitbox(size_t valx1, size_t valx2, size_t valy1, size_t valy2)
{
	return ((ft_collision(valx1, valx2)
			|| ft_collision(valx1 + SCALE - 1, valx2))
		&& (ft_collision(valy1, valy2)
			|| ft_collision(valy1 + SCALE - 1, valy2)));
}

bool	ft_is_hitbox(t_data *data, t_vec pos)
{
	bool	status;

	status = false;
	if ((data->map[pos.y / SCALE][pos.x / SCALE] == WALL
		&& ft_collision_hitbox(pos.x, pos.x / SCALE, pos.y, pos.y / SCALE))
		|| (data->map[pos.y / SCALE + 1][pos.x / SCALE] == WALL
		&& ft_collision_hitbox(pos.x, pos.x / SCALE, pos.y, pos.y / SCALE + 1))
		|| (data->map[pos.y / SCALE][pos.x / SCALE + 1] == WALL
		&& ft_collision_hitbox(pos.x, pos.x / SCALE + 1, pos.y, pos.y / SCALE))
		|| (data->map[pos.y / SCALE + 1][pos.x / SCALE + 1] == WALL
		&& ft_collision_hitbox(pos.x, pos.x / SCALE + 1, pos.y,
			pos.y / SCALE + 1)))
	{
		status = true;
	}
	return (status);
}
