/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/02 17:23:37 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_dda(t_data *data)
{
	t_ray_data	ray;

	ray.start.y = (float)data->player.y + SCALE / 2;
	ray.start.x = (float)data->player.x + SCALE / 2;
	ray.end.y = data->player.y + SCALE / 2 + (RAY_VIEW * cos(data->player.rotat * PI180));
	ray.end.x = data->player.x + SCALE / 2 + (RAY_VIEW * sin(data->player.rotat * PI180));
	ray.norm = ft_vector_norm(ray.start, ray.end);
	ray.step_size.x = sqrt(1 + ft_pow(ray.norm.y / ray.norm.x, 2));
	ray.step_size.y = sqrt(1 + ft_pow(ray.norm.x / ray.norm.y, 2));
	
}