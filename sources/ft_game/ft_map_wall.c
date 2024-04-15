/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 16:42:53 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_print_line_screen(t_data *data, t_data_wall wall)
{
	int	color;

	color = GREEN;
	if (wall.collide.wall_dir == W_NORTH)
		color = BLACK;
	else if (wall.collide.wall_dir == W_SOUTH)
		color = RED;
	else if (wall.collide.wall_dir == W_EAST)
		color = PINK;
	else if (wall.collide.wall_dir == W_WEST)
		color = WHITE;
	if (wall.height < 0 || wall.height > data->mlx->height)
		wall.height = data->mlx->height;
	ft_put_block(data->img.game, (t_vec){wall.start,
		data->middle.screen.y - wall.height / 2, 0},
		(t_vec){wall.width, wall.height, 0}, color);
}

static void	ft_use_dda(t_data *data, float rotat, int size, int ray_start)
{
	t_data_wall		wall;
	int				height_dist;

	wall.collide = ft_dda(data, (t_fvec){(float)(data->player.x
				+ data->middle.player_size) / SCALE, (float)(data->player.y
				+ data->middle.player_size) / SCALE},
			data->player.rotat + rotat);
	height_dist = 0;
	if (wall.collide.checker)
	{
		height_dist = (float)(data->mlx->height)
			/ ((wall.collide.dist) * cos(rotat * PI180));
		wall.height = height_dist;
		wall.start = ray_start;
		wall.width = size;
		ft_print_line_screen(data, wall);
		mlx_put_pixel(data->img.map, (wall.collide.len.x * SCALE)
			*MAP_SIZE_OBJECT / SCALE, (wall.collide.len.y * SCALE)
			*MAP_SIZE_OBJECT / SCALE, PINK);
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
