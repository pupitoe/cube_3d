/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:54:58 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/29 14:42:57 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_put_white_block(t_data *data, t_vec pos)
{
	ft_put_block(data->img.map, pos,
		(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, WHITE | ALPHA_128);
}

void	ft_put_valid_block(t_data *data, t_vec block_position,
	int pos_y, int pos_x)
{
	if (data->map[data->player.y / SCALE + pos_y]
		[data->player.x / SCALE + pos_x] == 0)
		ft_put_white_block(data, block_position);
	else if (data->map[data->player.y / SCALE + pos_y]
		[data->player.x / SCALE + pos_x] == 3)
		ft_put_block(data->img.map, block_position,
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, GREEN | ALPHA_128);
	else if (data->map[data->player.y / SCALE + pos_y]
		[data->player.x / SCALE + pos_x] == 2)
		ft_put_block(data->img.map, block_position,
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, RED | ALPHA_128);
	else if (data->map[data->player.y / SCALE + pos_y]
		[data->player.x / SCALE + pos_x] == 1)
		ft_put_block(data->img.map, block_position,
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, BLACK | ALPHA_128);
	else
		ft_put_block(data->img.map, block_position,
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, WHITE | ALPHA_128);
}

void	choose_block(t_data *data, int pos_y, int pos_x)
{
	t_vec	block_position;

	block_position.y = data->middle.screen.y + pos_y * MAP_SIZE_OBJECT;
	block_position.x = data->middle.screen.x + pos_x * MAP_SIZE_OBJECT;
	block_position.rotat = 0;
	if (pos_y == -4 || pos_x == -4 || pos_y == 4 || pos_x == 4)
		ft_put_block(data->img.map, block_position,
			(t_vec){MAP_SIZE_OBJECT, MAP_SIZE_OBJECT, 0}, 0);
	else if ((long long ) data->player.y / SCALE + pos_y < 0)
		ft_put_white_block(data, block_position);
	else if ((long long ) data->player.x / SCALE + pos_x < 0)
		ft_put_white_block(data, block_position);
	else if (data->player.y / SCALE + pos_y >= data->map_size.y)
		ft_put_white_block(data, block_position);
	else if (data->player.x / SCALE + pos_x >= data->map_size.x)
		ft_put_white_block(data, block_position);
	else
		ft_put_valid_block(data, block_position, pos_y, pos_x);
}

void	ft_print_border(t_data *data)
{
	t_vec	block_position;

	block_position.y = data->middle.screen.y + -3 * MAP_SIZE_OBJECT;
	block_position.x = data->middle.screen.x + -3 * MAP_SIZE_OBJECT;
	block_position.rotat = 0;
	ft_put_block(data->img.map, block_position,
		(t_vec){5, MAP_SIZE_OBJECT * 7, 0}, BLACK | ALPHA_192);
	ft_put_block(data->img.map, block_position,
		(t_vec){MAP_SIZE_OBJECT * 7, 5, 0}, BLACK | ALPHA_192);
	block_position.x = data->middle.screen.x + 4 * MAP_SIZE_OBJECT;
	ft_put_block(data->img.map, block_position,
		(t_vec){5, MAP_SIZE_OBJECT * 7, 0}, BLACK | ALPHA_192);
	block_position.x = data->middle.screen.x + -3 * MAP_SIZE_OBJECT;
	block_position.y = data->middle.screen.y + 4 * MAP_SIZE_OBJECT;
	ft_put_block(data->img.map, block_position,
		(t_vec){MAP_SIZE_OBJECT * 7 + 5, 5, 0}, BLACK | ALPHA_192);
}

void	ft_print_map(t_data *data)
{
	int	pos_y;
	int	pos_x;

	data->img.player->instances[0].x = data->middle.screen.x + 19;
	data->img.player->instances[0].y = data->middle.screen.y + 19;
	data->img.player->instances[0].enabled = true;
	pos_y = -4;
	while (pos_y < 5)
	{
		pos_x = -4;
		while (pos_x < 5)
		{
			choose_block(data, pos_y, pos_x);
			pos_x++;
		}
		pos_y++;
	}
	ft_print_border(data);
}
