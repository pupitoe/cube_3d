/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:31 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 15:37:27 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

t_dvec	ft_vector_norm(t_dvec fvec1, t_dvec fvec2)
{
	return ((t_dvec){fvec2.x - fvec1.x, fvec2.y - fvec1.y});
}

double	ft_pow(double nbr, int pow)
{
	double	result;

	result = nbr;
	pow--;
	while (pow > 0)
	{
		pow--;
		result *= nbr;
	}
	return (result);
}
