/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:51:14 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/18 12:25:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

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

struct s_data_time
{
	float	time_passed;
	float	framerate;
};

struct s_img
{
	mlx_image_t	*map;
	mlx_image_t	*player;
	mlx_image_t	*game;
};

struct s_texture
{
	mlx_texture_t	*icon;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				floor_rgba;
	int				ceiling_rgba;
};

struct s_middle
{
	t_ivec	screen;
	int		player_size;
};

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	t_rgb		*floor;
	t_rgb		*celling;
	char		*map;
}	t_map;

typedef struct s_pov
{
	double	position_x;
	double	position_y;
	int		angle;
}	t_pov;

typedef struct s_data
{
	t_map				*map_parser;
	t_vec				player;
	int					**map;
	t_vec				map_size;
	int					print_map;
	struct s_data_time	time;
	mlx_t				*mlx;
	struct s_texture	texture;
	struct s_img		img;
	struct s_middle		middle;
}	t_data;

#endif
