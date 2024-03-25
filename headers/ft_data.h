/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:51:14 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/25 23:10:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

typedef struct s_vec
{
	size_t	x;
	size_t	y;
	int		rotat;
}t_vec;

struct s_data_time
{
	float	time_passed;
	float	framerate;
};

typedef struct s_data
{
	t_vec				player;
	int					**map;
	t_vec				map_size;
	struct s_data_time	time;
	mlx_t				*mlx;
}t_data;

#endif