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

int	get_rgba(t_rgb *rgb)
{
	int	result;

	result = 0;
	result |= rgb->red;
	result |= rgb->green << 8;
	result |= rgb->blue << 16;
	result |= 255 << 24;
	return (result);
}
