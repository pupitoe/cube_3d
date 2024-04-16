/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:31:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/16 20:16:45 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

bool	ft_is_hitbox(int **map, t_vec pos)
{
	t_hitbox_point	hit;
	t_vec			hit_basic;
	t_vec			hit_size;

	hit_basic = (t_vec){pos.x / SCALE, pos.y / SCALE, 0};
	hit_size = (t_vec){(pos.x + PLAYER_SIZE - 1) / SCALE,
		(pos.y + PLAYER_SIZE - 1) / SCALE, 0};
	hit.top_left = (t_vec){hit_basic.x, hit_basic.y, 0};
	hit.top_right = (t_vec){hit_size.x, hit_basic.y, 0};
	hit.bottum_left = (t_vec){hit_basic.x, hit_size.y, 0};
	hit.bottum_right = (t_vec){hit_size.x, hit_size.y, 0};
	return (map[hit.top_left.y][hit.top_left.x] == WALL
		|| map[hit.top_right.y][hit.top_right.x] == WALL
		|| map[hit.bottum_left.y][hit.bottum_left.x] == WALL
		|| map[hit.bottum_right.y][hit.bottum_right.x] == WALL);
}
