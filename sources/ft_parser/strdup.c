/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 11:27:54 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

char	*ft_strdup_parser(char *s)
{
	char	*rptr;
	int		size;

	size = ft_strlen(s);
	rptr = malloc(size + 1);
	if (!rptr)
		return ((char *) 1);
	while (size >= 0)
	{
		*(rptr + size) = *(s + size);
		size--;
	}
	return (rptr);
}
