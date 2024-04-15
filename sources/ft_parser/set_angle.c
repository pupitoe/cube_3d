/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:13 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/12 20:44:22 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	set_angle(t_pov *player, char angle)
{
	if (angle == 'N')
		player->angle = 90;
	if (angle == 'W')
		player->angle = 180;
	if (angle == 'S')
		player->angle = 270;
	if (angle == 'E')
		player->angle = 0;
}
