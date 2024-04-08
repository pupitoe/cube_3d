/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:19:54 by abareux           #+#    #+#             */
/*   Updated: 2024/01/08 09:23:06 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	check_extension(char *location)
{
	size_t	len;

	len = ft_strlen(location);
	if (len < 5)
		return (1);
	if (location[len - 1] != 'b')
		return (1);
	if (location[len - 2] != 'u')
		return (1);
	if (location[len - 3] != 'c')
		return (1);
	if (location[len - 4] != '.')
		return (1);
	return (0);
}
