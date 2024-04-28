/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:54:58 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/17 18:43:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_put_block(mlx_image_t *img, t_vec pos, t_vec size, int color)
{
	int	x;

	while (size.y)
	{
		x = size.x;
		size.y--;
		while (x)
		{
			x--;
			mlx_put_pixel(img, x + pos.x, pos.y + size.y, color);
		}
	}
}
