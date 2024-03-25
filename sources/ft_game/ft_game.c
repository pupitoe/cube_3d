/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/25 23:18:29 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	test(void *vdata)
{
	t_data	*data;
	
	data = vdata;	
	data->time.time_passed += data->mlx->delta_time;
	if (data->time.time_passed >= data->time.framerate)
	{
	
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
		mlx_loop_hook(data->mlx, &test, data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
	}
	return (status);
}
