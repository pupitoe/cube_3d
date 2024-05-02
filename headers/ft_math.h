/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:27:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 15:27:51 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# define PI 3.14159265359f
# define PI180 0.017453292519943295f

float	ft_pow(float nbr, int pow);
t_dvec	ft_vector_norm(t_dvec fvec1, t_dvec fvec2);

#endif
