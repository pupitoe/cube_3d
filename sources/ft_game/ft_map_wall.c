/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/18 18:31:05 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_print_line_texture(mlx_image_t *game, mlx_texture_t *texture,
	int height, int start_x , float pos_x)
{
	
	if (texture && height >= 0 && (unsigned int)height < game->height
		&& start_x >= 0 && (unsigned)start_x < game->width && pos_x < 1)
	{
		while (height)
		{
			if (start_x == 0)
				printf("%i\n", (unsigned) (pos_x * texture->width));
			height--;
			mlx_put_pixel(game, start_x, height, texture->pixels[(unsigned )(texture->width * height + pos_x)]);
		}
		
	}
}

static void	ft_print_line_screen(t_data *data, t_data_wall wall)
{
	mlx_texture_t	*texture;
	float			pos_x;

	texture = NULL;
	pos_x = 0;
	if (wall.collide.wall_dir == W_NORTH)
		texture = data->texture.north;
	else if (wall.collide.wall_dir == W_SOUTH)
		texture = data->texture.south;
	else if (wall.collide.wall_dir == W_EAST)
		texture = data->texture.east;
	else if (wall.collide.wall_dir == W_WEST)
		texture = data->texture.west;
	if (wall.height < 0 || wall.height > data->mlx->height)
		wall.height = data->mlx->height;
	if (wall.collide.wall_dir == W_NORTH || wall.collide.wall_dir == W_SOUTH)
		pos_x = wall.collide.len.x *= SCALE;
	else
		pos_x = wall.collide.len.y *= SCALE;
	pos_x = pos_x - (int)pos_x;
	ft_print_line_texture(data->img.game, texture, wall.height, wall.start, pos_x);
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
