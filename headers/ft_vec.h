/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:12:35 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 19:13:35 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VEC_H
# define FT_VEC_H

typedef struct s_vec
{
	size_t	x;
	size_t	y;
	float	rotat;
}	t_vec;

typedef struct s_ivec
{
	int	x;
	int	y;
}	t_ivec;

typedef struct s_fvec
{
	float	x;
	float	y;
}	t_fvec;

#endif
