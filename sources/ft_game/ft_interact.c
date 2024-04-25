/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:25:46 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/25 13:34:48 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_key_hook_interact(t_data *data)
{
	t_collide_data	collide;

	collide = ft_dda(data, (t_fvec){(float)(data->player.x
				+ data->middle.player_size) / SCALE, (float)(data->player.y
				+ data->middle.player_size) / SCALE},
			data->player.rotat);
	if (collide.block_touch == DOOR_OP && collide.dist < DIST_INTERACT)
		data->map[collide.block_cheked.y][collide.block_cheked.x] = DOOR_CL;
	else if (collide.block_touch == DOOR_CL && collide.dist < DIST_INTERACT)
		data->map[collide.block_cheked.y][collide.block_cheked.x] = DOOR_OP;
}
