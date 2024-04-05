/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/04 22:05:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static float	ft_get_frame(int fps)
{
	return (1.0f / (float)fps);
}

static void	ft_escape(mlx_key_data_t key, void *vdata)
{
	t_data	*data;

	data = vdata;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
}

static int	ft_set_icon(t_data *data)
{
	int	status;

	status = FAIL;
	data->texture.icon = mlx_load_png("./asset/icon.png");
	if (data->texture.icon)
	{
		status = SUCCESS;
		mlx_set_icon(data->mlx, data->texture.icon);
	}
	return (status);
}

static int	ft_set_hook(t_data *data)
{
	if (!mlx_loop_hook(data->mlx, &ft_print_map_hook, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_y, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_x, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_arrow, data))
		return (FAIL);
	mlx_key_hook(data->mlx, &ft_escape, data);
	return (SUCCESS);
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
		ft_set_icon(data);
		if (ft_load_image(data) == SUCCESS && ft_put_img(data) == SUCCESS
			&& ft_set_hook(data) == SUCCESS)
			mlx_loop(data->mlx);
		ft_delet_images(data);
		ft_delet_textures(data);
		mlx_terminate(data->mlx);
	}
	return (status);
}
