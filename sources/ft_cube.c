/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:35:16 by tlassere          #+#    #+#             */
/*   Updated: 2024/03/24 17:45:15 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	main(int argc, char **argv)
{
	int	status;

	status = SUCCESS;
	if (argc == 2)
	{
		ft_fprintf(STDERR, "file used is: %s\n", argv[1]);
	}
	else
	{
		ft_fprintf(STDERR, "Bad arguments\n");
		status = FAIL;
	}
	return (status);
}
