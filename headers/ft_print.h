/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:09:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 17:10:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

void	ft_print_many_ray(t_data *data);
void	ft_print_map(t_data *data);
void	ft_print_wall(t_data *data);
void	ft_print_game(t_data *data);
void	ft_print_hud(t_data *data);
void	ft_print_line_texture(t_data *data, mlx_texture_t *texture,
			t_data_wall wall, float pos_x);

#endif
