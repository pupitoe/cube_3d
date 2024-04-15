/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:22 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 15:11:19 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

char	*ft_strdup_parser(char *s)
{
	char	*rptr;
	size_t	size;

	size = ft_strlen(s) + 1;
	rptr = malloc(size * sizeof(char));
	if (!rptr)
		return ((char *) 1);
	while (size)
	{
		size--;
		*(rptr + size) = *(s + size);
	}
	return (rptr);
}
