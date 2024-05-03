/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:31:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/03 12:33:25 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static t_dvec	ft_get_pos_ratio(int wall_dir, t_dvec len, t_ivec block_checked)
{
	t_dvec	posx_ratio;

	posx_ratio.x = len.x - (long long)len.x;
	posx_ratio.y = len.y - (long long)len.y;
	if (wall_dir != W_NORTH)
	{
		if ((int)(len.x) - 1 == block_checked.x)
			posx_ratio.x = MAX_PRECISION;
		else if ((int)(len.y) + 1 == block_checked.y)
			posx_ratio.x = 0;
		if ((int)(len.y) - 1 == block_checked.y)
			posx_ratio.y = MAX_PRECISION;
		else if ((int)(len.y) + 1 == block_checked.y)
			posx_ratio.y = 0;
	}
	return (posx_ratio);
}

/**
 * MAX_PRECISION is a limit for X position.
 * texture NORTH and EAST are reversed, so the pos_x is reverse
 * to get the right feel
*/
double	ft_get_pos_x_wall(int wall_dir, t_dvec len, t_ivec block_checked)
{
	double	pos_x;
	double	buffer;
	t_dvec	posx_ratio;

	posx_ratio = ft_get_pos_ratio(wall_dir, len, block_checked);
	if (posx_ratio.x > MAX_PRECISION)
		posx_ratio.x = MAX_PRECISION;
	if (posx_ratio.y > MAX_PRECISION)
		posx_ratio.y = MAX_PRECISION;
	if (wall_dir == W_NORTH || wall_dir == W_SOUTH)
		pos_x = posx_ratio.x;
	else
		pos_x = posx_ratio.y;
	buffer = pos_x;
	if (wall_dir == W_NORTH || wall_dir == W_EAST)
		pos_x = MAX_PRECISION - pos_x;
	if (wall_dir == W_NORTH && ((int)len.x) != block_checked.x)
	{
		pos_x = MAX_PRECISION;
		if (posx_ratio.x != MAX_PRECISION)
			pos_x = 0;
	}
	return (pos_x);
}
