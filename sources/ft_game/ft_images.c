/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:59:49 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 20:04:05 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_delet_images(t_data *data)
{
	if (data->img.map)
		mlx_delete_image(data->mlx, data->img.map);
	if (data->img.player)
		mlx_delete_image(data->mlx, data->img.player);
	if (data->img.game)
		mlx_delete_image(data->mlx, data->img.game);
	data->img.map = NULL;
	data->img.player = NULL;
	data->img.game = NULL;
}

int	ft_load_image(t_data *data)
{
	int	status;

	status = FAIL;
	data->img.map = mlx_new_image(data->mlx, WINDOW_WIDTH_MAX,
			WINDOW_HEIGHT_MAX);
	data->img.player = mlx_new_image(data->mlx, WINDOW_WIDTH_MAX,
			WINDOW_HEIGHT_MAX);
	data->img.game = mlx_new_image(data->mlx, WINDOW_WIDTH_MAX,
			WINDOW_HEIGHT_MAX);
	if (data->img.player)
		ft_put_block(data->img.player, (t_vec){0, 0, 0},
			(t_vec){PLAYER_SIZE * MAP_SIZE_OBJECT / SCALE, PLAYER_SIZE
			*MAP_SIZE_OBJECT / SCALE, 0}, RED | ALPHA_64);
	if (data->img.player && data->img.map && data->img.game)
		status = SUCCESS;
	return (status);
}

int	ft_put_img(t_data *data)
{
	int	status;

	status = SUCCESS;
	if (mlx_image_to_window(data->mlx, data->img.game, 0, 0) == -1)
		status = FAIL;
	if (mlx_image_to_window(data->mlx, data->img.map, 0, 0) == -1)
		status = FAIL;
	if (mlx_image_to_window(data->mlx, data->img.player, 0, 0) == -1)
		status = FAIL;
	return (status);
}
