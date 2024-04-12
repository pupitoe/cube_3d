/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/11 14:34:20by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_print_line_screen(t_data *data, int height, int start, int size, t_collide_data collide)
{
	//height = data->mlx->height;
	if (height < data->mlx->height)
	{
		if ((int)(collide.len.x * SCALE) % SCALE == 0)
		{
			ft_put_block(data->img.game, (t_vec){start, data->middle.screen.y
				- height / 2, 0}, (t_vec){size, height, 0}, BLACK);
		}
		else 
		{
			ft_put_block(data->img.game, (t_vec){start, data->middle.screen.y
				- height / 2, 0}, (t_vec){size, height, 0}, RED);
		}
	}
}

static void	ft_use_dda(t_data *data, float rotat, int size, int ray_start)
{
	t_collide_data	collide;
	int				height_dist;

	collide = ft_dda(data, (t_fvec){(float)(data->player.x
				+ data->middle.player_size) / SCALE, (float)(data->player.y
				+ data->middle.player_size) / SCALE},
			data->player.rotat + rotat);
	height_dist = 0;
	if (collide.checker)
	{
		height_dist = (float)(data->mlx->height) / ((collide.dist) * cos(rotat * PI180));
		printf("toma: %d\n", height_dist);
		printf("collide: %f\n", collide.dist);
		ft_print_line_screen(data, height_dist, ray_start, size, collide);
		mlx_put_pixel(data->img.map, (collide.len.x * SCALE) * MAP_SIZE_OBJECT / SCALE, (collide.len.y * SCALE) * MAP_SIZE_OBJECT / SCALE, PINK);
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
