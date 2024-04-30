# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:29:01 by tlassere          #+#    #+#              #
#    Updated: 2024/04/30 11:58:56 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			::= cub3D
T_FT_PARSER		::=	ft_map_free ft_parser celling check_extension error flood \
					floor load map purge set_angle strdup_parser \
					strjoin_parser texture utils validate converter
FT_PARSER		::= $(foreach buffer, $(T_FT_PARSER), ft_parser/$(buffer))
T_FT_GAME		::= ft_game	ft_map ft_move ft_move_hook ft_images \
					ft_collision ft_dda ft_math ft_map_wall ft_game_print \
					ft_print ft_textures ft_wall_texture ft_interact \
					ft_dda_call ft_put_block ft_mouse ft_game_hook \
					ft_print_hud ft_konami
FT_GAME			::= $(foreach buffer, $(T_FT_GAME), ft_game/$(buffer))
SOURCES_CONTENT ::= ft_cube $(FT_PARSER) $(FT_GAME)
OBJS_FOLDER		::= objects
SRC_FOLDER		::= sources
SOURCES			::= $(foreach buffer, $(SOURCES_CONTENT), \
						$(SRC_FOLDER)/$(buffer).c)
OBJECTS			::= $(foreach buffer, $(SOURCES_CONTENT), \
						$(OBJS_FOLDER)/$(buffer).o)
HEADER			::= headers
T_HEADER_FILES	::= ft_cub ft_data ft_game ft_move ft_parser ft_math ft_color \
					ft_dda ft_data_wall ft_print ft_vec
HEADER_FILES	::= $(foreach buffer, $(T_HEADER_FILES), $(HEADER)/$(buffer).h)
LIBMLX			::= ./MLX42
LIBFT_DIR		::= libft
LIBFT			::= $(LIBFT_DIR)/libft.a
CFLAGS			::= -Wall -Wextra -Werror -g3
MLX_C			::= $(LIBMLX)/build/libmlx42.a
LDFLAGS			::= $(MLX_C) -lm -ldl -lglfw -pthread
CC				::= cc

$(OBJS_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT_DIR) -I$(LIBMLX)/include -c -o $@ $<

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_C) $(OBJECTS) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) $(LIBFT) -o $(NAME)

sclean:
	rm -rf $(OBJECTS) $(OBJS_FOLDER)

clean: sclean
	make -C libft clean
	rm -rf $(LIBMLX)/build

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

rec: sclean all

$(MLX_C):
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	make -C libft

re: fclean all

.PHONY: all clean fclean re
