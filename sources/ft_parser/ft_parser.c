/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:37 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:11:39 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_parser(char *path_file, t_data *data)
{
	t_map		*map;
	t_pov		*player;

	if (check_extension(path_file))
		return (FAIL);
	map = load_file(path_file);
	validate_map(map);
	validate_data(map);
	player = load_player(map);
	data->map_parser = map;
	data->player_parser = player;
	return (SUCCESS);
}
