/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 16:01:08 by tlassere         ###   ########.fr       */
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
	int32_t	width;
	int32_t	height;

	status = FAIL;
	data->time.framerate = 1.0f / 30.0f;
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HIGHT, "cub3D", true);
	mlx_get_monitor_size(0, &width, &height);
	ft_set_data(data);
	if (data->mlx)
	{
		status = SUCCESS;
		mlx_set_window_limit(data->mlx, 960, 540, 1920, 1080);
		ft_set_icon(data);
		if (ft_load_image(data, width, height) == SUCCESS
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
