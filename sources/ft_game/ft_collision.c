/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:31:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 19:50:23 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_is_collide(int block)
{
	return (block == WALL || block == DOOR_OP);
}

static int	ft_check_dist(t_vec map_size, t_vec player)
{
	return (player.x >= 0 && player.x < map_size.x
		&& player.y >= 0 && player.y < map_size.y);
}

bool	ft_is_hitbox(int **map, t_vec map_size, t_vec pos)
{
	t_hitbox_point	hit;
	t_vec			hit_basic;
	t_vec			hit_size;

	hit_basic = (t_vec){pos.x / SCALE, pos.y / SCALE, 0};
	hit_size = (t_vec){(pos.x + PLAYER_SIZE - 1) / SCALE,
		(pos.y + PLAYER_SIZE - 1) / SCALE, 0};
	hit.top_left = (t_vec){hit_basic.x, hit_basic.y, 0};
	hit.top_right = (t_vec){hit_size.x, hit_basic.y, 0};
	hit.bottom_left = (t_vec){hit_basic.x, hit_size.y, 0};
	hit.bottom_right = (t_vec){hit_size.x, hit_size.y, 0};
	return (ft_check_dist(map_size, hit_basic)
		&& ft_check_dist(map_size, hit_size)
		&& (ft_is_collide(map[hit.top_left.y][hit.top_left.x])
		|| ft_is_collide(map[hit.top_right.y][hit.top_right.x])
		|| ft_is_collide(map[hit.bottom_left.y][hit.bottom_left.x])
		|| ft_is_collide(map[hit.bottom_right.y][hit.bottom_right.x])));
}
