/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:45:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/25 21:55:09 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_parser(const char *path_file, t_data *data)
{
	int		status;
	
	int mapt[7][8] = 
	{
		{1,1,1,1,1,1,1,1,},
		{1,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,1,},
		{1,0,1,1,1,1,0,1,},
		{1,0,0,0,1,0,0,1,},
		{1,0,0,0,1,0,0,1,},
		{1,1,1,1,1,1,1,1,},
	};
	status = SUCCESS;
	if (path_file == NULL)
		status = FAIL;
	data->map_size.x = 8;
	data->map_size.y = 7;
	for (size_t i = 0; i < data->map_size.y; i++)
	{
		for (size_t j = 0; j < data->map_size.x; j++)
			data->map[i][j] = mapt[i][j];
	}
	return (status);
}
