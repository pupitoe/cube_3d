/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:08:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/19 22:36:36 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_get_pixel_color(uint8_t *texture_pixel)
{
	return (ft_get_rgba(texture_pixel[0], texture_pixel[1], texture_pixel[2],
		texture_pixel[3]));
}

static unsigned int	ft_get_y_pos(long double ratio, float pos, unsigned int width)
{
	return ((unsigned int)(ratio * pos) * width * sizeof(int));
}

void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
	t_data_wall wall, float pos_x)
{
	uint8_t			*texture_x;
	int 			mid;
	long double		ratio_height;
	int				start_at;
	int	step;

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
			mlx_put_pixel(data->img.game, wall.start, step + mid, ft_get_pixel_color(texture_x + ft_get_y_pos(ratio_height, step + start_at, texture->width)));
			step++;
		}
	}
}
