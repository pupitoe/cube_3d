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

void	set_angle(t_pov *player, char angle)
{
	if (angle == 'N')
		player->angle = 0;
	if (angle == 'O')
		player->angle = 90;
	if (angle == 'S')
		player->angle = 180;
	if (angle == 'E')
		player->angle = 270;
}
