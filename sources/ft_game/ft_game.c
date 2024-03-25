/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/26 00:03:11 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_put_block(t_data *data, t_vec pos, t_vec size, int color)
{
	int	x;

	while (size.y) 
	{
		x = size.x;
		size.y--;
		while (x)
		{
			x--;
			mlx_put_pixel(data->img, x + pos.x, pos.y + size.y, color);
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
	size_x = 0;
	size_y = 0;
	if (data->mlx->height != 0 && data->mlx->width != 0)
	{
		size_x = WINDOW_WIDTH / data->map_size.x;
		size_y = WINDOW_HIGHT / data->map_size.y;
	}
	while (i < data->map_size.y)
	{
		j = 0;
		while (j < data->map_size.x)
		{
			if (data->map[i][j] == 0)
				ft_put_block(data, (t_vec){j * size_x, i * size_y, 0}, (t_vec){size_x, size_y, 0}, 0xFF0000FF);
			else
				ft_put_block(data, (t_vec){j * size_x, i * size_y, 0}, (t_vec){size_x, size_y, 0}, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	test(void *vdata)
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

static float	ft_get_frame(int fps)
{
	return (1.0f / (float)fps);
}

int	ft_game_start(t_data *data)
{
	int	status;

	status = FAIL;
	data->time.framerate = ft_get_frame(30);
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HIGHT, "cub3D", true);
	if (data->mlx)
	{
		status = SUCCESS;
		data->img = mlx_new_image(data->mlx, WINDOW_HIGHT, WINDOW_WIDTH);
		if (data->img && mlx_image_to_window(data->mlx, data->img, 0, 0) >= 0)
		{
			mlx_loop_hook(data->mlx, &test, data);
			mlx_loop(data->mlx);
		}
		mlx_terminate(data->mlx);
	}
	return (status);
}
