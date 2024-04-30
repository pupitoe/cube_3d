/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:18:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/30 19:36:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_clear_map(t_data *data)
{
	t_vec	img_size;

	img_size.y = data->img.map->height;
	img_size.x = data->img.map->width;
	img_size.rotat = 0;
	ft_put_block(data->img.map, (t_vec){0, 0, 0}, img_size, 0);
	data->img.player->instances[0].enabled = false;
}

void	ft_print_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	ft_print_game(data);
	data->time.time_passed += data->mlx->delta_time;
	data->time.all_time += data->mlx->delta_time * 15;
	if (data->time.time_passed >= data->time.framerate)
	{
		ft_clear_map(data);
		if (data->print_map)
			ft_print_map(data);
		data->time.time_passed = 0;
	}
}
