/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:45:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/26 13:48:42 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_parser(const char *path_file, t_data *data)
{
	int		status;
	
	int mapt[9][18] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	};
	status = SUCCESS;
	if (path_file == NULL)
		status = FAIL;
	data->map_size.x = 18;
	data->map_size.y = 9;
	data->player.x = 4;
	data->player.y = 4;
	data->map = malloc(sizeof(int *) * data->map_size.y);
	for (size_t i = 0; i < data->map_size.y; i++)
	{
		data->map[i] = malloc(sizeof(int *) * data->map_size.x);
		for (size_t j = 0; j < data->map_size.x; j++)
			data->map[i][j] = mapt[i][j];
	}
	return (status);
}
