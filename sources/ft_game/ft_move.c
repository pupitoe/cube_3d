/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:12:53 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/29 15:41:40y tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

bool	ft_collision(size_t box, size_t box2)
{
	size_t	box_pos;

	box_pos = box2 * SCALE;
	return (box >= box_pos && box < box_pos + SCALE);
}

bool	ft_is_hit(t_data *data, t_vec pos)
{
	bool	status;
	size_t	y;
	size_t	x;

	y = 0;
	status = false;
	while (y < data->map_size.y && status == false)
	{
		x = 0;
		while (x < data->map_size.x && status == false)
		{
			if (data->map[y][x] == WALL)
			{
				if (ft_collision(pos.x, x) && ft_collision(pos.y, y))
					status = true;
			}
			x++;
		}
		y++;
	}
	return (status);
}

void	ft_move(t_data *data, int val, float rotat)
{
	int		x;
	int		y;
	float	rotat_pi;

	rotat += data->player.rotat;
	rotat_pi = rotat * PI180;
	x = (int)lround(val * -cos(rotat_pi));
	y = (int)lround(val * sin(rotat_pi));
	if (ft_is_hit(data, (t_vec){data->player.x + x, data->player.y + y, 0}))
	{
		y = 0;
		x = 0;
	}
	data->player.x += x;
	data->player.y += y;
}
