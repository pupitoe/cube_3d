/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:11:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	get_rgba(t_rgb *rgb)
{
	int	result;

	result = 0;
	result |= rgb->red;
	result |= rgb->green << 8;
	result |= rgb->blue << 16;
	result |= 255 << 24;
	return (result);
}
