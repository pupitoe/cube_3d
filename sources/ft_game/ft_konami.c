/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_konami.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:50:40 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/30 11:22:14 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_konami_check(keys_t *buffer, t_data *data)
{
	keys_t	konami_imput[KONAMI_SIZE];
	int		cmp;

	konami_imput[0] = MLX_KEY_UP;
	konami_imput[1] = MLX_KEY_UP;
	konami_imput[2] = MLX_KEY_DOWN;
	konami_imput[3] = MLX_KEY_DOWN;
	konami_imput[4] = MLX_KEY_LEFT;
	konami_imput[5] = MLX_KEY_RIGHT;
	konami_imput[6] = MLX_KEY_LEFT;
	konami_imput[7] = MLX_KEY_RIGHT;
	konami_imput[8] = MLX_KEY_B;
	konami_imput[9] = MLX_KEY_A;
	cmp = 0;
	while (cmp < KONAMI_SIZE && konami_imput[cmp] == buffer[cmp])
		cmp++;
	if (cmp == KONAMI_SIZE)
		data->konami_toggle = !(data->konami_toggle);
}

void	ft_konami(keys_t key, t_data *data)
{
	static int		size = 0;
	static keys_t	buffer[KONAMI_SIZE] = {0};

	buffer[size] = key;
	size++;
	if (size == KONAMI_SIZE)
	{
		ft_konami_check(buffer, data);
		while (size)
		{
			size--;
			buffer[size] = 0;
		}
	}
}
