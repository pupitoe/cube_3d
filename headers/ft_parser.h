/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:51:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/25 21:56:24 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define EOF_MAP 256

int		ft_parser(const char *path_file, t_data *data);
void	ft_map_free(int ***map, int heigth);
int		**ft_map_dup(int **map, t_vec size);

#endif
