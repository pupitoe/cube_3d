/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:18:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 22:18:48 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_clear_map(t_data *data)
{
	int		pos_y;
	int		pos_x;
	t_vec	block_position;

	data->img.player->instances[0].enabled = false;
	pos_y = -4;
	while (pos_y < 5)
	{
		pos_x = -4;
		while (pos_x < 5)
		{
			block_position.y = data->middle.screen.y + pos_y * MAP_SIZE_OBJECT;
			block_position.x = data->middle.screen.x + pos_x * MAP_SIZE_OBJECT;
			block_position.rotat = 0;
			ft_put_block(data->img.map, block_position,
				(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, 0);
			pos_x++;
		}
		pos_y++;
	}
}

void	ft_print_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	ft_print_game(data);
	data->time.time_passed += data->mlx->delta_time;
	if (data->time.time_passed >= data->time.framerate)
	{
		if (data->print_map)
			ft_print_map(data);
		else
			ft_clear_map(data);
		data->time.time_passed -= data->time.framerate;
	}
}
