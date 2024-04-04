/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/04 21:19:42 by tlassere         ###   ########.fr       */
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


static t_fvec	ft_colide(t_ray_data ray, t_data *data)
{
	float	ray_dist;
	int		checker;

	checker = 0;
	ray_dist = 0.0f;
	while (!checker && ray_dist < DISTANCE_RAY_VIEW)
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
			ray.length.y += ray.step_size.y;
		}
		if (ray.map_checker.x >= 0 && ray.map_checker.x < (int)data->map_size.x
			&& ray.map_checker.y >= 0 && ray.map_checker.y < (int)data->map_size.y)
		{
			ft_put_block(data->img.map, (t_vec){(ray.map_checker.x) * MAP_SIZE_OBJECT,
				(ray.map_checker.y) * MAP_SIZE_OBJECT, 0},
				(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, GREEN);
			if (data->map[ray.map_checker.y][ray.map_checker.x] == 1)
				checker = 1;
		}
	}
	if (checker)
	{
		ft_put_block(data->img.map, (t_vec){(ray.map_checker.x) * MAP_SIZE_OBJECT,
			(ray.map_checker.y) * MAP_SIZE_OBJECT, 0},
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, PINK);
		//printf("touch at: x: %d, y: %d\n", ray.map_checker.x, ray.map_checker.y);
	}
	return ((t_fvec){ray_dist * ray.norm.x, ray_dist * ray.norm.y});
}

// TODO make define for size of player
t_fvec	ft_dda(t_data *data, t_fvec ray_start, float rotat)
{
	t_ray_data	ray;
	t_fvec		ray_hit;

	ray.start.x = ray_start.x;
	ray.start.y = ray_start.y;
	ray.end.x = ray.start.x + cos(rotat * PI180);
	ray.end.y = ray.start.y + -sin(rotat * PI180);
	ray.norm = ft_vector_norm(ray.start, ray.end);
	ray.step_size.x = sqrt(1 + ft_pow(ray.norm.y / ray.norm.x, 2));
	ray.step_size.y = sqrt(1 + ft_pow(ray.norm.x / ray.norm.y, 2));
	ray.map_checker.x = ray.start.x;
	ray.map_checker.y = ray.start.y;
	ft_set_step(&ray);
	ray_hit = ft_colide(ray, data);
	ray_hit.x += ray.start.x;
	ray_hit.y += ray.start.y;
	return(ray_hit);
}
