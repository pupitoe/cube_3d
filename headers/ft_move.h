/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:14:22 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/16 18:55:34 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MOVE_H
# define FT_MOVE_H

void	ft_key_hook_y(void *vdata);
void	ft_key_hook_x(void *vdata);
void	ft_key_hook_arrow(void *vdata);
void	ft_move(t_data *data, int val, float rotat);
bool	ft_is_hitbox(t_data *data, t_vec pos);

#endif