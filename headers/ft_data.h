/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:51:14 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 22:04:56 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

typedef struct s_vec
{
	size_t	x;
	size_t	y;
	float	rotat;
}t_vec;

typedef struct s_ivec
{
	int	x;
	int	y;
}t_ivec;

typedef struct s_fvec
{
	float	x;
	float	y;
}t_fvec;

struct s_data_time
{
	float	time_passed;
	float	framerate;
};

struct s_img
{
	mlx_image_t	*map;
	mlx_image_t	*player;
	mlx_image_t	*ray;
	mlx_image_t	*game;
};

struct s_texture
{
	mlx_texture_t	*icon;
	int				floor_rgba;
	int				ceiling_rgba;
};

struct s_middle
{
	t_ivec	screen;
	int		player_size;
};


typedef struct s_data
{
	t_vec				player;
	int					**map;
	t_vec				map_size;
	struct s_data_time	time;
	mlx_t				*mlx;
	struct s_texture	texture;
	struct s_img		img;
	struct s_middle		middle;
}t_data;

#endif