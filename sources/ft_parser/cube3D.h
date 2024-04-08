/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2024/02/08 12:12:11 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>



# include "../MLX42/include/MLX42/MLX42.h"

# define LEFT 1
# define RIGHT 2
# define BOTH 3

# define WIDTH 1080
# define HEIGHT 1920

static const int	g_pxl = WIDTH * HEIGHT;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_map {
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	mlx_image_t	*north_image;
	mlx_image_t	*south_image;
	mlx_image_t	*west_image;
	mlx_image_t	*east_image;
	t_rgb		*floor;
	t_rgb		*celling;
	char		*map;
}	t_map;

typedef struct s_pov {
	double	position_x;
	double	position_y;
	int		angle;
	mlx_t	*mlx;
}	t_pov;

typedef struct s_data {
	t_map		*map;
	t_pov		*player;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_data;

int		check_extension(char *location);

t_map	*load_file(char *location);

t_pov	*load_player(t_map *map);

void	load_image(t_data *data, t_map *map);

int		is_texture(char *line, t_map *map);
void	set_texture(char *line, t_map *map);

int		is_floor(char *line, t_map *map);
void	set_floor(char *line, t_map *map);

int		is_celling(char *line, t_map *map);
void	set_celling(char *line, t_map *map);

int		is_map(t_map *map);
void	add_line_map(char *line, t_map *map);
char	get_cell(char *map, int x, int y);
int		is_leak(char *map, t_point pos, int buffer, int i);

void	map_error(t_map *map);
void	malloc_error(t_map *map);

void	validate_map(t_map *map);
void	validate_data(t_map *map);

int		flood(char *map);

int		empty(char c);

void	set_angle(t_pov *player, char angle);

void	purge_map(t_map *map);

int		get_rgba(t_rgb *rgb);

char	*ft_strdup_parser(char *s);

char	*ft_strjoin_parser(char *string_a, char *string_b, int mode);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_intset(void *s, int c, size_t n);

int		ft_atoi(const char *nptr);

#endif
