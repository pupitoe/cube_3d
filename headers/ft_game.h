/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/16 20:30:42 by tlassere         ###   ########.fr       */
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
# define PLAYER_SIZE 20

# define PLAYER_SPEED 1
# define ROT_SPEED 1.0f

# define FOV 60.0f
# define COUNT_RAY 200.0f
# define COUNT_RAY_MAP 30.0f

int		ft_game_start(t_data *data);
void	ft_put_block(mlx_image_t *img, t_vec pos, t_vec size, int color);
void	ft_print_hook(void *vdata);

void	ft_delet_images(t_data *data);
int		ft_load_image(t_data *data, uint32_t width, uint32_t height);
void	ft_delet_textures(t_data *data);
int		ft_put_img(t_data *data);
void	ft_print_many_ray(t_data *data);
void	ft_print_map(t_data *data);
void	ft_print_wall(t_data *data);
void	ft_print_game(t_data *data);

#endif