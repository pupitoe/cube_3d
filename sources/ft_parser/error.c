/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:07:37 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	map_error(t_map *map)
{
	if (map->north_texture > (char *) 1)
		free(map->north_texture);
	if (map->south_texture > (char *) 1)
		free(map->south_texture);
	if (map->west_texture > (char *) 1)
		free(map->west_texture);
	if (map->east_texture > (char *) 1)
		free(map->east_texture);
	if (map->floor > (t_rgb *) 1)
		free(map->floor);
	if (map->celling > (t_rgb *) 1)
		free(map->celling);
	if (map->map > (char *) 1)
		free(map->map);
	write(1, "Error\n", 6);
	exit(1);
}

void	malloc_error(t_map *map)
{
	if (map)
	{
		free(map->north_texture);
		free(map->south_texture);
		free(map->west_texture);
		free(map->east_texture);
		free(map->floor);
		free(map->celling);
		free(map->map);
	}
	write(1, "Error\n", 6);
	write(1, "a malloc f*** up\n", 18);
	exit(1);
}
