/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:28:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/25 15:49:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_set_textures(t_data *data)
{
	int	status;

	status = FAIL;
	data->texture.north = mlx_load_png(data->map_parser->north_texture);
	data->texture.south = mlx_load_png(data->map_parser->south_texture);
	data->texture.west = mlx_load_png(data->map_parser->west_texture);
	data->texture.east = mlx_load_png(data->map_parser->east_texture);
	data->texture.door = mlx_load_png("./asset/door.png");
	if (data->texture.north && data->texture.south
		&& data->texture.west && data->texture.east
		&& data->texture.door)
		status = SUCCESS;
	return (status);
}

void	ft_delet_textures(t_data *data)
{
	if (data->texture.icon)
		mlx_delete_texture(data->texture.icon);
	if (data->texture.north)
		mlx_delete_texture(data->texture.north);
	if (data->texture.east)
		mlx_delete_texture(data->texture.east);
	if (data->texture.south)
		mlx_delete_texture(data->texture.south);
	if (data->texture.west)
		mlx_delete_texture(data->texture.west);
	if (data->texture.door)
		mlx_delete_texture(data->texture.door);
	data->texture.icon = NULL;
	data->texture.north = NULL;
	data->texture.east = NULL;
	data->texture.south = NULL;
	data->texture.west = NULL;
	data->texture.door = NULL;
}

int	ft_set_icon(t_data *data)
{
	int	status;

	status = FAIL;
	data->texture.icon = mlx_load_png("./asset/debug.png");
	if (data->texture.icon)
	{
		status = SUCCESS;
		mlx_set_icon(data->mlx, data->texture.icon);
	}
	return (status);
}
