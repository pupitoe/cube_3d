/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:09:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/01 16:30:38 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# define FRAME_ANIMATION 5
# define SIZE_FRAME_HUD 64
# define SIZE_FRAME_MID_HUD 32
# define CENTER_HUD 75

# define FRAME_ANIMATION_DOOR 15
# define SIZE_DOOR 256

void	ft_print_map(t_data *data);
void	ft_print_wall(t_data *data);
void	ft_print_game(t_data *data);
void	ft_print_hud(t_data *data);
void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
			t_data_wall wall, float pos_x);
int		ft_get_pixel_color(uint8_t *texture_pixel);
void	ft_print_line_animated(t_data *data, mlx_texture_t *texture,
			t_data_wall wall, float pos_x);
size_t	ft_get_y_pos(long double ratio, long double pos_y,
			size_t width);
void	ft_init_texture(t_texture_pos *texture_pos,
			mlx_texture_t *texture, t_data_wall wall, int screen_height);

#endif
