/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:45:32 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/24 18:53:18 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_parser(const char *path_file, t_data *data)
{
	int	status;

	status = SUCCESS;
	(void)data;
	if (path_file == NULL)
		status = FAIL;
	return (status);
}
