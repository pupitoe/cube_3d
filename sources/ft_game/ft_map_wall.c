/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 22:20:40 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_use_dda(t_data *data, float rotat, int size, int ray_start)
{
	t_collide_data	collide;
	int				height_dist;

	collide = ft_dda(data, (t_fvec){(float)(data->player.x
				+ data->middle.player_size) / SCALE, (float)(data->player.y
				+ data->middle.player_size) / SCALE},
			data->player.rotat + rotat);
	height_dist = (float)(data->mlx->height) / (collide.dist + 0.5f);
	if (collide.checker)
	{
		ft_put_block(data->img.game, (t_vec){ray_start, data->middle.screen.y
			- height_dist / 2, 0}, (t_vec){size, height_dist, 0}, RED);
	}
}

void	ft_print_wall(t_data *data)
{
	int		ray_number;
	float	rad;
	int		size_ray;
	int		i;
	float	fov_2;

	i = 0;
	fov_2 = FOV / 2.0f;
	ray_number = data->mlx->width;
	rad = FOV / ray_number;
	size_ray = data->mlx->width / ray_number;
	while (i < ray_number)
	{
		if (i != 0)
			ft_use_dda(data, (float)(i) *rad - fov_2, size_ray,
				(ray_number - i) * size_ray);
		else
			ft_use_dda(data, fov_2, size_ray, 0);
		i++;
	}
}
