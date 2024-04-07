/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:14:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/07 12:58:58 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_put_ray(mlx_image_t *image, float corner, t_vec size)
{
	int		pos;
	double	retc;
	double	rets;

	size.y /= 2;
	retc = cos(corner * PI180);
	rets = sin(corner * PI180);
	pos = 0;
	while (pos < (int)size.y)
	{
		mlx_put_pixel(image, (int)lround(pos * retc) + MAP_SIZE_OBJECT / 2,
			-(int)lround(pos * rets) + MAP_SIZE_OBJECT / 2, PINK);
		pos++;
	}
}

static void	ft_print_ray(t_data *data, float rad)
{
	int		pos;
	double	retc;
	double	rets;
	t_ivec	c_player;
	t_ivec	pos_pixel;

	retc = cos((data->player.rotat + rad) * PI180);
	rets = -sin((data->player.rotat + rad) * PI180);
	c_player.x = data->player.x * MAP_SIZE_OBJECT / SCALE + MAP_SIZE_OBJECT / 2;
	c_player.y = data->player.y * MAP_SIZE_OBJECT / SCALE + MAP_SIZE_OBJECT / 2;
	pos = 0;
	while (pos < 100)
	{
		pos_pixel.x = (int)lround(pos * retc) + c_player.x;
		pos_pixel.y = (int)lround(pos * rets) + c_player.y;
		if (pos_pixel.x >= 0 && pos_pixel.y >= 0
			&& (size_t)pos_pixel.x < data->map_size.x * MAP_SIZE_OBJECT
			&& (size_t)pos_pixel.y < data->map_size.y * MAP_SIZE_OBJECT)
			mlx_put_pixel(data->img.map, pos_pixel.x, pos_pixel.y, PINK);
		pos++;
	}
}

void	ft_print_many_ray(t_data *data)
{
	int		ray_number;
	float	rad;
	float	fov_tmp;
	int		i;

	ray_number = COUNT_RAY_MAP;
	rad = FOV / COUNT_RAY_MAP;
	fov_tmp = FOV / 2.0f;
	i = 0;
	while (i < ray_number)
	{
		ft_print_ray(data, (float)i * rad - fov_tmp);
		i++;
	}
	//ft_print_ray(data, 0);
}
