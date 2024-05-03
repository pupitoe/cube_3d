/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/03 12:18:52 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static mlx_texture_t	*ft_get_texture_face(t_data *data, t_data_wall wall)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (wall.collide.block_touch == DOOR_OP)
		texture = data->texture.door;
	else if (wall.collide.wall_dir == W_NORTH)
		texture = data->texture.north;
	else if (wall.collide.wall_dir == W_SOUTH)
		texture = data->texture.south;
	else if (wall.collide.wall_dir == W_EAST)
		texture = data->texture.east;
	else if (wall.collide.wall_dir == W_WEST)
		texture = data->texture.west;
	return (texture);
}

static double	ft_get_pos_x(int wall_dir, t_dvec len, t_ivec block_checked)
{
	double	pos_x;
	t_dvec	pos_test;
	double buffer;

	pos_test.x = len.x - (long long)len.x;
	pos_test.y = len.y - (long long)len.y;
	if (wall_dir != W_NORTH)
	{
		if ((int)(len.x) - 1 == block_checked.x)
			pos_test.x = MAX_PRECISION;
		else if ((int)(len.y) + 1 == block_checked.y)
			pos_test.x = 0;
		if ((int)(len.y) - 1 == block_checked.y)
			pos_test.y = MAX_PRECISION;
		else if ((int)(len.y) + 1 == block_checked.y)
			pos_test.y = 0;
	}
	if (pos_test.x > MAX_PRECISION)
		pos_test.x = MAX_PRECISION;
	if (pos_test.y > MAX_PRECISION)
		pos_test.y = MAX_PRECISION;
	if (wall_dir == W_NORTH || wall_dir == W_SOUTH)
		pos_x = pos_test.x;
	else
		pos_x = pos_test.y;
	buffer = pos_x;
	if (wall_dir == W_NORTH || wall_dir == W_EAST)
		pos_x = MAX_PRECISION - pos_x;
	if (wall_dir == W_NORTH && ((int)len.x) != block_checked.x)
	{
		pos_x = MAX_PRECISION;
		if (pos_test.x != MAX_PRECISION)
			pos_x = 0;
	}
	return (pos_x);
}

/**
 * MAX_PRECISION is a limit for X position.
 * texture NORTH and EAST are reversed, so the pos_x is reverse
 * to get the right feel
*/
static void	ft_print_line_screen(t_data *data, t_data_wall wall)
{
	mlx_texture_t	*texture;
	double			pos_x;

	texture = ft_get_texture_face(data, wall);
	pos_x = 0;
	if (wall.height < 0)
		wall.height = data->height;
	pos_x = ft_get_pos_x(wall.collide.wall_dir, wall.collide.len, wall.collide.block_checked);
	if (wall.collide.block_touch == DOOR_OP)
		ft_print_line_animated(data, texture, wall, pos_x);
	else
		ft_print_line_texture(data, texture, wall, pos_x);
}

static void	ft_use_dda(t_data *data, double rotat, int size, int ray_start)
{
	t_data_wall		wall;
	int				height_dist;

	wall.collide = ft_dda(data, (t_dvec){(double)(data->player.x
				+ data->middle.player_size) / SCALE, (double)(data->player.y
				+ data->middle.player_size) / SCALE},
			(double)data->player.rotat + rotat);
	height_dist = 0;
	if (wall.collide.checker)
	{
		height_dist = (double)(data->height)
			/ ((wall.collide.dist) * cos((rotat) * PI180));
		wall.height = height_dist;
		wall.start = ray_start;
		wall.width = size;
		ft_print_line_screen(data, wall);
	}
}

void	ft_print_wall(t_data *data)
{
	int		ray_number;
	double	rad;
	int		size_ray;
	int		i;
	float	fov_2;

	i = 0;
	fov_2 = FOV / 2.0f;
	ray_number = data->width;
	rad = FOV / ray_number;
	size_ray = 1;
	while (i < ray_number)
	{
		if (i != 0)
			ft_use_dda(data, (double)(i) *rad - fov_2, size_ray,
				(ray_number - i) * size_ray);
		else
			ft_use_dda(data, fov_2, size_ray, 0);
		i++;
	}
}
