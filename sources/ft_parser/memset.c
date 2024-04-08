/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:02:50 by abareux           #+#    #+#             */
/*   Updated: 2024/04/08 19:14:51 by tlassere         ###   ########.fr       */
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
