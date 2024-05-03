/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:12:53 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 14:30:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_get_x(t_data *data, int x)
{
	int	signe;

	signe = 1;
	if (x > 0)
		signe = -1;
	if (x)
		x += signe;
	while (x && ft_is_hitbox(data->map, data->map_size,
			(t_vec){data->player.x + x, data->player.y, 0}))
		x += signe;
	return (x);
}

int	ft_get_y(t_data *data, int y)
{
	int	signe;

	signe = 1;
	if (y > 0)
		signe = -1;
	if (y)
		y += signe;
	while (y && ft_is_hitbox(data->map, data->map_size,
			(t_vec){data->player.x, data->player.y + y, 0}))
		y += signe;
	return (y);
}

void	ft_move(t_data *data, int val, float rotat)
{
	int		x;
	int		y;
	float	rotat_pi;

	rotat += data->player.rotat;
	rotat_pi = rotat * PI180;
	x = (int)lround(val * -cos(rotat_pi));
	y = (int)lround(val * sin(rotat_pi));
	if (ft_is_hitbox(data->map, data->map_size,
			(t_vec){data->player.x + x, data->player.y, 0}))
		x = ft_get_x(data, x);
	if (ft_is_hitbox(data->map, data->map_size,
			(t_vec){data->player.x, data->player.y + y, 0}))
		y = ft_get_y(data, y);
	data->player.x += x;
	data->player.y += y;
}
