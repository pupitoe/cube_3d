/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:22 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:12:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

char	*ft_strdup_parser(char *s)
{
	char	*rptr;
	int		size;

	size = ft_strlen(s);
	rptr = malloc(size + 1);
	if (!rptr)
		return ((char *) 1);
	while (size >= 0)
	{
		*(rptr + size) = *(s + size);
		size--;
	}
	return (rptr);
}
