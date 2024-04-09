/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:51:44 by tlassere          #+#    #+#             */
/*   Updated: 2024/04/08 20:16:41 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define LEFT 1
# define RIGHT 2
# define BOTH 3

int		ft_parser(char *path_file, t_data *data);
void	ft_map_free(int ***map, int heigth);
int		**ft_map_dup(int **map, t_vec size);

int		check_extension(char *location);

t_map	*load_file(char *location);

t_pov	*load_player(t_map *map);

int		is_texture(char *line, t_map *map);
void	set_texture(char *line, t_map *map);

int		is_floor(char *line, t_map *map);
void	set_floor(char *line, t_map *map);

int		is_celling(char *line, t_map *map);
void	set_celling(char *line, t_map *map);

int		is_map(t_map *map);
int		add_line_map(char *line, t_map *map);
char	get_cell(char *map, int x, int y);
int		is_leak(char *map, t_point pos, int buffer, int i);

int		map_error(t_map *map, char *reason);
int		malloc_error(t_map *map);

int		validate_map(t_map *map);
int		validate_data(t_map *map);

int		flood(char *map);

int		empty(char c);

void	set_angle(t_pov *player, char angle);

void	purge_map(t_map *map);

int		get_rgba(t_rgb *rgb);

char	*ft_strdup_parser(char *s);

char	*ft_strjoin_parser(char *string_a, char *string_b, int mode);

void	*ft_intset(void *s, int c, size_t n);

int		ft_atoi(const char *nptr);

#endif
