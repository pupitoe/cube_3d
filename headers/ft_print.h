/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:09:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 21:05:49 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# define HEIGHT_HUD 90
# define FRAME_ANIMATION 5
# define SIZE_FRAME_HUD 64
# define SIZE_FRAME_MID_HUD 32
# define CENTER_HUD 75
# define SPEED_FRAME 10

void	ft_print_many_ray(t_data *data);
void	ft_print_map(t_data *data);
void	ft_print_wall(t_data *data);
void	ft_print_game(t_data *data);
void	ft_print_hud(t_data *data);
void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
			t_data_wall wall, float pos_x);
int		ft_get_pixel_color(uint8_t *texture_pixel);
#endif
