/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:25:46 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/03 12:53:59 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_interact_block(int block)
{
	return (block == DOOR_CL || block == DOOR_OP);
}

static void	ft_interact(t_collide_data collide, t_data *data)
{
	int	buffer_touched;

	if (collide.checker)
	{
		buffer_touched = data->map[collide.block_checked.y]
		[collide.block_checked.x];
		if (collide.block_touch == DOOR_CL
			&& buffer_touched == DOOR_CL && collide.dist < DIST_INTERACT)
			data->map[collide.block_checked.y]
			[collide.block_checked.x] = DOOR_OP;
		else if (collide.block_touch == DOOR_OP
			&& buffer_touched == DOOR_OP && collide.dist < DIST_INTERACT)
		{
			data->map[collide.block_checked.y]
			[collide.block_checked.x] = DOOR_CL;
			if (ft_is_hitbox(data->map, data->map_size, data->player))
				data->map[collide.block_checked.y]
				[collide.block_checked.x] = DOOR_OP;
		}
	}
	return ;
}

void	ft_key_hook_interact(t_data *data)
{
	t_collide_data	collide_right;
	t_collide_data	collide_center;
	t_collide_data	collide_left;
	t_dvec			player_pos;

	player_pos = (t_dvec){(float)(data->player.x
			+ data->middle.player_size) / SCALE,
		(float)(data->player.y) / SCALE};
	collide_center = ft_dda_interact(data, player_pos, data->player.rotat);
	collide_right = ft_dda_interact(data, player_pos, data->player.rotat
			- ROTATE_INTERACT);
	collide_left = ft_dda_interact(data, player_pos, data->player.rotat
			+ ROTATE_INTERACT);
	ft_interact(collide_center, data);
	ft_interact(collide_left, data);
	ft_interact(collide_right, data);
}
