/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:11:37 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/28 17:54:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	ft_set_data(t_data *data, t_pov *player, t_map *map)
{
	int	middle_player;

	middle_player = SCALE / 2 - PLAYER_SIZE / 2;
	data->map_parser = map;
	data->player.x = (player->position_x * SCALE) + middle_player;
	data->player.y = (player->position_y * SCALE) + middle_player;
	data->player.rotat = player->angle;
	data->texture.floor_rgba = ft_get_rgba(map->floor->red,
			map->floor->green, map->floor->blue, 255);
	data->texture.ceiling_rgba = ft_get_rgba(map->celling->red,
			map->celling->green, map->celling->blue, 255);
}

int	ft_parser(char *path_file, t_data *data)
{
	int			return_code;
	t_map		*map;
	t_pov		*player;

	if (check_extension(path_file))
		return (ft_putstr_fd("Error\nWrong file extension\n", 1), FAIL);
	map = load_file(path_file);
	if (!map)
		return (FAIL);
	return_code = validate_map(map);
	if (return_code == MALLOC_FAIL)
		return (malloc_error(map));
	if (return_code == FAIL)
		return (map_error(map, "Invalid map\n"));
	if (validate_data(map) == FAIL)
		return (FAIL);
	player = load_player(map);
	if (!player)
		return (MALLOC_FAIL);
	ft_set_data(data, player, map);
	free(player);
	return (convert(data));
}
