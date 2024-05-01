/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:49 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_set_data(t_data *data)
{
	data->middle.player_size = PLAYER_SIZE / 2;
	data->print_map = false;
}

int	ft_game_start(t_data *data)
{
	int		status;

	status = FAIL;
	data->time.framerate = 1.0f / 4.0f;
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
	ft_set_data(data);
	if (data->mlx)
	{
		status = SUCCESS;
		mlx_set_window_limit(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_WIDTH_MAX, WINDOW_HEIGHT_MAX);
		ft_set_icon(data);
		if (ft_load_image(data) == SUCCESS
			&& ft_set_textures(data) == SUCCESS
			&& ft_put_img(data) == SUCCESS
			&& ft_set_hook(data) == SUCCESS)
			mlx_loop(data->mlx);
		ft_delet_images(data);
		ft_delet_textures(data);
		mlx_terminate(data->mlx);
	}
	return (status);
}
