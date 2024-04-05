/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/05 21:21:31 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_use_dda(t_data *data, float rotat)
{
	t_collide_data	dist;

	dist = ft_dda(data, (t_fvec){(float)(data->player.x + SCALE / 2) / SCALE,
			(float)(data->player.y + SCALE / 2) / SCALE},
			data->player.rotat + rotat);
	if (dist.checker)
	{
		printf("dist x: %f\n", dist.len.x);
		printf("dist y: %f\n", dist.len.y);
		mlx_put_pixel(data->img.map, (int)(dist.len.x * SCALE) *MAP_SIZE_OBJECT
			/ SCALE, (int)(dist.len.y * SCALE) *MAP_SIZE_OBJECT / SCALE, BLACK);
		mlx_put_pixel(data->img.map, 1 + (int)(dist.len.x * SCALE) *MAP_SIZE_OBJECT
			/ SCALE, (int)(dist.len.y * SCALE) *MAP_SIZE_OBJECT / SCALE, BLACK);
		mlx_put_pixel(data->img.map, 1 + (int)(dist.len.x * SCALE) *MAP_SIZE_OBJECT
			/ SCALE, 1 + (int)(dist.len.y * SCALE) *MAP_SIZE_OBJECT / SCALE, BLACK);
		mlx_put_pixel(data->img.map, 0 + (int)(dist.len.x * SCALE) *MAP_SIZE_OBJECT
			/ SCALE, 1 + (int)(dist.len.y * SCALE) *MAP_SIZE_OBJECT / SCALE, BLACK);
	}
}

void	ft_print_wall(t_data *data)
{
	int		ray_number;
	float	rad;

	ray_number = COUNT_RAY;
	rad = FOV / COUNT_RAY;
	while (ray_number)
	{
		ft_use_dda(data, (float)ray_number * rad);
		ft_use_dda(data, -((float)ray_number * rad));
		ray_number--;
	}
	ft_use_dda(data, 0);
}
