/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:41 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 13:24:23 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# define WINDOW_HEIGHT 540
# define WINDOW_WIDTH 960
# define WINDOW_WIDTH_MAX 1920
# define WINDOW_HEIGHT_MAX 1080

# define WALL 1
# define FLOOR 0
# define DOOR_OP 2
# define DOOR_CL 3

# define MAP_SIZE_OBJECT 50
# define SCALE 40
# define PLAYER_SIZE 10

# define PLAYER_SPEED 2
# define ROT_SPEED 2.0f

# define FOV 60.0f
# define COUNT_RAY 200.0f
# define COUNT_RAY_MAP 30.0f

# define DIST_INTERACT 2.0f
# define ROTATE_INTERACT 10.0f

# define KONAMI_SIZE 10

# define DOOR_PATH "./asset/door.png"
# define HUD_PATH "./asset/hud.png"
# define HUDK_PATH "./asset/hud_konami.png"

# define WIDTH_HUD 320
# define HEIGHT_HUD 64
# define WIDTH_DOOR 3840
# define HEIGHT_DOOR 256 

int		ft_game_start(t_data *data);
void	ft_key_hook_other_key(mlx_key_data_t key, void *vdata);
void	ft_put_block(mlx_image_t *img, t_vec pos, t_vec size, int color);
int		ft_set_hook(t_data *data);
void	ft_print_hook(void *vdata);

void	ft_delet_images(t_data *data);
int		ft_load_image(t_data *data);
int		ft_set_textures(t_data *data);
void	ft_delet_textures(t_data *data);
int		ft_set_icon(t_data *data);
int		ft_put_img(t_data *data);
void	ft_key_hook_interact(t_data *data);
void	ft_cursor_func(double xpos, double ypos, void *vdata);
int		ft_interact_block(int block);
void	ft_konami(keys_t key, t_data *data);

#endif
