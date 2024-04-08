/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   celling.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 09:06:16 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	is_celling(char *line, t_map *map)
{
	if (*(line + 0) == 'C' && *(line + 1) == ' ' && *(line + 2) != '\0')
		return (!map->celling);
	return (0);
}

void	set_celling(char *line, t_map *map)
{
	t_rgb	*result;

	result = malloc(sizeof(t_rgb));
	if (!result)
	{
		map->floor = (void *) 1;
		return ;
	}
	result->red = ft_atoi(line + 2);
	while (*line != ',' && *line)
		line++;
	result->green = ft_atoi(++line);
	while (*line != ',' && *line)
		line++;
	result->blue = ft_atoi(++line);
	map->celling = result;
}
