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

bool	ft_is_hit(t_data *data, t_vec pos)
{
	bool	status;
	size_t	i;

	i = 0;
	status = false;
	while (i / data->map_size.x < data->map_size.y)
	{
		if (data->map[i  / data->map_size.x][i % data->map_size.x] == WALL)
		{
			if (i % data->map_size.x * SCALE >= pos.x && i % data->map_size.x * SCALE + SCALE < pos.x
				&& i / data->map_size.x * SCALE >= pos.y && i / data->map_size.x * SCALE + SCALE < pos.y)
				status = true;
		}
		i++;
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
