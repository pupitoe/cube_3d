/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_texture_animated.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:23:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/30 19:28:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static uint8_t	*ft_get_pos_x(mlx_texture_t *texture, float pos_x, int frame)
{
	return (texture->pixels + ((size_t)(SIZE_DOOR * pos_x + (SIZE_DOOR * frame)) * sizeof(int)));
}

void	ft_print_line_animated(t_data *data, mlx_texture_t *texture,
	t_data_wall wall, float pos_x)
{
	static unsigned int	frame = 0;
	t_texture_pos	texture_pos;
	size_t			texture_width;
	int				step;

	step = 0;
	if (texture && wall.height >= 0
		&& (unsigned int)wall.start < data->img.game->width && pos_x < 1)
	{
		ft_init_texture(&texture_pos, texture, wall, data->mlx->height);
		texture_pos.ptr_texutre_x = ft_get_pos_x(texture, pos_x, frame / 1000);
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
	if (++frame >= FRAME_ANIMATION_DOOR * 1000)
		frame = 0;
}
