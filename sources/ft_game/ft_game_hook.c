/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:00:45 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/30 11:23:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_key_hook_other_key(mlx_key_data_t key, void *vdata)
{
	t_data	*data;

	data = vdata;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	else if (key.key == MLX_KEY_TAB)
		ft_key_hook_tab(key, vdata);
	else if (key.key == MLX_KEY_E && key.action == MLX_PRESS)
		ft_key_hook_interact(data);
	else if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
	{
		data->mouse_toggle = !(data->mouse_toggle);
		if (data->mouse_toggle)
			mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
		else
			mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	}
	else if (key.action == MLX_PRESS && (key.key == MLX_KEY_LEFT
			|| key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_DOWN
			|| key.key == MLX_KEY_UP || key.key == MLX_KEY_A
			|| key.key == MLX_KEY_B))
		ft_konami(key.key, data);
}

int	ft_set_hook(t_data *data)
{
	if (!mlx_loop_hook(data->mlx, &ft_print_hook, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_y, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_x, data))
		return (FAIL);
	if (!mlx_loop_hook(data->mlx, &ft_key_hook_arrow, data))
		return (FAIL);
	mlx_key_hook(data->mlx, &ft_key_hook_other_key, data);
	mlx_cursor_hook(data->mlx, &ft_cursor_func, data);
	return (SUCCESS);
}
