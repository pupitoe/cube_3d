/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_wall.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:49:51 by tlassere          #+#    #+#             */
/*   Updated: 2024/05/02 15:15:08 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_WALL_H
# define FT_DATA_WALL_H

# define MAX_PRECISION 0.9999999999999999

typedef struct s_data_wall
{
	int				height;
	int				width;
	int				start;
	t_collide_data	collide;
}	t_data_wall;

enum	e_wall_dir
{
	W_NO_DIR = 0,
	W_NORTH,
	W_EAST,
	W_SOUTH,
	W_WEST
};

typedef struct s_texture_pos
{
	uint8_t		*ptr_texutre_x;
	long double	ratio_height;
	int			start_pixel;
	int			middle;
}	t_texture_pos;

#endif
