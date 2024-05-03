/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture_animated.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:23:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 17:03:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static uint8_t	*ft_get_pos_x(mlx_texture_t *texture, double pos_x, int frame)
{
	return (texture->pixels + ((size_t)(SIZE_DOOR * pos_x
			+ (SIZE_DOOR * frame)) * sizeof(int)));
}

void	ft_print_line_animated(t_data *data, mlx_texture_t *texture,
	t_data_wall wall, double pos_x)
{
	t_texture_pos	texture_pos;
	size_t			texture_width;
	int				step;

	step = 0;
	if (texture && wall.height >= 0 && pos_x >= 0 && pos_x < 1
		&& (unsigned int)wall.start < data->img.game->width)
	{
		ft_init_texture(&texture_pos, texture, wall, data->height);
		texture_pos.ptr_texutre_x = ft_get_pos_x(texture, pos_x,
				(long long)data->time.all_time % FRAME_ANIMATION_DOOR);
		texture_width = texture->width * sizeof(int);
		while (step < data->height && step < wall.height)
		{
			mlx_put_pixel(data->img.game, wall.start, step + texture_pos.middle,
				ft_get_pixel_color(texture_pos.ptr_texutre_x
					+ ft_get_y_pos(texture_pos.ratio_height,
						step + texture_pos.start_pixel, texture_width)));
			step++;
		}
	}
}
