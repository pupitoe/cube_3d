/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:15:28 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/06 16:46:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_print_horizon(t_data *data)
{
	int	height;

	height = data->mlx->height / 2;
	ft_put_block(data->img.game, (t_vec){0, 0, 0}, (t_vec){data->mlx->width,
		height, 0}, data->texture.ceiling_rgba);
	ft_put_block(data->img.game, (t_vec){0, height, 0},
		(t_vec){data->mlx->width, data->mlx->height - height, 0},
		data->texture.floor_rgba);
}

void	ft_print_game(t_data *data)
{
	ft_print_horizon(data);
	ft_print_wall(data);
}
