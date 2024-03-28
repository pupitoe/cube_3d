/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 23:23:34 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static float	ft_get_frame(int fps)
{
	return (1.0f / (float)fps);
}

void	ft_escape(mlx_key_data_t key, void *vdata)
{
	t_data	*data;

	data = vdata;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}

int	ft_game_start(t_data *data)
{
	int		status;
	int32_t	width;
	int32_t	height;

	status = FAIL;
	data->time.framerate = ft_get_frame(30);
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HIGHT, "cub3D", true);
	mlx_get_monitor_size(0, &width, &height);
	if (data->mlx)
	{
		status = SUCCESS;
		mlx_set_window_limit(data->mlx, 480, 270, width, height);
		if (ft_load_image(data) == SUCCESS && ft_put_img(data) == SUCCESS)
		{
			mlx_loop_hook(data->mlx, &ft_print_map_hook, data);
			mlx_loop_hook(data->mlx, &ft_key_hook_y, data);
			mlx_loop_hook(data->mlx, &ft_key_hook_x, data);
			mlx_loop_hook(data->mlx, &ft_key_hook_arrow, data);
			mlx_key_hook(data->mlx, &ft_escape, data);
			mlx_loop(data->mlx);
			ft_delet_images(data);
		}
		mlx_terminate(data->mlx);
	}
	return (status);
}
