/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:32:26 by abareux           #+#    #+#             */
/*   Updated: 2024/04/15 17:09:52 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

static
int	is_player(char map)
{
	if (map == 'N' || map == 'S' || map == 'E' || map == 'W')
		return (1);
	return (0);
}

static
int	parse_line(char *line, t_map *map)
{
	if (is_texture(line, map))
		set_texture(line, map);
	else if (is_floor(line, map))
		set_floor(line, map);
	else if (is_celling(line, map))
		set_celling(line, map);
	else if (is_map(map))
		return (add_line_map(line, map));
	else
		return (FAIL);
	return (SUCCESS);
}

static
void	init_map(t_map *map)
{
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor = NULL;
	map->celling = NULL;
	map->map = NULL;
}

t_map	*load_file(char *location)
{
	int		fd;
	char	*line;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (malloc_error(map), NULL);
	init_map(map);
	fd = open(location, O_RDONLY);
	if (fd == -1)
		return (map_error(map, "Can't open file\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && parse_line(line, map) == FAIL)
			return (map_error(map, "Error while parsing\n"), close(fd),
				free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_pov	*load_player(t_map *map)
{
	int			iteration;
	static int	position_x;
	static int	position_y;
	t_pov		*player;

	iteration = 0;
	while (!is_player(map->map[iteration]) && map->map[iteration])
	{
		if (map->map[iteration] == '\n')
			position_x = 0;
		if (map->map[iteration++] == '\n')
			position_y++;
		else
			position_x++;
	}
	if (!is_player(map->map[iteration]) || check_duplicate(map->map, iteration))
		return (map_error(map, "No / Multiple player found\n"), NULL);
	player = malloc(sizeof(t_pov));
	if (!player)
		return (malloc_error(map), NULL);
	player->position_x = position_x;
	player->position_y = position_y;
	set_angle(player, map->map[iteration]);
	map->map[iteration] = '0';
	return (player);
}
