/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_wall.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:49:51 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/12 15:03:13 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_WALL_H
# define FT_DATA_WALL_H

typedef struct s_data_wall
{
	int				height;
	int				width;
	int				start;
	t_collide_data	collide;
}t_data_wall;

#endif