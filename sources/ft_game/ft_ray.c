/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:14:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 16:58:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_put_ray(mlx_image_t *image, float corner, t_vec size)
{
	int	x;
	int	y;
	double	retc;
	double	rets;

	size.y /= 2;
	retc = cos(corner * PI180);
	rets = sin(corner * PI180);
	x = 0;
	y = 0;
	while (y < (int)size.y)
	{
		mlx_put_pixel(image, (int)lround(x * retc) + MAP_SIZE_OBJECT / 2, -(int)lround(y * rets) + MAP_SIZE_OBJECT / 2, PINK);
		printf("val x euh non Y: %d\n", (int)lround(y * sin(corner * (PI / 180))));
		printf("val X: %d\n", (int)lround(x * cos(corner * (PI / 180))));
		x++;
		y++;
	}
}