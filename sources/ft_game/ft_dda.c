/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:22:20 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/13 21:58:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_get_wall_dir(int last_dir, t_ivec step_unit)
{
	int	dir;

	if (last_dir == X_LAST)
	{
		if (step_unit.x == 1)
			dir = W_EAST;
		else
			dir = W_WEST;
	}
	else
	{
		if (step_unit.y == 1)
			dir = W_NORTH;
		else
			dir = W_SOUTH;
	}
	return (dir);
}

static void	ft_set_step(t_ray_data *ray)
{
	if (ray->norm.x < 0)
	{
		ray->step_unit.x = -1;
		ray->length.x = (ray->start.x - (float)ray->map_checker.x)
			* ray->step_size.x;
	}
	else
	{
		ray->step_unit.x = 1;
		ray->length.x = (((float)ray->map_checker.x + 1) - ray->start.x)
			* ray->step_size.x;
	}
	if (ray->norm.y < 0)
	{
		ray->step_unit.y = -1;
		ray->length.y = (ray->start.y - (float)ray->map_checker.y)
			* ray->step_size.y;
	}
	else
	{
		ray->step_unit.y = 1;
		ray->length.y = (((float)ray->map_checker.y + 1) - ray->start.y)
			* ray->step_size.y;
	}
}

static float	ft_collide_while(t_ray_data *ray, int *buffer_dir)
{
	float	ray_dist;

	ray_dist = 0;
	if (ray->length.x < ray->length.y)
	{
		ray->map_checker.x += ray->step_unit.x;
		ray_dist = ray->length.x;
		ray->length.x += ray->step_size.x;
		*buffer_dir = X_LAST;
	}
	else
	{
		ray->map_checker.y += ray->step_unit.y;
		ray_dist = ray->length.y;
		ray->length.y += ray->step_size.y;
		*buffer_dir = Y_LAST;
	}
	return (ray_dist);
}

static t_collide_data	ft_collide(t_ray_data ray, t_data *data)
{
	t_collide_data	ray_content;
	int				checker;

	checker = false;
	ray_content.dist = 0.0f;
	ray_content.wall_dir = W_NO_DIR;
	while (!checker && ray_content.dist < DISTANCE_RAY_VIEW)
	{
		ray_content.dist = ft_collide_while(&ray, &ray_content.wall_dir);
		if (ray.map_checker.x >= 0 && ray.map_checker.x < (int)data->map_size.x
			&& ray.map_checker.y >= 0 && ray.map_checker.y
			< (int)data->map_size.y)
		{
			if (data->map[ray.map_checker.y][ray.map_checker.x] == 1)
				checker = true;
		}
	}
	ray_content.wall_dir = ft_get_wall_dir(ray_content.wall_dir,
			ray.step_unit);
	ray_content.len.x = ray_content.dist * ray.norm.x;
	ray_content.len.y = ray_content.dist * ray.norm.y;
	ray_content.checker = checker;
	return (ray_content);
}

t_collide_data	ft_dda(t_data *data, t_fvec ray_start, float rotat)
{
	double			rotat_op;
	t_ray_data		ray;
	t_collide_data	ray_hit;

	rotat_op = rotat * PI180;
	ray.start.x = ray_start.x;
	ray.start.y = ray_start.y;
	ray.end.x = ray.start.x + cos(rotat_op);
	ray.end.y = ray.start.y + -sin(rotat_op);
	ray.norm = ft_vector_norm(ray.start, ray.end);
	ray.step_size.x = sqrt(1 + ft_pow(ray.norm.y / ray.norm.x, 2));
	ray.step_size.y = sqrt(1 + ft_pow(ray.norm.x / ray.norm.y, 2));
	ray.map_checker.x = ray.start.x;
	ray.map_checker.y = ray.start.y;
	ft_set_step(&ray);
	ray_hit = ft_collide(ray, data);
	ray_hit.len.x += ray.start.x;
	ray_hit.len.y += ray.start.y;
	return (ray_hit);
}
