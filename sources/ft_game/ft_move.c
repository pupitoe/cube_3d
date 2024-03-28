/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 16:46:55 by tlassere         ###   ########.fr       */
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
			data->img.player->instances[0].y -= PLAYER_SPEED;
		printf("w\n");
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_W) == 0)
			data->img.player->instances[0].y += PLAYER_SPEED;
		printf("s\n");
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
			data->img.player->instances[0].x -= PLAYER_SPEED;
		printf("A\n");
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_A) == 0)
			data->img.player->instances[0].x += PLAYER_SPEED;
		printf("D\n");
	}
	data->img.ray->instances[0].x = data->img.player->instances[0].x;
}

void	ft_key_hook_arrow(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == 0)
			data->player.rotat -= 10;
		printf("<-\n");
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == 0)
			data->player.rotat += 10;
		printf("->\n");
	}
	ft_put_block(data->img.ray, (t_vec){0, 0, 0}, (t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, 0);
	ft_put_ray(data->img.ray, data->player.rotat, (t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0});
}
