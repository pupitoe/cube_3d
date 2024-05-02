/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:23:52 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 15:35:03 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DDA_H
# define FT_DDA_H

# define DISTANCE_RAY_VIEW 20
# define X_LAST 1
# define Y_LAST 2

typedef struct s_ray_data
{
	t_dvec	start;
	t_dvec	end;
	t_dvec	norm;
	t_dvec	step_size;
	t_ivec	step_unit;
	t_dvec	length;
	t_ivec	map_checker;
}	t_ray_data;

typedef struct s_collide_data
{
	t_dvec	len;
	float	dist;
	int		checker;
	int		wall_dir;
	int		block_touch;
	t_ivec	block_cheked;
}	t_collide_data;

t_collide_data	ft_dda_call(t_data *data, t_dvec ray_start, double rotat,
					int (*check_block)(int));
t_collide_data	ft_dda(t_data *data, t_dvec ray_start, double rotat);
t_collide_data	ft_dda_interact(t_data *data, t_dvec ray_start, double rotat);

#endif
