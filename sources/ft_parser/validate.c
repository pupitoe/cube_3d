/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/01/08 10:06:06 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	validate_map(t_map *map)
{
	char	*buffer;

	buffer = ft_strdup(map->map);
	if (!buffer)
		malloc_error(map);
	if (flood(buffer))
		map_error(map);
}

void	validate_data(t_map *map)
{
	if (map->celling->blue > 255)
		map_error(map);
	if (map->celling->red > 255)
		map_error(map);
	if (map->celling->green > 255)
		map_error(map);
	if (map->celling->blue < 0)
		map_error(map);
	if (map->celling->red < 0)
		map_error(map);
	if (map->celling->green < 0)
		map_error(map);
}
