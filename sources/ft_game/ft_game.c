/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/26 15:14:13by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"


void	ft_delet_images(t_data *data)
{
	if (data->img.map)
		mlx_delete_image(data->mlx, data->img.map);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.player);
}

int	ft_load_image(t_data *data)
{
	int	status;

	status = SUCCESS;
	data->img.map = mlx_new_image(data->mlx, WINDOW_HIGHT * 4,
		WINDOW_WIDTH * 4);
	data->img.player = mlx_new_image(data->mlx, MAP_SIZE_OBJECT,
		MAP_SIZE_OBJECT);
	if (data->img.player)
		ft_put_block(data->img.player, (t_vec){0, 0, 0}, (t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, BLACK);
	if (data->img.player == NULL || data->img.map == NULL)
	{
		status = FAIL;
		ft_delet_images(data);
	}
	return (status);
}

int ft_put_img(t_data *data)
{
	int	status;

	status = SUCCESS;
	if (mlx_image_to_window(data->mlx, data->img.map, 0, 0) == -1)
		status = FAIL;
	if (mlx_image_to_window(data->mlx, data->img.player, data->player.x * MAP_SIZE_OBJECT,
		data->player.y * MAP_SIZE_OBJECT) == -1)
		status = FAIL;
	if (status == FAIL)
		ft_delet_images(data);
	return (status);
}

static float	ft_get_frame(int fps)
{
	return (1.0f / (float)fps);
}

void	ft_key_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->img.player->instances[0].y -= PLAYER_SPEED;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->img.player->instances[0].y += PLAYER_SPEED;
	
}

int	ft_game_start(t_data *data)
{
	int		status;
	int32_t	width;
	int32_t	height;

	status = FAIL;
	data->time.framerate = ft_get_frame(10);
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HIGHT, "cub3D", true);
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_limit(data->mlx, 480, 270, width, height);
	if (data->mlx)
	{
		status = SUCCESS;
		if (ft_load_image(data) == SUCCESS && ft_put_img(data) == SUCCESS)
		{
			mlx_loop_hook(data->mlx, &ft_print_map_hook, data);
			mlx_loop_hook(data->mlx, &ft_key_hook, data);
			mlx_loop(data->mlx);
		}
		mlx_terminate(data->mlx);
	}
	return (status);
}
