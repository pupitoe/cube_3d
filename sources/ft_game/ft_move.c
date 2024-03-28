/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:12:53 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 23:13:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_move(t_data *data, int val, float rotat)
{
	int		x;
	int		y;
	float	rotat_pi;

	rotat += data->player.rotat;
	rotat_pi = rotat * PI180;
	x = (int)lround(val * -cos(rotat_pi));
	y = (int)lround(val * sin(rotat_pi));
	data->player.x += x;
	data->player.y += y;
	data->img.player->instances[0].x += x;
	data->img.player->instances[0].y += y;
}
