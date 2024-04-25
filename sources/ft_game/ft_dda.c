/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:04:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/25 14:11:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

t_collide_data	ft_dda(t_data *data, t_fvec ray_start, float rotat)
{
	return (ft_dda_call(data, ray_start, rotat, &ft_is_collide));
}
