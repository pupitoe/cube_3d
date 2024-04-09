/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:02:50 by abareux           #+#    #+#             */
/*   Updated: 2024/01/08 10:16:46 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	*ft_intset(void *s, int c, size_t n)
{
	size_t	cursor;

	cursor = 0;
	while (cursor < n)
	{
		*((int *)s + cursor) = c;
		cursor++;
	}
	return (s);
}
