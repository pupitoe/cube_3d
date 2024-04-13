/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_wall.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:49:51 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/13 19:41:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_WALL_H
# define FT_DATA_WALL_H

typedef struct s_data_wall
{
	int				height;
	int				width;
	int				start;
	t_collide_data	collide;
}t_data_wall;

enum	e_wall_dir
{
	W_NO_DIR = 0,
	W_NORTH,
	W_EAST,
	W_SOUTH,
	W_WEST
};

#endif