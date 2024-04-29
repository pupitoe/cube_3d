/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:54:19 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/28 19:42:34 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_cursor_func(double xpos, double ypos, void *vdata)
{
	static double	last_xpos = 0;
	t_data			*data;

	(void)ypos;
	data = vdata;
	if (data->mouse_toggle)
		data->player.rotat -= (xpos - last_xpos) / 10;
	last_xpos = xpos;
}
