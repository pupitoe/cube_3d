/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 22:34:20 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_move(t_data *data, int val, float rotat)
{
	int		x;
	int		y;
	float	rotat_pi;

	rotat += data->player.rotat;
	rotat_pi = rotat * PI180;
	x = (int)lround(val * -cos(rotat_pi));
	y = (int)lround(val * sin(rotat_pi));
	data->player.x += x;
	data->player.y += y;
	data->img.player->instances[0].x += x;
	data->img.player->instances[0].y += y;
}

void	ft_key_hook_y(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_S) == 0)
			ft_move(data, PLAYER_SPEED, 180);
		printf("w\n");
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_W) == 0)
			ft_move(data, PLAYER_SPEED, 0);
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
			ft_move(data, PLAYER_SPEED, 270.0f);
		printf("A\n");
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_A) == 0)
			ft_move(data, PLAYER_SPEED, 90.0f);
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
	printf("player rotation: %f\n", data->player.rotat);
	ft_put_block(data->img.ray, (t_vec){0, 0, 0},
		(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, 0);
	ft_put_ray(data->img.ray, data->player.rotat,
		(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0});
}
