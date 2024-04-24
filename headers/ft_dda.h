/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:23:52 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/24 20:58:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DDA_H
# define FT_DDA_H

# define DISTANCE_RAY_VIEW 20
# define X_LAST 1
# define Y_LAST 2

typedef struct s_ray_data
{
	t_fvec	start;
	t_fvec	end;
	t_fvec	norm;
	t_fvec	step_size;
	t_ivec	step_unit;
	t_fvec	length;
	t_ivec	map_checker;
}	t_ray_data;

typedef struct s_collide_data
{
	t_fvec	len;
	float	dist;
	int		checker;
	int		wall_dir;
	int		block_touch;
}	t_collide_data;

t_collide_data	ft_dda(t_data *data, t_fvec ray_start, float rotat);

#endif
