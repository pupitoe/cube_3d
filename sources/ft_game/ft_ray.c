/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:14:00 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/28 22:41:25 by tlassere         ###   ########.fr       */
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
