/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:14:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/27 00:13:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

# define PI 3.14159265359

void	ft_put_ray(mlx_image_t *image, float corner, t_vec size)
{
	int	x;
	int	y;

	(void)corner;

	size.y /= 2;
	x = 0;
	y = 0;
	printf("ii\n");
	while (y < (int)size.y)
	{
		mlx_put_pixel(image, (int)lround(x * cos(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2 - 1, -(int)lround(y * sin(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2, PINK);
		mlx_put_pixel(image, (int)lround(x * cos(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2, -(int)lround(y * sin(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2, PINK);
		mlx_put_pixel(image, (int)lround(x * cos(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2 + 1, -(int)lround(y * sin(corner * (PI / 180))) + MAP_SIZE_OBJECT / 2, PINK);
		printf("val x euh non Y: %d\n", (int)lround(y * sin(corner * (PI / 180))));
		printf("val X: %d\n", (int)lround(x * cos(corner * (PI / 180))));
		x++;
		y++;
	}
	(void)image;	
}