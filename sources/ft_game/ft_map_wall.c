/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:36:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/19 22:05:02 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_get_pixel_color(uint8_t *texture_pixel)
{
	return (ft_get_rgba(texture_pixel[0], texture_pixel[1], texture_pixel[2],
		texture_pixel[3]));
}

static void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
	t_data_wall wall, float pos_x)
{
	uint8_t			*texture_x;
	int 			mid;
	long double		ratio_height;
	unsigned int	ft_get_y;
	int	step;
	int	start_at;

	step = 0;
	start_at = 0;
	mid	= 0;
	if (texture && wall.height >= 0 && (unsigned int)wall.start < data->img.game->width && pos_x < 1)
	{
		ratio_height = (long double)texture->height / (long double)wall.height;
		if (wall.height > data->mlx->height)
			start_at = (wall.height - data->mlx->height) / 2;
		else
			mid = (data->mlx->height - wall.height) / 2;
		texture_x = texture->pixels + (unsigned int)(texture->width * pos_x) * sizeof(int);
		while (step < data->mlx->height && step < wall.height)
		{
			ft_get_y = ((unsigned )(ratio_height * (float)(step + start_at)) * texture->width) * sizeof(int);
			mlx_put_pixel(data->img.game, wall.start, step + mid, ft_get_pixel_color(texture_x + ft_get_y));
			step++;
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
	if (wall.height < 0)
		wall.height = data->mlx->height;
	if (wall.collide.wall_dir == W_NORTH || wall.collide.wall_dir == W_SOUTH)
		pos_x = wall.collide.len.x;
	else
		pos_x = wall.collide.len.y;
	pos_x = pos_x - (int)pos_x;
	ft_print_line_texture(data, texture, wall, pos_x);
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
