/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:31 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/02 17:14:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

t_fvec	ft_vector_norm(t_fvec fvec1, t_fvec fvec2)
{
	return ((t_fvec){fvec2.x - fvec1.x, fvec2.y - fvec1.y});
}

float	ft_pow(float nbr, int pow)
{
	float	result;

	result = nbr;
	pow--;
	while (pow > 0)
	{
		pow--;
		result *= nbr;
	}
	return (result);
}
