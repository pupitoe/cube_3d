/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:06:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 17:47:45 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_print_hud(t_data *data)
{
	ft_put_block(data->img.game, (t_vec){0, data->mlx->height - HEIGHT_HUD, 0},
		(t_vec){data->mlx->width, HEIGHT_HUD, 0}, BLUE | ALPHA_255);
}
