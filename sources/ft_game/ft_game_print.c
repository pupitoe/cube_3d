/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:15:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/01 17:22:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_print_horizon(t_data *data)
{
	ft_put_block(data->img.game, (t_vec){0, 0, 0}, (t_vec){data->width,
		data->middle.screen.y, 0}, data->texture.ceiling_rgba);
	ft_put_block(data->img.game, (t_vec){0, data->middle.screen.y, 0},
		(t_vec){data->width, data->height - data->middle.screen.y, 0},
		data->texture.floor_rgba);
}

void	ft_print_game(t_data *data)
{
	data->middle.screen.y = data->height / 2;
	data->middle.screen.x = data->width / 2;
	ft_print_horizon(data);
	ft_print_wall(data);
	ft_print_hud(data);
}
