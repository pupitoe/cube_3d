/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/29 19:26:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# define WINDOW_HIGHT 540
# define WINDOW_WIDTH 960

# define WALL 1
# define FLOOR 0

# define MAP_SIZE_OBJECT 50
# define SCALE 40

# define PLAYER_SPEED 5
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define PINK 0xFF00FFFF

int		ft_game_start(t_data *data);
void	ft_put_block(mlx_image_t *img, t_vec pos, t_vec size, int color);
void	ft_print_map_hook(void *vdata);

void	ft_delet_images(t_data *data);
int		ft_load_image(t_data *data);
int		ft_put_img(t_data *data);
void	ft_put_ray(mlx_image_t *image, float corner, t_vec size);

#endif