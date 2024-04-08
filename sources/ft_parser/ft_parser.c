/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 12:15:55 by abareux          ###   ########.fr       */
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
