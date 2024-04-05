/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:12:53 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/02 17:30:25 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_get_x(t_data *data, int x)
{
	if (x < 0)
	{
		x++;
		while (x && ft_is_hitbox(data,
				(t_vec){data->player.x + x, data->player.y, 0}))
			x++;
	}
	else
	{
		x--;
		while (x && ft_is_hitbox(data,
				(t_vec){data->player.x + x, data->player.y, 0}))
			x--;
	}
	return (x);
}

int	ft_get_y(t_data *data, int y)
{
	if (y < 0)
	{
		y++;
		while (y && ft_is_hitbox(data,
				(t_vec){data->player.x, data->player.y + y, 0}))
			y++;
	}
	else
	{
		y--;
		while (y && ft_is_hitbox(data,
				(t_vec){data->player.x, data->player.y + y, 0}))
			y--;
	}
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
	if (ft_is_hitbox(data, (t_vec){data->player.x + x, data->player.y, 0}))
		x = ft_get_x(data, x);
	if (ft_is_hitbox(data, (t_vec){data->player.x, data->player.y + y, 0}))
		y = ft_get_y(data, y);
	data->player.x += x;
	data->player.y += y;
}
