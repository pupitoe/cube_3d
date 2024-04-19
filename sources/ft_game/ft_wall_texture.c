/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/19 23:10:20 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_get_pixel_color(uint8_t *texture_pixel)
{
	return (ft_get_rgba(texture_pixel[0], texture_pixel[1], texture_pixel[2],
			texture_pixel[3]));
}

static unsigned int	ft_get_y_pos(long double ratio, float pos,
	unsigned int width)
{
	return ((unsigned int)(ratio * pos) *width * sizeof(int));
}

static uint8_t	*ft_get_x_pos(mlx_texture_t *texture, float pos_x)
{
	return (texture->pixels + (unsigned int)(texture->width * pos_x)
		* sizeof(int));
}

static void	ft_init_texture(t_texture_pos *texture_pos,
	mlx_texture_t *texture, t_data_wall wall, int screen_height)
{
	ft_bzero(texture_pos, sizeof(t_texture_pos));
	texture_pos->ratio_height = (long double)texture->height
		/ (long double)wall.height;
	if (wall.height > screen_height)
		texture_pos->start_pixel = (wall.height - screen_height) / 2;
	else
		texture_pos->middle = (screen_height - wall.height) / 2;
}

void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
	t_data_wall wall, float pos_x)
{
	t_texture_pos	texture_pos;
	int				step;

	step = 0;
	if (texture && wall.height >= 0
		&& (unsigned int)wall.start < data->img.game->width && pos_x < 1)
	{
		ft_init_texture(&texture_pos, texture, wall, data->mlx->height);
		texture_pos.ptr_texutre_x = ft_get_x_pos(texture, pos_x);
		while (step < data->mlx->height && step < wall.height)
		{
			mlx_put_pixel(data->img.game, wall.start, step + texture_pos.middle,
				ft_get_pixel_color(texture_pos.ptr_texutre_x
					+ ft_get_y_pos(texture_pos.ratio_height,
						step + texture_pos.start_pixel, texture->width)));
			step++;
		}
	}
}
