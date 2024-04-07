/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:18:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 22:18:48 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_print_hook(void *vdata)
{
	t_data	*data;

	data = vdata;
	data->time.time_passed += data->mlx->delta_time;
	if (data->time.time_passed >= data->time.framerate)
	{
		ft_print_map(data);
		ft_print_many_ray(data);
		data->time.time_passed -= data->time.framerate;
	}
	ft_print_game(data);
}
