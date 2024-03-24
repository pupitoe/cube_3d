/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:10:03 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/24 17:58:27 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include "ft_parser.h"

typedef struct s_vec
{
	size_t	x;
	size_t	y;
	int		rotat;
}t_vec;

typedef struct s_data
{
	t_vec	player;
	char	**map;
}t_data;

#endif
