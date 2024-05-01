/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:06:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/01 17:36:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_print_texture(mlx_image_t *image, mlx_texture_t *hud,
	unsigned int frame, t_data *data)
{
	uint8_t			*color;
	unsigned int	width;
	unsigned int	height;

	width = 0;
	while (width < SIZE_FRAME_HUD)
	{
		height = 0;
		while (height < SIZE_FRAME_HUD)
		{
			color = hud->pixels + ((width + SIZE_FRAME_HUD * frame)
					+ height * hud->width) * sizeof(int);
			mlx_put_pixel(image, width + data->middle.screen.x
				- SIZE_FRAME_MID_HUD, data->height - CENTER_HUD + height,
				ft_get_pixel_color(color));
			height++;
		}
		width++;
	}
}

void	ft_print_hud(t_data *data)
{
	if (!data->konami_toggle)
		ft_print_texture(data->img.game, data->texture.hud,
			(size_t)data->time.all_time % FRAME_ANIMATION, data);
	else
		ft_print_texture(data->img.game, data->texture.hud_konami,
			(size_t)data->time.all_time % FRAME_ANIMATION, data);
}
