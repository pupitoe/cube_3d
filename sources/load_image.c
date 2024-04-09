/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 12:15:55 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	image_not_open(t_map *map)
{
	if (!map->north_image)
		return (1);
	if (!map->south_image)
		return (1);
	if (!map->west_image)
		return (1);
	if (!map->east_image)
		return (1);
	return (0);
}

void	mlx_delete_texture_protected(mlx_texture_t *texture)
{
	if (texture)
		mlx_delete_texture(texture);
}

int	open_image(t_map *map, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	int				loaded;

	loaded = 1;
	texture = mlx_load_png(map->north_texture);
	if (texture && loaded++)
		map->north_image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture_protected(texture);
	texture = mlx_load_png(map->south_texture);
	if (texture && loaded++)
		map->south_image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture_protected(texture);
	texture = mlx_load_png(map->west_texture);
	if (texture && loaded++)
		map->west_image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture_protected(texture);
	texture = mlx_load_png(map->east_texture);
	if (texture && loaded++)
		map->east_image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture_protected(texture);
	if (loaded != 5 || image_not_open(map))
		return (0);
	return (1);
}

/*
void	load_image(t_data *data, t_map *map)
{
	mlx_image_t	*img;

	img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	if (img && open_image(map, data->mlx))
	{
		ft_intset(img->pixels, get_rgba(map->celling), g_pxl / 2);
		ft_intset(img->pixels + (g_pxl * 2), get_rgba(map->floor), g_pxl / 2);
		mlx_image_to_window(data->mlx, img, 0, 0);
		data->img = img;
	}
	else
	{
		mlx_terminate(data->mlx);
		map_error(map);
	}
}
*/