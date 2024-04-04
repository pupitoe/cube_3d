/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:23:52 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/04 13:45:05 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DDA_H
# define FT_DDA_H

#define RAY_VIEW 5 * SCALE

typedef struct s_ray_data
{
	t_fvec	start;
	t_fvec	end;
	t_fvec	norm;
	t_fvec	step_size;
	t_ivec	step_unit;
	t_fvec	length;
	t_ivec	map_checker;
}t_ray_data;

float	ft_dda(t_data *data);

#endif
