/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/12/07 12:53:38 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

char	*ft_strjoin_parser(char *string_a, char *string_b, int mode)
{
	size_t	cursor;
	size_t	cursor_string;
	char	*result;

	cursor = 0;
	cursor_string = 0;
	result = malloc(ft_strlen(string_a) + ft_strlen(string_b) + 1);
	if (!result)
		return (NULL);
	while (*(string_a + cursor_string))
		*(result + cursor++) = *(string_a + cursor_string++);
	cursor_string = 0;
	while (*(string_b + cursor_string))
		*(result + cursor++) = *(string_b + cursor_string++);
	*(result + cursor) = 0;
	if (mode == LEFT || mode == BOTH)
		free(string_a);
	if (mode == RIGHT || mode == BOTH)
		free(string_b);
	return (result);
}
