/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/28 14:51:36 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

/**
 * @param texture_pixel is position of pixel to get color;
 * @return color of pixel pos;
*/
static int	ft_get_pixel_color(uint8_t *texture_pixel)
{
	return (ft_get_rgba(texture_pixel[0], texture_pixel[1], texture_pixel[2],
			texture_pixel[3]));
}

/**
 * @param ratio is texture height / wall height (to make proportion of image)
 * @param pos_y is pos in Y of Wall pixel
 * @param width is with of texture
 * @return Y position of image 
*/
static unsigned int	ft_get_y_pos(long double ratio, float pos_y,
	unsigned int width)
{
	return ((unsigned int)(ratio * pos_y) *width);
}

/**
 * @param pos_x value 0 >= && .9999... <= value; to get X of image
 * @return ptr of pixel in X
*/
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
	size_t			texture_width;
	int				step;

	step = 0;
	if (texture && wall.height >= 0
		&& (unsigned int)wall.start < data->img.game->width && pos_x < 1)
	{
		ft_init_texture(&texture_pos, texture, wall, data->mlx->height);
		texture_pos.ptr_texutre_x = ft_get_x_pos(texture, pos_x);
		texture_width = texture->width * sizeof(int);
		while (step < data->mlx->height && step < wall.height)
		{
			mlx_put_pixel(data->img.game, wall.start, step + texture_pos.middle,
				ft_get_pixel_color(texture_pos.ptr_texutre_x
					+ ft_get_y_pos(texture_pos.ratio_height,
						step + texture_pos.start_pixel, texture_width)));
			step++;
		}
	}
}
