/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:54:58 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/03 00:34:54 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_put_block(mlx_image_t *img, t_vec pos, t_vec size, int color)
{
	int	x;

	while (size.y)
	{
		x = size.x;
		size.y--;
		while (x)
		{
			x--;
			mlx_put_pixel(img, x + pos.x, pos.y + size.y, color);
		}
	}
}

// TODO check if devisor is 0 (segfault belike)
static void	ft_print_map(t_data *data)
{
	unsigned int	i;
	unsigned int	size_y;
	unsigned int	size_x;

	i = 0;
	size_x = MAP_SIZE_OBJECT;
	size_y = MAP_SIZE_OBJECT;
	while (i / data->map_size.x < data->map_size.y)
	{
		if (data->map[i / data->map_size.x][i % data->map_size.x] == 1)
			ft_put_block(data->img.map, (t_vec){(i % data->map_size.x) * size_x,
				(i / data->map_size.x) * size_y, 0},
				(t_vec){size_x, size_y, 0}, RED);
		else
			ft_put_block(data->img.map, (t_vec){(i % data->map_size.x) * size_x,
				(i / data->map_size.x) * size_y, 0},
				(t_vec){size_x, size_y, 0}, WHITE);
		i++;
	}
	data->img.player->instances[0].x = data->player.x * MAP_SIZE_OBJECT / SCALE;
	data->img.player->instances[0].y = data->player.y * MAP_SIZE_OBJECT / SCALE;
}

void	ft_print_ray(t_data *data)
{
	int		pos;
	double	retc;
	double	rets;
	t_ivec	c_player;
	t_ivec	pos_pixel;

	retc = cos(data->player.rotat * PI180);
	rets = sin(data->player.rotat * PI180);
	c_player.x = data->player.x * MAP_SIZE_OBJECT / SCALE + MAP_SIZE_OBJECT / 2;
	c_player.y = data->player.y * MAP_SIZE_OBJECT / SCALE + MAP_SIZE_OBJECT / 2;
	pos = 0;
	while (pos < 100)
	{
		pos_pixel.x = (int)lround(pos * retc) + c_player.x;
		pos_pixel.y = -(int)lround(pos * rets) + c_player.y;
		if (pos_pixel.x >= 0 && pos_pixel.y >= 0
			&& (size_t)pos_pixel.x < data->map_size.x * MAP_SIZE_OBJECT
			&& (size_t)pos_pixel.y < data->map_size.y * MAP_SIZE_OBJECT)
			mlx_put_pixel(data->img.map, pos_pixel.x, pos_pixel.y, PINK);
		pos++;
	}
	ft_dda(data);
}

void	ft_print_map_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	data->time.time_passed += data->mlx->delta_time;
	if (data->time.time_passed >= data->time.framerate)
	{
		ft_print_map(data);
		ft_print_ray(data);
		data->time.time_passed -= data->time.framerate;
	}
}
