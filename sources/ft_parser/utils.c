/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 16:58:53 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	empty(char c)
{
	if (c == '0' || c == ' ' || c == 'D')
		return (1);
	return (0);
}

int	check_duplicate(char *map, int cursor)
{
	cursor++;
	while (map[cursor])
	{
		if (map[cursor] == 'N')
			return (1);
		if (map[cursor] == 'S')
			return (1);
		if (map[cursor] == 'W')
			return (1);
		if (map[cursor] == 'E')
			return (1);
		cursor++;
	}
	return (0);
}

int	intlen(char *str)
{
	int	len;

	len = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*(str + len)))
		len++;
	if (len == 0 && *(str - 1) == '0')
		return (1);
	return (len);
}
