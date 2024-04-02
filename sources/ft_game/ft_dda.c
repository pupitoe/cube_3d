/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/03 00:38:16 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_set_step(t_ray_data *ray)
{
	if (ray->norm.x < 0)
	{
		ray->step_unit.x = -1;
		ray->length.x = (ray->start.x - (float)ray->map_checker.x) * ray->step_size.x;
	}
	else
	{
		ray->step_unit.x = 1;
		ray->length.x = (((float)ray->map_checker.x + 1) - ray->start.x) * ray->step_size.x;
	}
	if (ray->norm.y < 0)
	{
		ray->step_unit.y = -1;
		ray->length.y = (ray->start.y - (float)ray->map_checker.y) * ray->step_size.y;
	}
	else
	{
		ray->step_unit.y = 1;
		ray->length.y = (((float)ray->map_checker.y + 1) - ray->start.y) * ray->step_size.y;
	}
}

static void	ft_colide(t_ray_data ray, t_data *data)
{
	float	ray_dist;
	int		checker;

	checker = 0;
	while (!checker && ray_dist < 100)
	{
		if (ray.length.x < ray.length.y)	
		{
			ray.map_checker.x += ray.step_unit.x;
			ray_dist = ray.length.x;
			ray.length.x += ray.step_size.x;
		}
		else
		{
			ray.map_checker.y += ray.step_unit.y;
			ray_dist = ray.length.y;
			ray.length.x += ray.step_size.y;
		}
		if (ray.map_checker.x >= 0 && ray.map_checker.x < (int)data->map_size.x
			&& ray.map_checker.y >= 0 && ray.map_checker.y < (int)data->map_size.y)
		{
			if (data->map[ray.map_checker.y][ray.map_checker.x] == 1)
				checker = 1;
		}
	}

	if (checker)
	{
		if (data->map[ray.map_checker.y][ray.map_checker.x] == 1)
			ft_put_block(data->img.map, (t_vec){(ray.map_checker.x) * MAP_SIZE_OBJECT,
				(ray.map_checker.y) * MAP_SIZE_OBJECT, 0},
				(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, GREEN);
		//mlx_put_pixel(data->img.map, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE), (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE), GREEN);
		//mlx_put_pixel(data->img.map, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE) + 1, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE), GREEN);
		//mlx_put_pixel(data->img.map, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE) + 1, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE) + 1, GREEN);
		//mlx_put_pixel(data->img.map, (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE), (int)((ray.start.x + ray_dist * ray.norm.x) * SCALE) + 1, GREEN);
		printf("touch at: x: %d, y: %d\n", ray.map_checker.x, ray.map_checker.y);
	}
}

// TODO make define for size of player
void	ft_dda(t_data *data)
{
	t_ray_data	ray;

	ray.start.y = (float)data->player.y + SCALE / 2;
	ray.start.x = (float)data->player.x + SCALE / 2;
	ray.end.x = data->player.x + SCALE / 2 + (RAY_VIEW * cos(data->player.rotat * PI180));
	ray.end.y = data->player.y + SCALE / 2 + (RAY_VIEW * sin(data->player.rotat * PI180));
	ray.norm = ft_vector_norm(ray.start, ray.end);
	ray.step_size.x = sqrt(1 + ft_pow(ray.norm.y / ray.norm.x, 2));
	ray.step_size.y = sqrt(1 + ft_pow(ray.norm.x / ray.norm.y, 2));
	ray.map_checker.x = (int)(ray.start.x / SCALE);
	ray.map_checker.y = (int)(ray.start.y / SCALE);
	ft_set_step(&ray);
	ft_colide(ray, data);
	//(void)ft_colide;
}