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
	int			return_code;
	t_map		*map;
	t_pov		*player;

	if (check_extension(path_file))
		return (FAIL);
	map = load_file(path_file);
	if (!map)
		return (FAIL);
	return_code = validate_map(map);
	if (return_code == MALLOC_FAIL)
		return (malloc_error(map));
	if (return_code == FAIL)
		return (map_error(map, "Invalid map"));
	validate_data(map);
	player = load_player(map);
	data->map_parser = map;
	data->player_parser = player;
	return (SUCCESS);
}
