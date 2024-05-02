/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:14:22 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 19:50:23 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVE_H
# define FT_MOVE_H

typedef struct s_hitbox_point
{
	t_vec	top_left;
	t_vec	top_right;
	t_vec	bottom_left;
	t_vec	bottom_right;
}	t_hitbox_point;

void	ft_key_hook_y(void *vdata);
void	ft_key_hook_x(void *vdata);
void	ft_key_hook_arrow(void *vdata);
void	ft_key_hook_tab(mlx_key_data_t key, void *vdata);
void	ft_move(t_data *data, int val, float rotat);
int		ft_is_collide(int block);
bool	ft_is_hitbox(int **map, t_vec map_size, t_vec pos);

#endif
