/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/18 23:33:16 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
	int height, int start_x , float pos_x)
{
	int				color;
	uint8_t			*texture_x;
	int 			mid;
	float			ratio_height;
	float			pos;
	unsigned int	ft_get_y;

	if (texture && height >= 0 && (unsigned int)height < data->img.game->height
		&& start_x >= 0 && (unsigned)start_x < data->img.game->width && pos_x < 1)
	{
		if ((unsigned int)height > texture->height)
			ratio_height = (long double)height / (long double)texture->height;
		else
			ratio_height = (long double)texture->height / (long double)height;
		mid = (data->mlx->height - height) / 2;
		texture_x = texture->pixels + (unsigned int)(texture->width * pos_x) * sizeof(int);
		pos = 0;
		while (height)
		{
			height--;
			ft_get_y = (unsigned )((unsigned )(pos - ((int)pos - pos)) * texture->width) * sizeof(int);
			ft_get_y = 0;
			color = ft_get_rgba(*(texture_x + ft_get_y), *(texture_x + 1 + ft_get_y), *(texture_x + 2 + ft_get_y), *(texture_x + 3 + ft_get_y));
			mlx_put_pixel(data->img.game, start_x, height + mid, color);
			pos += ratio_height;
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
		pos_x = wall.collide.len.x;
	else
		pos_x = wall.collide.len.y;
	pos_x = pos_x - (int)pos_x;
	ft_print_line_texture(data, texture, wall.height, wall.start, pos_x);
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
