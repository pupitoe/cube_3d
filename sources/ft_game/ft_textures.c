/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:28:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/15 18:35:20 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_set_textures(t_data *data)
{
	(void)data;
	return (SUCCESS);
}

void	ft_delet_textures(t_data *data)
{
	if (data->texture.icon)
		mlx_delete_texture(data->texture.icon);
	data->texture.icon = NULL;
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
