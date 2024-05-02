/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:04:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 15:27:51 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

t_collide_data	ft_dda_interact(t_data *data, t_dvec ray_start, float rotat)
{
	return (ft_dda_call(data, ray_start, rotat, &ft_interact_block));
}

t_collide_data	ft_dda(t_data *data, t_dvec ray_start, float rotat)
{
	return (ft_dda_call(data, ray_start, rotat, &ft_is_collide));
}
