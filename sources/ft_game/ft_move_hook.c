/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/29 15:56:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_key_hook_y(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_S) == 0)
			ft_move(data, PLAYER_SPEED, 180);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_W) == 0)
			ft_move(data, PLAYER_SPEED, 0);
	}
	data->img.ray->instances[0].y = data->img.player->instances[0].y;
}

void	ft_key_hook_x(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_D) == 0)
			ft_move(data, PLAYER_SPEED, 270.0f);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_A) == 0)
			ft_move(data, PLAYER_SPEED, 90.0f);
	}
	data->img.ray->instances[0].x = data->img.player->instances[0].x;
}
// TODO uncatch KEY_Q is for test
void	ft_key_hook_arrow(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == 0)
			data->player.rotat -= 10;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == 0)
			data->player.rotat += 10;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
	{
		data->player.x = 1 * SCALE;
		data->player.y = 1 * SCALE;
		data->player.rotat = 0.0f;
	}
	ft_put_block(data->img.ray, (t_vec){0, 0, 0},
		(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, 0);
	ft_put_ray(data->img.ray, data->player.rotat,
		(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0});
}
