/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:54:58 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 22:41:05 by tlassere         ###   ########.fr       */
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
	unsigned int	j;
	unsigned int	size_y;
	unsigned int	size_x;

	i = 0;
	size_x = MAP_SIZE_OBJECT;
	size_y = MAP_SIZE_OBJECT;
	while (i < data->map_size.y)
	{
		j = 0;
		while (j < data->map_size.x)
		{
			if (data->map[i][j] == 1)
				ft_put_block(data->img.map, (t_vec){j * size_x, i * size_y, 0},
					(t_vec){size_x, size_y, 0}, RED);
			else
				ft_put_block(data->img.map, (t_vec){j * size_x, i * size_y, 0},
					(t_vec){size_x, size_y, 0}, WHITE);
			j++;
		}
		i++;
	}
}

void	ft_print_map_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	data->time.time_passed += data->mlx->delta_time;
	if (data->time.time_passed >= data->time.framerate)
	{
		ft_print_map(data);
		data->time.time_passed -= data->time.framerate;
	}
}
