/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:35:16 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:04:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_data_clear(t_data *data)
{
	if (data)
	{
		ft_map_free(&data->map, data->map_size.y);
		purge_map(data->map);
		if (data->player_parser)
			free(data->player_parser);
		free(data);
	}
}

int	main(int argc, char **argv)
{
	int		status;
	t_data	*data;

	status = FAIL;
	data = NULL;
	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		if (data)
		{
			ft_bzero(data, sizeof(t_data));
			if (ft_parser(argv[1], data) == SUCCESS)
				status = ft_game_start(data);
			ft_data_clear(data);
		}
	}
	else
		ft_fprintf(STDERR, "Error\nBad arguments\n");
	return (status);
}
