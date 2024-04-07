/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 14:25:36 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_use_dda(t_data *data, float rotat, int size, int ray_start)
{
	t_collide_data	collide;
	int				height_dist;

	collide = ft_dda(data, (t_fvec){(float)(data->player.x + SCALE / 2) / SCALE,
			(float)(data->player.y + SCALE / 2) / SCALE},
			data->player.rotat + rotat);
	height_dist = (float)(data->mlx->height) / (collide.dist + 0.5f);
	if (collide.checker)
	{
		ft_put_block(data->img.game, (t_vec){ray_start, data->mlx->height
			/ 2 - height_dist / 2, 0}, (t_vec){size, height_dist, 0}, RED);
	}
}

void	ft_print_wall(t_data *data)
{
	int		ray_number;
	float	rad;
	int		size_ray;
	int		i;

	i = 0;
	//ray_number = COUNT_RAY;
	//rad = FOV / COUNT_RAY;
	ray_number = data->mlx->width;
	rad = FOV / ray_number;
	size_ray = data->mlx->width / ray_number;
	while (i < ray_number)
	{
		if (i != 0)
			ft_use_dda(data, (float)(i) *rad - FOV / 2.0f, size_ray,
				(ray_number - i) * size_ray);
		else
			ft_use_dda(data, (FOV / 2.0f), size_ray, 0);
		i++;
	}
}
