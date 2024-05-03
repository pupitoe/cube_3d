/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/16 20:30:29 by tlassere         ###   ########.fr       */
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
}

void	ft_key_hook_arrow(void *vdata)
{
	t_data	*data;

	data = vdata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT) == 0)
			data->player.rotat -= ROT_SPEED;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT) == 0)
			data->player.rotat += ROT_SPEED;
	}
}

void	ft_key_hook_tab(mlx_key_data_t key, void *vdata)
{
	t_data	*data;

	data = vdata;
	if (key.key == MLX_KEY_TAB && key.action == MLX_PRESS)
		data->print_map = !data->print_map;
}
